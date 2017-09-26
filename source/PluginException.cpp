//---------------------------------------------------------------------------

#pragma hdrstop

#include "PluginException.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

const char* PluginException::what() const throw()
{
  return AnsiString(m_message).c_str();
}
