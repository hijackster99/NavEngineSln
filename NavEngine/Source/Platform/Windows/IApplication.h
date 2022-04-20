#pragma once

#define ENTRYAPP(x) IApplication* EntryApplication() { return new x; }

class NAVENGINE_API IApplication
{
public:
	IApplication();
	virtual ~IApplication() {}

	virtual VOID GameSetup() = 0;
	virtual VOID Initialize() = 0;
	virtual VOID Update() = 0;
};

IApplication* EntryApplication();