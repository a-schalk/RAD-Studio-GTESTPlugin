//---------------------------------------------------------------------------

#ifndef CommandH
#define CommandH
//---------------------------------------------------------------------------

#include <string>
#include <vector>
#include <windows.h>

class Command
{
private:
	std::string m_commandString;
	std::vector<std::string> m_parameterVector;

	std::string getParameters() const;
public:
  void execute() const;
  void setCommandString(std::string commandString) { m_commandString = commandString; }
  void addParameter(std::string parameter) { m_parameterVector.push_back(parameter); };
};

#endif
