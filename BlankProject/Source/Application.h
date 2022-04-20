#pragma once

#include "Platform/Windows/IApplication.h"

class Application : public IApplication
{
public:
	Application();
	~Application();

	VOID GameSetup();
	VOID Initialize();
	VOID Update();
};