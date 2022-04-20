#include "pch.h"
#include "Application.h"
#include "Platform/Windows/WinEntry.h"

ENTRYAPP(Application)

Application::Application()
{

}

Application::~Application()
{

}

VOID Application::GameSetup()
{
	PerGameSettings::SetGameName(IDS_PERGAMENAME);
	PerGameSettings::SetShortName(IDS_SHORTNAME);
	PerGameSettings::SetMainIcon(IDI_MAINICON);
}

VOID Application::Initialize()
{
	Logger::PrintLog(L" Loaded %s! ", L"Blank Project");
}

VOID Application::Update()
{
	MessageBox(0, L" Loop ", 0, 0);
}
