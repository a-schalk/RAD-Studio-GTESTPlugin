//---------------------------------------------------------------------------

#ifndef UtilityH
#define UtilityH
//---------------------------------------------------------------------------
#include <System.hpp>
#include <string>

class Utility
{
public:
  static std::string convertUnicodeStrToStdStr(System::UnicodeString unicodeStr);
  static System::UnicodeString convertStdStrToUnicodeStr(std::string stdStr);
};

#endif
