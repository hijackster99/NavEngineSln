#include "NavEngine.h"

PerGameSettings* PerGameSettings::m_Instance;

PerGameSettings::PerGameSettings()
{
	m_Instance = this;

	wcscpy_s(m_Instance->m_GameName, L"undefined");
	wcscpy_s(m_Instance->m_ShortName, L"undefined");
	wcscpy_s(m_Instance->m_BootTime, Time::GetDateTimeString(TRUE).c_str());
}

PerGameSettings::~PerGameSettings()
{

}
