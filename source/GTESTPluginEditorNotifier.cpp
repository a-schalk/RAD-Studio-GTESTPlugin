#pragma hdrstop
#include <GTESTPluginEditorNotifier.h>
#include "GTESTPluginMacros.h"
#include <SysUtils.hpp>
#pragma package(smart_init)

int __fastcall AddEditorNotifier() {
  _di_IOTAEditorServices EditorServices;
  if (BorlandIDEServices->Supports(EditorServices)) {
    return EditorServices->AddNotifier(new TGTESTPluginEditorNotifier("TGTESTPluginEditorNotifier"));
  }
  return -1;
}

void __fastcall RemoveEditorNotifier(int iEditorNotifierIndex) {
  _di_IOTAEditorServices EditorServices;
  if (BorlandIDEServices->Supports(EditorServices)) {
    if (iEditorNotifierIndex > -1) {
      EditorServices->RemoveNotifier(iEditorNotifierIndex);
    }
  }
}

__fastcall TGTESTPluginEditorNotifier::TGTESTPluginEditorNotifier(String strObjectName) :
  TDGHNotifierObject(strObjectName) {
  // Do nothing constructor
}

__fastcall TGTESTPluginEditorNotifier::~TGTESTPluginEditorNotifier() {
  // Do nothing deconstructor
}

void __fastcall TGTESTPluginEditorNotifier::BeforeSave() {
  inherited::BeforeSave();
  DoNotification("::BeforeSave");
}

void __fastcall TGTESTPluginEditorNotifier::AfterSave() {
  inherited::AfterSave();
  DoNotification("::AfterSave");
}

void __fastcall TGTESTPluginEditorNotifier::Destroyed() {
  inherited::Destroyed();
  DoNotification("::Destroyed");
}

void __fastcall TGTESTPluginEditorNotifier::Modified() {
  inherited::Modified();
  DoNotification("::Modified");
}

HRESULT __stdcall TGTESTPluginEditorNotifier::QueryInterface(const GUID& iid, void** obj) {
  QUERY_INTERFACE(INTAEditServicesNotifier, iid, obj);
  return inherited::QueryInterface(iid, obj);
}

ULONG __stdcall TGTESTPluginEditorNotifier::AddRef() {
  return inherited::AddRef();
}

ULONG __stdcall TGTESTPluginEditorNotifier::Release() {
  return inherited::Release();
}

