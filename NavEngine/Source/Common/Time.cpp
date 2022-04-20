#include "NavEngine.h"
#include <ctime>
#include <sstream>
#include <iomanip>

std::wstring NAVENGINE_API Time::GetTime(BOOL stripped)
{
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	std::wstringstream wss;

	if (stripped)
		wss << std::put_time(&ltm, L"%H%M%S");
	else
		wss << std::put_time(&ltm, L"%H:%M:%S");

	std::wstring timeString = wss.str();

	return timeString;
}

std::wstring NAVENGINE_API Time::GetDate(BOOL stripped)
{
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	std::wstringstream wss;

	if (stripped)
		wss << std::put_time(&ltm, L"%m%d%y");
	else
		wss << std::put_time(&ltm, L"%m/%d/%y");

	std::wstring timeString = wss.str();

	return timeString;
}

std::wstring NAVENGINE_API Time::GetDateTimeString(BOOL stripped)
{
	return GetDate(stripped) + (stripped ? L"" : L" ") + GetTime(stripped);

}
