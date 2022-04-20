#pragma once
#include <string>

namespace Time
{
	std::wstring NAVENGINE_API GetTime(BOOL stripped = FALSE);
	std::wstring NAVENGINE_API GetDate(BOOL stripped = FALSE);
	std::wstring NAVENGINE_API GetDateTimeString(BOOL stripped = FALSE);
}