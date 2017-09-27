//---------------------------------------------------------------------------

#ifndef DockableFrameH
#define DockableFrameH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include "GTESTPluginDebugNotifier.h"
#include "gtest.h"

//---------------------------------------------------------------------------
class TGTESTFrame : public TFrame
{
__published:	// Von der IDE verwaltete Komponenten
  TPanel *HeadPanel;
  TPanel *BodyPanel;
  TButton *StartButton;
  TTreeView *GTESTTreeView;
  TLabel *TestsLabel;
  TLabel *FailureLabel;
  TLabel *DurationLabel;
  TLabel *ErrorsLabel;
  TLabel *DisabledLabel;
  void __fastcall GTESTTreeViewCustomDrawItem(TCustomTreeView *Sender, TTreeNode *Node,
          TCustomDrawState State, bool &DefaultDraw);
  void __fastcall GTESTTreeViewDblClick(TObject *Sender);
  void __fastcall StartButtonClick(TObject *Sender);
private:	// Benutzer-Deklarationen
  enum class TestStatus { SUCCESS, FAILURE };
  enum class NodeType {NORMAL, FAILURE_SOURCE};

  class GTestNodeData
  {
  private:
    TestStatus m_testStatus;
    NodeType m_nodeType;
  public:
    __fastcall GTestNodeData() : m_nodeType(NodeType::NORMAL) {}
    TestStatus __fastcall getTestStatus() const { return m_testStatus; }
    void __fastcall setTestStatus(const TestStatus& testStatus) { m_testStatus = testStatus; }

    NodeType __fastcall getNodeType() const { return m_nodeType; }
    void __fastcall setNodeType(const NodeType& nodeType) { m_nodeType = nodeType; }
  };

  const static String DEBUGGER_ENV_VARS_STRING;
  const static String DEBUGGER_ENV_BLOCK_VARIABLE_NAME;
  const static String RESULT_FILE;
  const static System::Uitypes::TColor RED;
  const static System::Uitypes::TColor GREEN;

  GTESTPluginDebugNotifier Debug;

  String __fastcall getTestProjectPathFromActiveProjectsEnvVariables();
  _di_IOTAProject __fastcall getProjectFromMainProjectGroup(String projectPath);
  void __fastcall buildProject(_di_IOTAProject project);
  void __fastcall refreshGui(String resultFilePath);
  String __fastcall runTestOnProject(_di_IOTAProject testProject);
  void __fastcall internalRun();
  void __fastcall clearResults();
  void __fastcall deleteTreeDataObjects();

  TTreeNode* __fastcall createTestSuitesNode(_di_IXMLtestsuites testSuites);
  TTreeNode* __fastcall createTestSuiteNode(TTreeNode* testSuitesNode, _di_IXMLTestSuiteType testSuite);
  TTreeNode* __fastcall createTestCaseNode(TTreeNode* testSuiteNode, _di_IXMLTestCaseType testCase);

  void __fastcall initTestSuitesNode(TTreeNode* testSuitesNode, _di_IXMLtestsuites testsuites);
  void __fastcall initTestSuiteNode(TTreeNode* testSuiteNode, _di_IXMLTestSuiteType testSuite);
  void __fastcall initTestCaseNode(TTreeNode* testCaseNode, _di_IXMLTestCaseType testCase);

  void __fastcall addFailureNodesToTestCaseNode(TTreeNode* testCaseNode, _di_IXMLTestCaseType testCase);

  void __fastcall navigateToFailureLine(TTreeNode* failureNode);
public:		// Benutzer-Deklarationen
  __fastcall TGTESTFrame(TComponent* Owner);
  void __fastcall Run();
};
//---------------------------------------------------------------------------
extern PACKAGE TGTESTFrame *GTESTFrame;
//---------------------------------------------------------------------------
#endif
