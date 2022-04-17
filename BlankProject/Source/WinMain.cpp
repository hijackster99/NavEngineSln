#include "pch.h"

/**********************************/
/*     Global Variables           */
/**********************************/

#pragma region GlobalVariables

WCHAR WindowClass[MAX_NAME_STRING];
WCHAR WindowTitle[MAX_NAME_STRING];


INT WindowWidth;
INT	WindowHeight;

HICON hIcon;

#pragma endregion

/**********************************/
/*     Function Declarations      */
/**********************************/

#pragma region Declarations

VOID InitializeVariables(HINSTANCE inst);
VOID CreateWindowClass(HINSTANCE inst);
VOID InitializeWindow(HINSTANCE inst);
VOID MessageLoop();

LRESULT CALLBACK WindowProcess(HWND hWnd, UINT msg, WPARAM wparam, LPARAM lparam);

#pragma endregion

/**********************************/
/*       Windows Functions        */
/**********************************/

#pragma region WindowsFunctions
/*
int CALLBACK WinMain(HINSTANCE inst, HINSTANCE prevInst, LPSTR lpCmdLine, INT nCmdShow)
{

	InitializeVariables(inst);

	CreateWindowClass(inst);

	InitializeWindow(inst);
	
	MessageLoop();

	return 0;
}
*/
LRESULT CALLBACK WindowProcess(HWND hWnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, msg, wparam, lparam);
}

#pragma endregion

/**********************************/
/*     Function Definitions       */
/**********************************/

#pragma region Definitions

VOID InitializeVariables(HINSTANCE inst)
{
	LoadString(inst, IDS_PERGAMENAME, WindowTitle, MAX_NAME_STRING);
	LoadString(inst, IDS_WINDOWCLASS, WindowClass, MAX_NAME_STRING);

	WindowWidth = 1366;
	WindowHeight = 768;

	hIcon = LoadIcon(inst, MAKEINTRESOURCE(IDI_MAINICON));
}

VOID CreateWindowClass(HINSTANCE inst)
{
	WNDCLASSEX wnd;

	wnd.cbSize = sizeof(WNDCLASSEX);
	wnd.style = CS_HREDRAW | CS_VREDRAW;
	wnd.cbClsExtra = 0;
	wnd.cbWndExtra = 0;

	wnd.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wnd.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);

	wnd.hIcon = hIcon;
	wnd.hIconSm = hIcon;

	wnd.lpszClassName = WindowClass;

	wnd.lpszMenuName = nullptr;

	wnd.hInstance = inst;

	wnd.lpfnWndProc = WindowProcess;

	RegisterClassEx(&wnd);
}

VOID InitializeWindow(HINSTANCE inst)
{
	HWND hWnd = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, WindowWidth, WindowHeight, nullptr, nullptr, inst, nullptr);

	if (!hWnd)
	{
		MessageBox(0, L"Failed to Create Window!", 0, 0);
		PostQuitMessage(1);
	}

	ShowWindow(hWnd, SW_SHOW);
}

VOID MessageLoop()
{
	MSG msg = { 0 };

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}

#pragma endregion

/**********************************/