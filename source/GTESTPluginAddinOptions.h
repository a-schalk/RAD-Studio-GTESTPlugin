/**

  This module contains a class which implements the INTAAddInOptions interface than handles the
  insertion of the options frame into the RAD Studio IDEs options dialogue.

  @Author  David Hoyle
  @Version 1.0
  @Date    17 Dec 2017

**/
#ifndef GTESTPluginAddinOptionsH
#define GTESTPluginAddinOptionsH

#include <ToolsAPI.hpp>
#include "GTESTPluginAppOptionsFrame.h"
#include "GTESTPluginAppOptions.h"
#include "GTESTPluginNotifierObject.h"

class PACKAGE TGTESTPluginAddInOptions : public TDGHNotifierObject, public INTAAddInOptions {
  typedef TDGHNotifierObject inherited;
  private:
    TGTESTPluginOptions* FOptions;
    TframeAppOptions* FAppOptionsFrame;
  protected:
    // IOTANotifier
    void __fastcall BeforeSave();
    void __fastcall AfterSave();
    void __fastcall Destroyed();
    void __fastcall Modified();
    // IInterface
    virtual HRESULT __stdcall QueryInterface(const GUID& iid, void** obj);
    virtual ULONG __stdcall AddRef();
    virtual ULONG __stdcall Release();
    // INTAAddinOptions
    UnicodeString __fastcall GetArea();
    UnicodeString __fastcall GetCaption();
    TCustomFrameClass __fastcall GetFrameClass();
    void __fastcall FrameCreated(TCustomFrame* AFrame);
    void __fastcall DialogClosed(bool Accepted);
    bool __fastcall ValidateContents();
    int __fastcall GetHelpContext();
    bool __fastcall IncludeInIDEInsight();
  public:
    TGTESTPluginAddInOptions(String strObjectName, TGTESTPluginOptions* Options);
    __fastcall ~TGTESTPluginAddInOptions(){};
};

TGTESTPluginAddInOptions* __fastcall AddOptionsFrameToIDE(TGTESTPluginOptions* Options);
void __fastcall RemoveOptionsFrameFromIDE(TGTESTPluginAddInOptions* IDEOptions);

#endif
