#pragma hdrstop
#include <GTESTPluginMainWizard.h>
#include <Dialogs.hpp>
#include <GTESTPluginPkgDLLInit.h>
#include <GTESTPluginSplashScreen.h>
#include <GTESTPluginAboutBoxPlugin.h>
#include "GTESTPluginMacros.h"
#include "GTESTPluginDockableForm.h"
#include <GTESTPluginEditorNotifier.h>
#include "GTESTPluginConstants.h"
#include <Vcl.Menus.hpp>
#include <Vcl.Consts.hpp>
#pragma package(smart_init)

/* TGTESTPluginWizard Implementation */

__fastcall TGTESTPluginWizard::TGTESTPluginWizard(String strObjectName) :
  TDGHNotifierObject(strObjectName) {
  //: @note Not required now
  //: #ifndef DLL
  AddSplashScreen();
  //: #endif
  FAboutBoxPlugin = AddAboutBoxPlugin();
  FIDENotifier = AddIDENotifier();
  _di_INTAServices INTAServices;

  if (BorlandIDEServices->Supports(INTAServices))
  {
    GTESTMenuItem = new TMenuItem(nullptr);
    GTESTMenuItem->Name = "ViewsGTESTPlugin";
    GTESTMenuItem->Caption = strGTestName;
    INTAServices->AddActionMenu("ToolsMenu", NULL, GTESTMenuItem, false /*InsertAfter*/, true /*InsertAsChild*/);

    TMenuItem* GTESTShowMenuItem = new TMenuItem(GTESTMenuItem);
    GTESTShowMenuItem->Caption = "Show";
    GTESTShowMenuItem->OnClick = GTESTShow;
    INTAServices->AddActionMenu("ViewsGTESTPlugin", NULL, GTESTShowMenuItem, false /*InsertAfter*/, true /*InsertAsChild*/);

    TMenuItem* GTESTRunMenuItem = new TMenuItem(GTESTMenuItem);
    GTESTRunMenuItem->Caption = strRunName;
    GTESTRunMenuItem->OnClick = GTESTRun;
    GTESTRunMenuItem->ShortCut = TextToShortCut(Vcl_Consts_SmkcCtrl+Vcl_Consts_SmkcAlt+"F9");
    INTAServices->AddActionMenu("ViewsGTESTPlugin", NULL, GTESTRunMenuItem, false /*InsertAfter*/, true /*InsertAsChild*/);
  }
  TGTESTForm::CreateDockableModuleExplorer();
}

__fastcall TGTESTPluginWizard::~TGTESTPluginWizard()
{
  RemoveAboutBoxPlugin(FAboutBoxPlugin);
  RemoveIDENotifier(FIDENotifier);
  TGTESTForm::RemoveDockableModuleExplorer();
  delete GTESTMenuItem;
}

ULONG __stdcall TGTESTPluginWizard::AddRef() {
  return inherited::AddRef();
}

ULONG __stdcall TGTESTPluginWizard::Release() {
  return inherited::Release();
}

HRESULT __stdcall TGTESTPluginWizard::QueryInterface(const GUID& iid, void** obj) {
  QUERY_INTERFACE(IOTAWizard, iid, obj);
  return inherited::QueryInterface(iid, obj);
}

UnicodeString __fastcall TGTESTPluginWizard::GetIDString() {
  return "GTEST.Plugin.Wizard";
}

UnicodeString __fastcall TGTESTPluginWizard::GetName() {
  return "GTESTPlugin";
}

TWizardState  __fastcall TGTESTPluginWizard::GetState() {
  TWizardState result;
  result << wsEnabled;
  return result;
}

void __fastcall TGTESTPluginWizard::GTESTShow(TObject* Sender)
{
  TGTESTForm::ShowDockableModuleExplorer();
}

void __fastcall TGTESTPluginWizard::GTESTRun(TObject* Sender)
{
  TGTESTForm::ShowDockableModuleExplorer();
  TGTESTForm::RunTests();
}

void __fastcall TGTESTPluginWizard::BeforeSave() {
  inherited::BeforeSave();
}

void __fastcall TGTESTPluginWizard::AfterSave() {
  inherited::AfterSave();
}

void __fastcall TGTESTPluginWizard::Destroyed() {
  inherited::Destroyed();
}

void __fastcall TGTESTPluginWizard::Modified() {
  inherited::Modified();
}


