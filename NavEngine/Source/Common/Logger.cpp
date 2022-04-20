#include "NavEngine.h"
#include <fstream>
#include "Shlobj.h"

Logger* Logger::instance_field;

Logger::Logger()
{
	instance_field = this;
}

Logger::~Logger()
{
}

VOID Logger::PrintLog(const WCHAR* fmt, ...)
{
	WCHAR buf[4096];
	va_list args;

	va_start(args, fmt);
	vswprintf_s(buf, fmt, args);
	va_end(args);

	OutputDebugString(buf);

	std::wfstream outStr;

	outStr.open(std::wstring(LogDirectory() + L"/" + LogFile()), std::ios_base::app);

	if (outStr.is_open())
	{
		std::wstring s = buf;
		outStr << L"[" << Time::GetDateTimeString() << L"]: " << s;
		outStr.close();

		OutputDebugString(s.c_str());
	}
	else
	{
		MessageBox(NULL, L"Failed to Open Log File...", L"Log Error", MB_OK);
	}
}

std::wstring Logger::LogDirectory()
{
	WCHAR Path[1024];
	#ifdef _DEBUG
		wcscpy_s(Path, L".");
	#else
		WCHAR* AppDataLocal;
		SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &AppDataLocal);
		wcscpy_s(Path, AppDataLocal);
		wcscat_s(Path, L"\\");
		wcscat_s(Path, PerGameSettings::GameName());
		CreateDirectory(Path, NULL);
	#endif
	wcscat_s(Path, L"\\Log");
	OutputDebugString(Path);
	CreateDirectory(Path, NULL);

	return Path;
}

std::wstring Logger::LogFile()
{
	WCHAR File[1024];

	wcscpy_s(File, PerGameSettings::GameName());
	wcscat_s(File, PerGameSettings::BootTime());
	wcscat_s(File, L".log");

	return File;
}
