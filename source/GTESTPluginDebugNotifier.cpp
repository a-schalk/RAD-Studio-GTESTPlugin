//---------------------------------------------------------------------------

#pragma hdrstop

#include "GTESTPluginDebugNotifier.h"

ULONG __stdcall GTESTPluginDebugNotifier::AddRef() {
  return inherited::AddRef();
}

ULONG __stdcall GTESTPluginDebugNotifier::Release() {
  return inherited::Release();
}

HRESULT __stdcall GTESTPluginDebugNotifier::QueryInterface(const GUID& iid, void** obj) {
  return inherited::QueryInterface(iid, obj);
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
