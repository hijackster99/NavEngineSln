#pragma once

class NAVENGINE_API PerGameSettings
{
public:
	PerGameSettings();
	~PerGameSettings();

	static WCHAR* GameName() { return m_Instance->m_GameName; }
	static WCHAR* ShortName() { return m_Instance->m_ShortName; }
	static HICON MainIcon() { return m_Instance->m_MainIcon; }
	static WCHAR* BootTime() { return m_Instance->m_BootTime; }

	static VOID SetGameName(UINT id) { LoadString(HInstance(), id, m_Instance->m_GameName, MAX_NAME_STRING); }
	static VOID SetShortName(UINT id) { LoadString(HInstance(), id, m_Instance->m_ShortName, MAX_NAME_STRING); }
	static VOID SetMainIcon(UINT id) { LoadIcon(HInstance(), MAKEINTRESOURCE(id)); }
private:
	static PerGameSettings* m_Instance;
	static PerGameSettings* Instance() { return m_Instance; }

	WCHAR m_GameName[MAX_NAME_STRING];
	WCHAR m_ShortName[MAX_NAME_STRING];
	HICON m_MainIcon;
	WCHAR m_BootTime[MAX_NAME_STRING];
};