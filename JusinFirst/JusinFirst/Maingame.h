#pragma once

class CMaingame
{
private:
	HDC m_hDC;

public:
	CMaingame();
	~CMaingame();

public:
	void Initialize();
	void Update();
	void Render();

private:
	void Release();
};

