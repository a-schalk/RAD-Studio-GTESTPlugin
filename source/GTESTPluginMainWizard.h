/**

  This module contains a class that implements the IOTAWizard and IOTAMenuWizard interfaces
  to provide a main wizard interfaces for this OTA project which installs and Open Tools
  API wizard / expert / plug-in into the RAD Studio IDE.

  This clas manages ALL objects created and used by this application.

  @Author  David Hoyle
  @Version 1.0
  @date    17 Dec 2016

**/
#ifndef GTESTPluginMainWizardH
#define GTESTPluginMainWizardH

#include <ToolsAPI.hpp>
#include <GTESTPluginNotifierObject.h>
#include "GTESTPluginAppOptions.h"
#include <GTESTPluginIDENotifier.h>
#include "GTESTPluginAddinOptions.h"
#include <ExtCtrls.hpp>

class PACKAGE TGTESTPluginWizard : public TDGHNotifierObject, public IOTAWizard {
  typedef TDGHNotifierObject inherited;
  private:
    int FAboutBoxPlugin;
    int FIDENotifier;
    TMenuItem* GTESTMenuItem;
  protected:
    // IOTAWizard
    virtual UnicodeString __fastcall GetIDString();
    virtual UnicodeString __fastcall GetName();
    virtual TWizardState  __fastcall GetState();
    virtual void __fastcall Execute(){}
    // IOTANotifer
    void __fastcall BeforeSave();
    void __fastcall AfterSave();
    void __fastcall Destroyed();
    void __fastcall Modified();
    // IInterface
    virtual HRESULT __stdcall QueryInterface(const GUID& iid, void** obj);
    virtual ULONG __stdcall AddRef();
    virtual ULONG __stdcall Release();
    // Non-interface methods
    void __fastcall AutoSaveTimerEvent(TObject* Sender);
    void __fastcall SaveModifiedFiles();
  public:
    void __fastcall GTESTShow(TObject* Sender);
    void __fastcall GTESTRun(TObject* Sender);

    __fastcall TGTESTPluginWizard(String strObjectName);
    __fastcall ~TGTESTPluginWizard();
};
#endif

