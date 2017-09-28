//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include <System.StrUtils.hpp>
#include <System.IOUtils.hpp>
#include <ToolsApi.hpp>
#pragma hdrstop

#include "GTESTPluginDockableFrame.h"
#include "PluginException.h"
#include "Utility.h"
#include "Command.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

const String TGTESTFrame::DEBUGGER_ENV_VARS_STRING = "Debugger_EnvVars";
const String TGTESTFrame::DEBUGGER_ENV_BLOCK_VARIABLE_NAME = "GTESTProject";
const String TGTESTFrame::RESULT_FILE = "testResults.xml";
const System::Uitypes::TColor TGTESTFrame::RED = System::Uitypes::TColor(0x00324BCC);
const System::Uitypes::TColor TGTESTFrame::GREEN = System::Uitypes::TColor(0x0081A84A);

TGTESTFrame *GTESTFrame;
//---------------------------------------------------------------------------
__fastcall TGTESTFrame::TGTESTFrame(TComponent* Owner)
  : TFrame(Owner)
{
  HeadPanel->ParentBackground = false;
  HeadPanel->ParentColor = false;
  GTESTTreeView->ReadOnly = true;
}
//---------------------------------------------------------------------------

void __fastcall TGTESTFrame::GTESTTreeViewCustomDrawItem(TCustomTreeView *Sender, TTreeNode *Node,
          TCustomDrawState State, bool &DefaultDraw)
{
  if(Node->Data)
  {
    GTestNodeData* data = static_cast<GTestNodeData*>(Node->Data);
    if(data->getTestStatus() == TestStatus::FAILURE)
      Sender->Canvas->Font->Color = RED;
    else if(data->getTestStatus() == TestStatus::SUCCESS)
      Sender->Canvas->Font->Color = GREEN;
    else
      throw PluginException("test status not supported");
  }
}
//---------------------------------------------------------------------------

void __fastcall TGTESTFrame::GTESTTreeViewDblClick(TObject *Sender)
{
  if(!GTESTTreeView->Selected)
    return;

  TTreeNode* node = GTESTTreeView->Selected;
  GTestNodeData* nodeData = static_cast<GTestNodeData*>(node->Data);

  if(nodeData->getNodeType() != NodeType::FAILURE_SOURCE)
    return;

  navigateToFailureLine(node);
}

void __fastcall TGTESTFrame::navigateToFailureLine(TTreeNode* failureNode)
{
  _di_IOTAActionServices actionServices;
  _di_IOTAEditorServices editorServices;

  TStringDynArray path = SplitString(failureNode->Text, ':');

  if(!FileExists(path[0]+":"+path[1]))
  {
    Debug.Debug("The file where the failure occured does not exist: " + path[0] + ":" + path[1]);
    return;
  }

  if(!BorlandIDEServices->Supports(actionServices))
  {
    Debug.Debug("ActionServices is not supported by the current IDE.");
    return;
  }

  actionServices->OpenFile(path[0]+":"+path[1]);

  if(!BorlandIDEServices->Supports(editorServices))
  {
    Debug.Debug("EditorServices is not supported by the current IDE.");
    return;
  }

  _di_IOTAEditView editView = editorServices->TopView;

  if(editView == nullptr)
  {
    Debug.Debug("No TopView (TopView should gain access to the active editor)");
    return;
  }

  int falseLineNumber = StrToInt(path[2]);
  editView->Buffer->EditPosition->Move(falseLineNumber, 1);
  editView->Center(falseLineNumber, 1);
}

void __fastcall TGTESTFrame::refreshGui(String resultFilePath)
{
  if(!FileExists(resultFilePath))
  {
    throw PluginException(resultFilePath + " does not exist. " +
                          "That means the program was not terminated correctly. " +
                          "So the file could not be created.");
  }

  _di_IXMLtestsuites testSuites = Loadtestsuites(resultFilePath);

  if(!testSuites)
    throw PluginException(resultFilePath + " was not found.");

  TTreeNode* testSuitesNode = createTestSuitesNode(testSuites);
  initTestSuitesNode(testSuitesNode, testSuites);
}

TTreeNode* __fastcall TGTESTFrame::createTestSuitesNode(_di_IXMLtestsuites testSuites)
{
  return GTESTTreeView->Items->Add(nullptr, testSuites->Get_name());
}

void __fastcall TGTESTFrame::initTestSuitesNode(TTreeNode* testSuitesNode, _di_IXMLtestsuites testSuites)
{
  GTestNodeData* testSuitesData = new GTestNodeData();
  testSuitesNode->Data = testSuitesData;

  TestsLabel->Caption = "Tests: " + IntToStr(testSuites->Get_tests());
  FailureLabel->Caption = "Failures: " + IntToStr(testSuites->Get_failures());
  ErrorsLabel->Caption = "Errors: " + IntToStr(testSuites->Get_errors());
  DisabledLabel->Caption = "Disabled: " + IntToStr(testSuites->Get_disabled());
  DurationLabel->Caption = "Time: " + testSuites->Get_time();
  GetParentForm(this)->Caption = "GTEST - " + testSuites->Get_timestamp();

  for(int testSuiteIndex = 0; testSuiteIndex < testSuites->GetCount(); ++testSuiteIndex)
  {
    _di_IXMLTestSuiteType testSuite = testSuites->Get_testsuite(testSuiteIndex);
    TTreeNode* testSuiteNode = createTestSuiteNode(testSuitesNode, testSuite);
    initTestSuiteNode(testSuiteNode, testSuite);
  }

  if(testSuites->Get_failures() > 0)
  {
    testSuitesNode->Expanded = true;
    HeadPanel->Color = RED;
    testSuitesData->setTestStatus(TestStatus::FAILURE);
  }
  else
  {
    HeadPanel->Color = GREEN;
    testSuitesData->setTestStatus(TestStatus::SUCCESS);
  }
}

TTreeNode* __fastcall TGTESTFrame::createTestSuiteNode(TTreeNode* testSuitesNode, _di_IXMLTestSuiteType testSuite)
{
  String outputString = testSuite->Get_name() + " | Tests: " + IntToStr(testSuite->Get_tests()) +
                        " | Failures: " + IntToStr(testSuite->Get_failures()) + " | Errors: " +
                        IntToStr(testSuite->Get_errors()) + " | Disabled: " + IntToStr(testSuite->Get_disabled()) +
                        " | Time: " + testSuite->Get_time() + " |";
  return GTESTTreeView->Items->AddChild(testSuitesNode, outputString);
}

void __fastcall TGTESTFrame::initTestSuiteNode(TTreeNode* testSuiteNode, _di_IXMLTestSuiteType testSuite)
{
  GTestNodeData* testSuiteData = new GTestNodeData();
  testSuiteNode->Data = testSuiteData;

  for(int testCaseIndex = 0; testCaseIndex < testSuite->GetCount(); ++testCaseIndex)
  {
    _di_IXMLTestCaseType testCase = testSuite->Get_testcase(testCaseIndex);
    TTreeNode* testCaseNode = createTestCaseNode(testSuiteNode, testCase);
    initTestCaseNode(testCaseNode, testCase);
  }

  if(testSuite->Get_failures() > 0)
  {
    testSuiteNode->Expanded = true;
    testSuiteData->setTestStatus(TestStatus::FAILURE);
  }
  else
  {
    testSuiteData->setTestStatus(TestStatus::SUCCESS);
  }
}

TTreeNode* __fastcall TGTESTFrame::createTestCaseNode(TTreeNode* testSuiteNode, _di_IXMLTestCaseType testCase)
{
  String outputString = testCase->Get_name() + " | Failures: " +
                        IntToStr(testCase->GetCount()) + " | Time: " +
                        testCase->Get_time() + " |";
  return GTESTTreeView->Items->AddChild(testSuiteNode, outputString);
}

void __fastcall TGTESTFrame::initTestCaseNode(TTreeNode* testCaseNode, _di_IXMLTestCaseType testCase)
{
  GTestNodeData* testCaseData = new GTestNodeData();
  testCaseNode->Data = testCaseData;

  if(testCase->GetCount() == 0)
  {
    testCaseData->setTestStatus(TestStatus::SUCCESS);
  }
  else
  {
    testCaseData->setTestStatus(TestStatus::FAILURE);
    addFailureNodesToTestCaseNode(testCaseNode, testCase);
    testCaseNode->Expanded = true;
  }
}

void __fastcall TGTESTFrame::addFailureNodesToTestCaseNode(TTreeNode* testCaseNode, _di_IXMLTestCaseType testCase)
{
  for(int failureIndex = 0; failureIndex < testCase->GetCount(); ++failureIndex)
  {
    String failureString = testCase->Get_failure(failureIndex)->Get_message();
    TStringDynArray failureStringLines = SplitString(failureString, "\n");
    bool firstFailureLine = true;

    for(auto failureStringLine : failureStringLines)
    {
      failureStringLine = failureStringLine.Trim();
      TTreeNode* failureNode = GTESTTreeView->Items->AddChild(testCaseNode, failureStringLine);
      GTestNodeData* failureData = new GTestNodeData();
      failureNode->Data = failureData;
      failureData->setTestStatus(TestStatus::FAILURE);

      if(firstFailureLine)
      {
        failureData->setNodeType(NodeType::FAILURE_SOURCE);
        firstFailureLine = false;
      }
    }
  }
}

void __fastcall TGTESTFrame::internalRun()
{
  clearResults();
  String testProjectPath = getTestProjectPathFromActiveProjectsEnvVariables();
	_di_IOTAProject testProject = getProjectFromMainProjectGroup(testProjectPath);
  buildProject(testProject);
  String resultFilePath = runTestOnProject(testProject);
	refreshGui(resultFilePath);
}

void __fastcall TGTESTFrame::clearResults()
{
  deleteTreeDataObjects();
  GTESTTreeView->Items->Clear();

  TestsLabel->Caption = "Tests:";
  FailureLabel->Caption = "Failures:";
  ErrorsLabel->Caption = "Errors:";
  DisabledLabel->Caption = "Disabled:";
  DurationLabel->Caption = "Time:";
  HeadPanel->Color = clBtnFace;
}

void __fastcall TGTESTFrame::deleteTreeDataObjects()
{
  TTreeNode* node = GTESTTreeView->Items->GetFirstNode();

  while(node)
  {
    if(node->Data)
    {
      GTestNodeData* data = static_cast<GTestNodeData*>(node->Data);
      delete data;
      node->Data = nullptr;
    }
    node = node->GetNext();
  }
}

String __fastcall TGTESTFrame::runTestOnProject(_di_IOTAProject testProject)
{
  _di_IOTAProjectOptions projectOptions = testProject->GetProjectOptions();

  String finalOutputDir = ExtractFilePath(testProject->GetFileName()) +
                          projectOptions->GetOptionValue("FinalOutputDir").As<String>();

  if(finalOutputDir.Length() > 0 && finalOutputDir[finalOutputDir.Length()-1] != '\\')
    finalOutputDir += "\\";

	String sanitizedProjectName = projectOptions->GetOptionValue("SanitizedProjectName").As<String>();
  String resultFilePath = finalOutputDir +
                          ReplaceStr(ExtractFileName(testProject->GetFileName()), ".cbproj", "")
                          + "_" + RESULT_FILE;

  String commandString = finalOutputDir + sanitizedProjectName + ".exe";
  String xmlPrameter = "--gtest_output=xml:\"" + resultFilePath + "\"";

  if(FileExists(resultFilePath))
    DeleteFile(resultFilePath);

  Command command;
  command.setCommandString(Utility::convertUnicodeStrToStdStr(commandString));
  command.addParameter(Utility::convertUnicodeStrToStdStr(xmlPrameter));
  command.execute();

	return resultFilePath;
}

void __fastcall TGTESTFrame::buildProject(_di_IOTAProject project)
{
  _di_IOTAProjectBuilder projectBuilder = project->GetProjectBuilder();

	if(!projectBuilder->BuildProject(cmOTAMake, true, true))
    throw PluginException("The following project could not be build: " + project->GetFileName());
}

_di_IOTAProject __fastcall TGTESTFrame::getProjectFromMainProjectGroup(String projectPath)
{
  _di_IOTAProject project = nullptr;
  _di_IOTAProjectGroup mainProjectGroup;
  _di_IOTAModuleServices moduleServices;

	if(!BorlandIDEServices->Supports(moduleServices))
    throw PluginException("IDE does not support module services");

  mainProjectGroup = moduleServices->GetMainProjectGroup();

  if(mainProjectGroup == nullptr)
    throw PluginException("No main project group");

	for(int i = 0; i < mainProjectGroup->GetProjectCount(); ++i)
	{
		project = mainProjectGroup->GetProject(i);
		if(project->GetFileName().Compare(projectPath) == 0)
      break;
		project = nullptr;
	}

	if(project == nullptr)
    throw PluginException("The following project could not be found in the main project group " + projectPath);

  return project;
}

String __fastcall TGTESTFrame::getTestProjectPathFromActiveProjectsEnvVariables()
{
  String result = "";
  _di_IOTAProject activeProject;
  _di_IOTAProjectOptions projectOptions;

  activeProject = GetActiveProject();
  if(!activeProject)
    throw PluginException("No project open");

  projectOptions = activeProject->GetProjectOptions();
  Variant debuggerEnvVariables = projectOptions->GetOptionValue(DEBUGGER_ENV_VARS_STRING);
  String debuggerEnvVariablesStr = debuggerEnvVariables.As<String>();

  TStringDynArray debuggerEnvVariablesStrParts = SplitString(debuggerEnvVariablesStr, ';');

  if(debuggerEnvVariablesStrParts.Length == 0)
    throw PluginException("The active project has no debugger environment variables");

  for(auto debuggerEnvVariableStr : debuggerEnvVariablesStrParts)
  {
    TStringDynArray envVariableParts = SplitString(debuggerEnvVariableStr, '=');

    if(envVariableParts.Length != 2)
      continue;

    if(envVariableParts[0].Compare(DEBUGGER_ENV_BLOCK_VARIABLE_NAME) == 0)
    {
      result = envVariableParts[1];
      break;
    }
  }

  if(result.IsEmpty())
  {
    throw PluginException("The active project has no environment variable with the name " +
                          DEBUGGER_ENV_BLOCK_VARIABLE_NAME);
  }

  if(result.Length() < 3 || result.SubString(0, 3).Compare("C:\\") != 0)
  {
    String currentPath = GetCurrentDir();
    try
    {
      SetCurrentDir(ExtractFilePath(activeProject->GetFileName()));
      result = TPath::GetFullPath(result);
      SetCurrentDir(currentPath);
    }
    catch(...)
    {
      SetCurrentDir(currentPath);
      throw PluginException(String("There occured an error when trying to generate ") +
                            "an absolute path with the absolute path " +
                            ExtractFilePath(activeProject->GetFileName()) +
                            " and the relative path " +
                            result);
    }
  }

  return result;
}

void __fastcall TGTESTFrame::Run()
{
  try
  {
    internalRun();
  }
  catch(PluginException& exception)
  {
    Application->MessageBox(exception.getMessage().c_str(), L"Error", MB_OKCANCEL);
  }
}

void __fastcall TGTESTFrame::StartButtonClick(TObject *Sender)
{
  Run();
}
