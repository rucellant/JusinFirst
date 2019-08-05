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
	bool KeyPressing(TCHAR tKey);
	
	bool KeyDown(DWORD dwKey);
	bool KeyDown(TCHAR tKey);
	
	bool KeyUp(DWORD dwKey);
	bool KeyUp(TCHAR tKey);
};

