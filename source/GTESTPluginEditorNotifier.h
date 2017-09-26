/**

  This module contains a class which implements the IOTAIDENotifier, IOTAIDENotifier50 and
  IOTAIDENotifier80 interfaces for capturing file notificationevents and compiler events in the
  RAD Studio IDE.

  @Author  David Hoyle
  @Version 1.0
  @Date    17 Dec 2016

**/
#ifndef GTESTPluginEditorNotifierH
#define GTESTPluginEditorNotifierH

#include <ToolsAPI.hpp>
#include <GTESTPluginNotifierObject.h>

class PACKAGE TGTESTPluginEditorNotifier : public TDGHNotifierObject, public INTAEditServicesNotifier {
  typedef TDGHNotifierObject inherited;
  public:
    __fastcall TGTESTPluginEditorNotifier(String strObjectName);
    __fastcall ~TGTESTPluginEditorNotifier();
    // IOTANotifer
    void __fastcall BeforeSave();
    void __fastcall AfterSave();
    void __fastcall Destroyed();
    void __fastcall Modified();
    // INTAEditServicesNotifier
    void __fastcall WindowShow(const _di_INTAEditWindow EditWindow, bool Show, bool LoadedFromDesktop)
    {
      DoNotification("::WindowShow");
    }
    void __fastcall WindowNotification(const _di_INTAEditWindow EditWindow, System::Classes::TOperation Operation)
    {
      DoNotification("::WindowNotification");
    }
    void __fastcall WindowActivated(const _di_INTAEditWindow EditWindow)
    {
      DoNotification("::WindowActivated");
    }
    void __fastcall WindowCommand(const _di_INTAEditWindow EditWindow, int Command, int Param, bool &Handled)
    {
      DoNotification("::WindowCommand");
    }
    void __fastcall EditorViewActivated(const _di_INTAEditWindow EditWindow, const _di_IOTAEditView EditView)
    {
      DoNotification("::EditorViewActivated");
    }
    void __fastcall EditorViewModified(const _di_INTAEditWindow EditWindow, const _di_IOTAEditView EditView)
    {
      DoNotification("::EditorViewModified");
    }
    void __fastcall DockFormVisibleChanged(const _di_INTAEditWindow EditWindow, Dockform::TDockableForm* DockForm)
    {
      DoNotification("::DockFormVisibleChanged");
    }
    void __fastcall DockFormUpdated(const _di_INTAEditWindow EditWindow, Dockform::TDockableForm* DockForm)
    {
      DoNotification("::DockFormUpdated");
    }
    void __fastcall DockFormRefresh(const _di_INTAEditWindow EditWindow, Dockform::TDockableForm* DockForm)
    {
      DoNotification("::DockFormRefresh");
    }
  protected:
    // IInterface
    virtual HRESULT __stdcall  QueryInterface(const GUID&, void**);
    virtual ULONG __stdcall  AddRef();
    virtual ULONG __stdcall  Release();
  private:
};

int __fastcall AddEditorNotifier();
void __fastcall RemoveEditorNotifier(int iEditorNotifierIndex);
#endif


