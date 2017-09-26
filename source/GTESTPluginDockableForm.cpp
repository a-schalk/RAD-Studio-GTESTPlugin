//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GTESTPluginDockableForm.h"
#include <DeskUtil.hpp>
#include <ToolsApi.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGTESTForm *GTESTForm = NULL;

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
// Ist verantwortlich für das Desktop Saving
// TODO muss noch richtig gemacht werden
//  if(RegisterFieldAddress)
//  {
//   RegisterFieldAddress(typeid(GTESTForm).name(), GTESTForm);
//  }
//  TMetaClass *FormClass = __classid(TGTESTForm);
//  RegisterDesktopFormClass(FormClass, typeid(GTESTForm).name(), typeid(GTESTForm).name());
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
// TODO muss zusammen mit RegisterDockableForm noch richtig umgesetzt werden
//  if(UnregisterFieldAddress)
//    UnregisterFieldAddress(GTESTForm);
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
  GTESTForm = new TGTESTForm(NULL);
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
  AutoSave = True;
  SaveStateNecessary = True;
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
  SaveStateNecessary = true;
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
