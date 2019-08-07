#pragma once

class CKeyMgr
{
DECLARE_SINGLETON(CKeyMgr)

private:
	CKeyMgr();
	~CKeyMgr();

private:
	DWORD m_dwKey;
	DWORD m_dwKeyDown;
	DWORD m_dwKeyUp;

public:
	void Update();

	bool KeyPressing(DWORD dwKey);
	
	bool KeyDown(DWORD dwKey);
	
	bool KeyUp(DWORD dwKey);
};

