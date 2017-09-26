#pragma hdrstop
#include "GTESTPluginAddinOptions.h"
#include "GTESTPluginMacros.h"
#pragma package(smart_init)

TGTESTPluginAddInOptions* __fastcall AddOptionsFrameToIDE(TGTESTPluginOptions* Options) {
  _di_INTAEnvironmentOptionsServices EnvOpServices;
  if (BorlandIDEServices->Supports(EnvOpServices)) {
    TGTESTPluginAddInOptions* IDEOptions =
      new TGTESTPluginAddInOptions("TGTESTPluginAddInOptions", Options);
    EnvOpServices->RegisterAddInOptions(IDEOptions);
    return IDEOptions;
  }
  return NULL;
}

void __fastcall RemoveOptionsFrameFromIDE(TGTESTPluginAddInOptions* IDEOptions) {
  _di_INTAEnvironmentOptionsServices EnvOpServices;
  if (BorlandIDEServices->Supports(EnvOpServices) && (IDEOptions != NULL))  {
    EnvOpServices->UnregisterAddInOptions(IDEOptions);
  }
}

TGTESTPluginAddInOptions::TGTESTPluginAddInOptions(String strObjectName,
  TGTESTPluginOptions* Options) : TDGHNotifierObject(strObjectName) {
  FOptions = Options;
}

UnicodeString __fastcall TGTESTPluginAddInOptions::GetArea() {
  return "";
}

UnicodeString __fastcall TGTESTPluginAddInOptions::GetCaption() {
  return "GTESTPlugin.Test Options";
}

TCustomFrameClass __fastcall TGTESTPluginAddInOptions::GetFrameClass() {
  return __classid(TframeAppOptions);
}

void __fastcall TGTESTPluginAddInOptions::FrameCreated(TCustomFrame* AFrame) {
  FAppOptionsFrame = dynamic_cast<TframeAppOptions*>(AFrame);
  if (FAppOptionsFrame != NULL) {
    FAppOptionsFrame->LoadFrame(FOptions);
  }
}

void __fastcall TGTESTPluginAddInOptions::DialogClosed(bool Accepted) {
  Accepted = true;
}

bool __fastcall TGTESTPluginAddInOptions::ValidateContents() {
  if (FAppOptionsFrame != NULL) {
    FAppOptionsFrame->SaveFrame(FOptions);
  }
  return true;
}

int __fastcall TGTESTPluginAddInOptions::GetHelpContext() {
  return 0;
}

bool __fastcall TGTESTPluginAddInOptions::IncludeInIDEInsight() {
  return true;
}

void __fastcall TGTESTPluginAddInOptions::BeforeSave() {
  inherited::BeforeSave();
}

void __fastcall TGTESTPluginAddInOptions::AfterSave() {
  inherited::AfterSave();
}

void __fastcall TGTESTPluginAddInOptions::Destroyed() {
  inherited::Destroyed();
}

void __fastcall TGTESTPluginAddInOptions::Modified() {
  inherited::Modified();
}

HRESULT __stdcall TGTESTPluginAddInOptions::QueryInterface(const GUID& iid, void** obj) {
  QUERY_INTERFACE(INTAAddInOptions, iid, obj);
  return inherited::QueryInterface(iid, obj);
}

ULONG __stdcall TGTESTPluginAddInOptions::AddRef() {
  return inherited::AddRef();
}

ULONG __stdcall TGTESTPluginAddInOptions::Release() {
  return inherited::Release();
}

