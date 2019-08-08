#include "stdafx.h"
#include "KeyMgr.h"


IMPLEMENT_SINGLETON(CKeyMgr)


CKeyMgr::CKeyMgr()
	:m_dwKey(0), m_dwKeyDown(0), m_dwKeyUp(0)
{
}


CKeyMgr::~CKeyMgr()
{
}

void CKeyMgr::Update()
{
	m_dwKey = 0;

	if (GetAsyncKeyState(VK_UP) & 0x8000)
		m_dwKey |= KEY_UP;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		m_dwKey |= KEY_DOWN;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		m_dwKey |= KEY_LEFT;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		m_dwKey |= KEY_RIGHT;
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		m_dwKey |= KEY_SPACE;
	if (GetAsyncKeyState('E') & 0x8000)
		m_dwKey |= KEY_E;
	if (GetAsyncKeyState('R') & 0x8000)
		m_dwKey |= KEY_R;
	if (GetAsyncKeyState('F') & 0x8000)
		m_dwKey |= KEY_F;
	if (GetAsyncKeyState('Z') & 0x8000)
		m_dwKey |= KEY_Z;
	if (GetAsyncKeyState('Q') & 0x8000)
		m_dwKey |= KEY_Q;
	if (GetAsyncKeyState(VK_MENU) & 0x8000)
		m_dwKey |= KEY_ALT;
	if (GetAsyncKeyState(VK_TAB) & 0x8000)
		m_dwKey |= KEY_TAB;
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		m_dwKey |= KEY_ESCAPE;
	if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
		m_dwKey |= KEY_SHIFT;
	if (GetAsyncKeyState('1') & 0x8000)
		m_dwKey |= KEY_1;
	if (GetAsyncKeyState('2') & 0x8000)
		m_dwKey |= KEY_2;
	if (GetAsyncKeyState('3') & 0x8000)
		m_dwKey |= KEY_3;
	if (GetAsyncKeyState('4') & 0x8000)
		m_dwKey |= KEY_4;
	if (GetAsyncKeyState('5') & 0x8000)
		m_dwKey |= KEY_5;
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
		m_dwKey |= KEY_LBUTTON;
	if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
		m_dwKey |= KEY_RBUTTON;
}

bool CKeyMgr::KeyPressing(DWORD dwKey)
{
	if (m_dwKey & dwKey)
		return true;

	return false;
}

bool CKeyMgr::KeyDown(DWORD dwKey)
{
	//이전에 키가 눌린 적이 없고 현재 눌린 상태 true
	if (!(m_dwKeyDown & dwKey) && (m_dwKey & dwKey))
	{
		m_dwKeyDown |= dwKey;
		return true;
	}

	//이전에 키가 눌린 적이 있고 현재 누르지 않은 상태 false
	if ((m_dwKeyDown & dwKey) && !(m_dwKey & dwKey))
	{
		m_dwKeyDown ^= dwKey;
		return false;
	}

	return false;
}

bool CKeyMgr::KeyUp(DWORD dwKey)
{
	//이전에 누른 적이 있고 현재 누르지 않은 상태 true
	if ((m_dwKeyUp & dwKey) && !(m_dwKey & dwKey))
	{
		m_dwKeyUp |= dwKey;
		return true;
	}
	//이전에 누른 적이 없고 현재 누른 상태 false
	if (!(m_dwKeyUp & dwKey) && (m_dwKey & dwKey))
	{
		m_dwKeyUp ^= dwKey;
		return false;
	}

	return false;
}