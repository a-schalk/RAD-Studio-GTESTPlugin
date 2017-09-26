#include <vcl.h>
#pragma hdrstop
#include "GTESTPluginAppOptionsFrame.h"
#pragma package(smart_init)
#pragma resource "*.dfm"

__fastcall TframeAppOptions::TframeAppOptions(TComponent* Owner) : TFrame(Owner) {
}

void __fastcall TframeAppOptions::LoadFrame(TGTESTPluginOptions* Options) {
  chkEnabled->Checked = Options->EnableAutoSave;
  udInterval->Position = Options->AutoSaveInterval;
  chkPrompt->Checked = Options->PromptOnAutoSave;
}

void __fastcall TframeAppOptions::SaveFrame(TGTESTPluginOptions* Options) {
  Options->EnableAutoSave = chkEnabled->Checked;
  Options->AutoSaveInterval = udInterval->Position;
  Options->PromptOnAutoSave = chkPrompt->Checked;
}

