#pragma once
#include <string>

class NAVENGINE_API Logger
{
public:
	Logger();

	~Logger();

	static Logger* Instance() { return instance_field; }

	static VOID PrintLog(const WCHAR* fmt, ...);

	static std::wstring LogDirectory();
	static std::wstring LogFile();
private:
	static Logger* instance_field;
};