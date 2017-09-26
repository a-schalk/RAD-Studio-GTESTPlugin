#pragma hdrstop
#include "GTESTPluginAppOptions.h"
#pragma package(smart_init)

#include <SysUtils.hpp>

__fastcall TGTESTPluginOptions::TGTESTPluginOptions() {
  String strModuleFileName = GetModuleName(unsigned(HInstance));
  FIniFileName = ChangeFileExt(strModuleFileName, ".ini");
  FIniFile = new TMemIniFile(FIniFileName);
  LoadSettings();
}

__fastcall TGTESTPluginOptions::~TGTESTPluginOptions() {
  SaveSettings();
  delete FIniFile;
}

void __fastcall TGTESTPluginOptions::LoadSettings() {
  FEnabled = FIniFile->ReadBool("AutoSave", "Enabled", false);
  FInterval = FIniFile->ReadInteger("AutoSave", "Interval", 300);
  FPromptOn = FIniFile->ReadBool("AutoSave", "PromptOn", true);
}

void __fastcall TGTESTPluginOptions::SaveSettings() {
  FIniFile->WriteBool("AutoSave", "Enabled", FEnabled);
  FIniFile->WriteInteger("AutoSave", "Interval", FInterval);
  FIniFile->WriteBool("AutoSave", "PromptOn", FPromptOn);
  FIniFile->UpdateFile();
}


