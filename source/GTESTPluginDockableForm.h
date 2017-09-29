//---------------------------------------------------------------------------

#ifndef GTESTPluginDockableFormH
#define GTESTPluginDockableFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <DockForm.hpp>
#include <ToolsApi.hpp>
#include "GTESTPluginDockableFrame.h"
#include "GTESTPluginDebugNotifier.h"

//---------------------------------------------------------------------------
class TGTESTForm : public TDockableForm
{
  typedef TDockableForm inherited;
__published:	// Von der IDE verwaltete Komponenten
private:	// Benutzer-Deklarationen
  TGTESTFrame *pGTESTFrame;
public:		// Benutzer-Deklarationen
  __fastcall TGTESTForm(TComponent* Owner);
  __fastcall ~TGTESTForm();
  void __fastcall Focus();
  bool __fastcall Floating()
  {
    return this->GetFloating();
  }

  static void __fastcall RunTests();
  void __fastcall Run();

  static void __fastcall ShowDockableModuleExplorer();
  static void __fastcall RemoveDockableModuleExplorer();
  static void __fastcall CreateDockableModuleExplorer();
};
//---------------------------------------------------------------------------
extern PACKAGE TGTESTForm *GTESTForm;
//---------------------------------------------------------------------------
#endif
