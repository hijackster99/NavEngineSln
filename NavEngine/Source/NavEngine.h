#pragma once

#ifdef WIN32

	#include <Windows.h>

#endif

#ifdef BUILD_DLL
	#define NAVENGINE_API __declspec(dllexport)
#else
	#define NAVENGINE_API __declspec(dllimport)
#endif