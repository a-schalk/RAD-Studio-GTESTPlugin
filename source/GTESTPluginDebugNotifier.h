//---------------------------------------------------------------------------

#ifndef MyNotifireH
#define MyNotifireH

#include <GTESTPluginNotifierObject.h>

class GTESTPluginDebugNotifier : public TDGHNotifierObject
{
protected:
  typedef TDGHNotifierObject inherited;
  virtual HRESULT __stdcall QueryInterface(const GUID&, void**);
  virtual ULONG __stdcall AddRef();
  virtual ULONG __stdcall Release();
public:
  __fastcall GTESTPluginDebugNotifier() : TDGHNotifierObject("Debug") {};
  __fastcall ~GTESTPluginDebugNotifier(){};
	void __fastcall Debug(String message)
  {
		this->DoNotification(": " + message);
  }
};

//---------------------------------------------------------------------------
#endif
