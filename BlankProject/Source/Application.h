#pragma once

#include "Platform/WIN32/IApplication.h"

class Application : public IApplication
{
public:
	Application();
	~Application();

	VOID Initialize();
	VOID Update();
};