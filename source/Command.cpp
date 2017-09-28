//---------------------------------------------------------------------------

#pragma hdrstop

#include "Command.h"
#include "PluginException.h"
#include "Utility.h"
#include <System.SysUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)

std::string Command::getParameters() const
{
	std::string parameters = "";

	for (int i = 0; i < m_parameterVector.size(); i++)
	{
		parameters += m_parameterVector.at(i);
		if(i != m_parameterVector.size()-1)
      parameters += " ";
	}

	return parameters;
}

void Command::execute() const
{
	std::wstring convertedCommand = std::wstring(m_commandString.begin(), m_commandString.end());
	std::string parameters = getParameters();
	std::wstring convertedParameters = std::wstring(parameters.begin(), parameters.end());

	SHELLEXECUTEINFO ShExecInfo = {0};
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = nullptr;
	ShExecInfo.lpVerb = nullptr;
	ShExecInfo.lpFile = convertedCommand.c_str();
	ShExecInfo.lpParameters = convertedParameters.c_str();
	ShExecInfo.lpDirectory = nullptr;
	ShExecInfo.nShow = SW_SHOW;
	ShExecInfo.hInstApp = nullptr;

	if(!ShellExecuteEx(&ShExecInfo))
	{
		throw PluginException(String("Problem occured when executing the following command:\n") +
												  Utility::convertStdStrToUnicodeStr(m_commandString.c_str()) + "\n" +
												  "parameters: \n" +
                          Utility::convertStdStrToUnicodeStr(getParameters()) + "\n" +
												  "error code: " + IntToStr(Integer(GetLastError())));
	}

	DWORD waitResult = WaitForSingleObject(ShExecInfo.hProcess, INFINITE);

	if (waitResult != WAIT_OBJECT_0)
	{
    throw PluginException(String("Problem occured when waiting for command:\n") +
												  Utility::convertStdStrToUnicodeStr(m_commandString.c_str()) + "\n" +
												  "parameters: \n" +
                          Utility::convertStdStrToUnicodeStr(getParameters()) + "\n" +
												  "error code: " + IntToStr(Integer(GetLastError())));
	}
}
