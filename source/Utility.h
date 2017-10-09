//---------------------------------------------------------------------------

#ifndef UtilityH
#define UtilityH
//---------------------------------------------------------------------------
#include <System.hpp>
#include <string>

//!  Utility
/*!
  helper class for string converting
*/
class Utility
{
public:
  //! convert vcl unicodestring to std::string
  /*!
    \param unicodeStr unicodestring to convert
    \return convertet string
  */
  static std::string convertUnicodeStrToStdStr(System::UnicodeString unicodeStr);
  //! convert std::string to vcl unicodestring
  /*!
    \param stdStr std::string to convert
    \return convertet string
  */
  static System::UnicodeString convertStdStrToUnicodeStr(std::string stdStr);
};

#endif
