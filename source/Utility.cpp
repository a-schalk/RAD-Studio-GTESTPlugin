//---------------------------------------------------------------------------

#pragma hdrstop

#include "Utility.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

std::string Utility::convertUnicodeStrToStdStr(System::UnicodeString unicodeStr)
{
  AnsiString ansiStr = unicodeStr;
  return ansiStr.c_str();
}

System::UnicodeString Utility::convertStdStrToUnicodeStr(std::string stdStr)
{
  return stdStr.c_str();
}
