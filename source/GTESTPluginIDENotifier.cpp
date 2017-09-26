#pragma hdrstop
#include <GTESTPluginIDENotifier.h>
#include "GTESTPluginMacros.h"
#include <SysUtils.hpp>
#pragma package(smart_init)

int __fastcall AddIDENotifier() {
  _di_IOTAServices IDEServices;
  if (BorlandIDEServices->Supports(IDEServices)) {
    return IDEServices->AddNotifier(new TGTESTPluginIDENotifier("TGTESTPluginIDENotifier"));
  }
  return -1;
}

void __fastcall RemoveIDENotifier(int iIDENotifierIndex) {
  _di_IOTAServices IDEServices;
  if (BorlandIDEServices->Supports(IDEServices)) {
    if (iIDENotifierIndex > -1) {
      IDEServices->RemoveNotifier(iIDENotifierIndex);
    }
  }
}

__fastcall TGTESTPluginIDENotifier::TGTESTPluginIDENotifier(String strObjectName) :
  TDGHNotifierObject(strObjectName) {
  // Do nothing constructor
}

__fastcall TGTESTPluginIDENotifier::~TGTESTPluginIDENotifier() {
  // Do nothing deconstructor
}

void __fastcall TGTESTPluginIDENotifier::FileNotification(
  TOTAFileNotification NotifyCode, const System::UnicodeString FileName, bool &Cancel) {
  const String strNotifyCode[11] = {
    "ofnFileOpening",
    "ofnFileOpened",
    "ofnFileClosing",
    "ofnDefaultDesktopLoad",
    "ofnDefaultDesktopSave",
    "ofnProjectDesktopLoad",
    "ofnProjectDesktopSave",
    "ofnPackageInstalled",
    "ofnPackageUninstalled",
    "ofnActiveProjectChanged",
    "ofnProjectOpenedFromTemplate"
  };
  DoNotification(
    Format("FileNotification: NotifyCode(%d): %s, FileName: %s",
      ARRAYOFCONST((
        NotifyCode,
        strNotifyCode[NotifyCode],
        ExtractFileName(FileName)
      ))
    )
  );
  switch(NotifyCode)
  {
    case ofnActiveProjectChanged:
    {
      break;
    }
    default:
      break;
  }
}

void __fastcall TGTESTPluginIDENotifier::BeforeCompile(const _di_IOTAProject Project,
  bool &Cancel) {
  DoNotification(
    Format("::BeforeCompile: Project: %s",
      ARRAYOFCONST((ExtractFileName(Project->FileName)))
    )
  );
}

void __fastcall TGTESTPluginIDENotifier::AfterCompile(bool Succeeded) {
  DoNotification(
    Format("::AfterCompile: %s",
      ARRAYOFCONST((
        Succeeded ? "True" : "False"
      ))
    )
  );
}

void __fastcall TGTESTPluginIDENotifier::BeforeCompile(const _di_IOTAProject Project,
  bool IsCodeInsight, bool &Cancel) {
  DoNotification(
    Format("50::BeforeCompile: Project: %s, IsCodeInsight: %s",
      ARRAYOFCONST((
        ExtractFileName(Project->FileName),
        IsCodeInsight ? "True" : "False"
      ))
    )
  );
}

void __fastcall TGTESTPluginIDENotifier::AfterCompile(bool Succeeded,
  bool IsCodeInsight) {
  DoNotification(
    Format("50::AfterCompile: Succeeded: %s, IsCodeInsight: %s",
      ARRAYOFCONST((
        Succeeded ? "True" : "False",
        IsCodeInsight ? "True" : "False"
      ))
    )
  );
}

void __fastcall TGTESTPluginIDENotifier::AfterCompile(const _di_IOTAProject Project,
  bool Succeeded, bool IsCodeInsight) {
  DoNotification(
    Format("80::AfterCompile: Project: %s, Succeeded: %s, IsCodeInsigh: %s",
      ARRAYOFCONST((
        ExtractFileName(Project->FileName),
        Succeeded ? "True" : "False",
        IsCodeInsight ? "True" : "False"
      ))
    )
  );
}

void __fastcall TGTESTPluginIDENotifier::BeforeSave() {
  inherited::BeforeSave();
  DoNotification("::BeforeSave");
}

void __fastcall TGTESTPluginIDENotifier::AfterSave() {
  inherited::AfterSave();
  DoNotification("::AfterSave");
}

void __fastcall TGTESTPluginIDENotifier::Destroyed() {
  inherited::Destroyed();
  DoNotification("::Destroyed");
}

void __fastcall TGTESTPluginIDENotifier::Modified() {
  inherited::Modified();
  DoNotification("::Modified");
}

HRESULT __stdcall TGTESTPluginIDENotifier::QueryInterface(const GUID& iid, void** obj) {
  QUERY_INTERFACE(IOTAIDENotifier50, iid, obj);
  QUERY_INTERFACE(IOTAIDENotifier80, iid, obj);
  QUERY_INTERFACE(IOTAIDENotifier, iid, obj);
  return inherited::QueryInterface(iid, obj);
}

ULONG __stdcall TGTESTPluginIDENotifier::AddRef() {
  return inherited::AddRef();
}

ULONG __stdcall TGTESTPluginIDENotifier::Release() {
  return inherited::Release();
}

