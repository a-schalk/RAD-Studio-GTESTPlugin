//---------------------------------------------------------------------------

#ifndef PluginExceptionH
#define PluginExceptionH
//---------------------------------------------------------------------------
#include <exception>
#include <ToolsApi.hpp>

class PluginException : public std::exception
{
private:
  String m_message;
public:
  PluginException(String message) : m_message(message) {}
  String getMessage() const { return m_message; }
  virtual const char* what() const throw();
};

#endif
