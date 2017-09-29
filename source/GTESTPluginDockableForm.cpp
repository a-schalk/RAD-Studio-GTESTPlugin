//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GTESTPluginDockableForm.h"
#include <DeskUtil.hpp>
#include <ToolsApi.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGTESTForm *GTESTForm = nullptr;
bool constructed = false;

//---------------------------------------------------------------------------
/**

  This procedure makes the dockable module explorer visible.

  @precon  None.
  @postcon Makes the dockable module explorer visible.

  @param   Form as a TfrmDockableModuleExplorer

**/
void __fastcall ShowDockableForm()
{
  if(!GTESTForm)
  {
    return;
  }
  if(!GTESTForm->Floating())
  {
    GTESTForm->ForceShow();
    FocusWindow(GTESTForm);
    GTESTForm->Focus();
  }
  else
  {
    GTESTForm->Show();
    GTESTForm->Focus();
  }
}

/**

  This procedure registers the dockable form with the IDE.

  @precon  None.
  @postcon The dockable form is registered with the IDE.

  @param   FormClass as a TfrmDockableModuleExplorerClass
  @param   FormVar
  @param   FormName  as a String as a constant

**/
void __fastcall RegisterDockableForm()
{
  if(RegisterFieldAddress)
  {
   RegisterFieldAddress(typeid(GTESTForm).name(), &GTESTForm);
  }
  TDesktopFormClass AFormClass = __classid(TGTESTForm);
  RegisterDesktopFormClass(AFormClass, typeid(GTESTForm).name(), typeid(GTESTForm).name());
}

/**

  This method unregisters the dockable form with the IDE.

  @precon  None.
  @postcon The dockable form is unregistered with the IDE.

  @param   FormVar
  @param   FormName as a String as a constant

**/
void __fastcall UnRegisterDockableForm()
{
  if(UnregisterFieldAddress)
    UnregisterFieldAddress(&GTESTForm);
}

/**

  This procedure creates an instance of the dockable form.

  @precon  FormVar is the instance reference and FormCass is the type of class
           to be created..
  @postcon The form instance is created.

  @param   FormVar   as a TfrmDockableModuleExplorer as a reference
  @param   FormClass as a TfrmDockableModuleExplorerClass

**/
void __fastcall CreateDockableForm()
{
  GTESTForm = new TGTESTForm(Application->MainForm);
  RegisterDockableForm();
}

/**

  This procedure frees the instance of the dockable form.

  @precon  None.
  @postcon Free the instance of the dockable form.

  @param   FormVar as a TfrmDockableModuleExplorer as a reference

**/
void __fastcall FreeDockableForm()
{
  if(GTESTForm)
  {
    UnRegisterDockableForm();
    if(constructed)
      delete GTESTForm;
  }
}

// TfrmDockableModuleExplorer

/**

  This is the constructor method for the TfrmDockableModuleExplorer class.

  @precon  None.
  @postcon Sets the dockable form up for being saved within the BDS 2006 IDE and
           then creates a Module Explorer Frame and places inside the form.

  @param   AOwner as a TComponent

**/
__fastcall TGTESTForm::TGTESTForm(TComponent* Owner) : TDockableForm(Owner)
{
  constructed = true;
  DeskSection = typeid(this).name();
  AutoSave = true;
  SaveStateNecessary = true;
  pGTESTFrame = new TGTESTFrame(this);
  pGTESTFrame->Parent = this;
  pGTESTFrame->Align = alClient;
}


/**

  This is the destructor method for the TfrmDockableModuleExplorer class.

  @precon  None.
  @postcon Destroys the Module Explorer Frame and ensures the desktop is saved.

**/
__fastcall TGTESTForm::~TGTESTForm()
{
  constructed = false;
  SaveStateNecessary = false;
  delete pGTESTFrame;
}

/**


  This method focuses the modukle explorers tree view the be focused IF
  available.

  @precon  None.
  @postcon Focuses the modukle explorers tree view the be focused IF available.


**/
void __fastcall TGTESTForm::Focus()
{
  //nothing to do
}

/**

  This is a class method to create the dockable form instance.

  @precon  None.
  @postcon The form instance is created if one is not already present.

**/
void __fastcall TGTESTForm::CreateDockableModuleExplorer()
{
  if (!GTESTForm)
  {
    CreateDockableForm();
  }
}

/**

  This is a class method to remove the dockable form.

  @precon  None.
  @postcon Removes the instance of the dockable form.

**/
void __fastcall TGTESTForm::RemoveDockableModuleExplorer()
{
  FreeDockableForm();
}

/**

  This method is a class method for displaying the dockable form. If the form
  does not already exist it is created first.

  @precon  None.
  @postcon Displays the dockable form.

**/
void __fastcall TGTESTForm::ShowDockableModuleExplorer()
{
  CreateDockableModuleExplorer();
  ShowDockableForm();
}

void __fastcall TGTESTForm::RunTests()
{
  if(GTESTForm)
    GTESTForm->Run();
}

void __fastcall TGTESTForm::Run()
{
  if(pGTESTFrame)
    pGTESTFrame->Run();
}

//---------------------------------------------------------------------------
