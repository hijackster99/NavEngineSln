#include "NavEngine.h"
#include "Platform/Windows/IApplication.h"

extern IApplication* EntryApplication();

INT CALLBACK WinMain(HINSTANCE inst, HINSTANCE prevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	auto EntryApp = EntryApplication();

	PerGameSettings gameSettings;

	EntryApp->GameSetup();

	Logger logger;

	EntryApp->Initialize();

	MSG msg = { 0 };

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			EntryApp->Update();
		}
	}

	return 0;
}