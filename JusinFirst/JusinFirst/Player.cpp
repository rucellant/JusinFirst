#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo.bIsDead = false;
	m_tInfo.fWidth = PLAYER_IDLE_WIDTH;
	m_tInfo.fHeight = PLAYER_IDLE_HEIGHT;
	m_tInfo.fX = GAMECX*0.5f;
	m_tInfo.fY = GAMECY*0.5f;
	m_tInfo.fXSpeed = 5;
	m_tInfo.fYSpeed = 5;

	m_tFrame.dwOldTime = GetTickCount();
	m_tFrame.dwCurTime = GetTickCount();
	m_tFrame.dwFrameSpeed = 50;
	m_tFrame.eState = STATE_IDLE;
	m_tFrame.iCol = 0;
	m_tFrame.iRow = PLAYER_SOUTH;
	m_tFrame.iFrameCount = 21;
	m_tFrame.wstrObjectKey = L"Player_Idle";
	
	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Player/Player_Idle.bmp", L"Player_Idle");
	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Player/Player_Running.bmp", L"Player_Run");

	CGameObj::UpdateRect();
}

int CPlayer::Update()
{
	KeyInput();
	IsFrame();
	return 0;
}

void CPlayer::Render(HDC hDC)
{
	HDC hMemDC = 0;

	switch (m_tFrame.eState)
	{
	case STATE_IDLE:
		hMemDC = CBmpMgr::GetInstance()->GetMemDC(m_tFrame.wstrObjectKey);
		m_tInfo.fWidth = PLAYER_IDLE_WIDTH;
		m_tInfo.fHeight = PLAYER_IDLE_HEIGHT;
		m_tFrame.wstrObjectKey = L"Player_Idle";
		break;
	case STATE_RUN:
		hMemDC = CBmpMgr::GetInstance()->GetMemDC(m_tFrame.wstrObjectKey);
		m_tInfo.fWidth = PLAYER_RUN_WIDTH;
		m_tInfo.fHeight = PLAYER_RUN_HEIGHT;
		m_tFrame.wstrObjectKey = L"Player_Run";
		break;
	}

	CGameObj::UpdateRect();

	GdiTransparentBlt(hDC, int(m_tRect.left - CScrollMgr::XScroll), int(m_tRect.top - CScrollMgr::YScroll),
		m_tInfo.fWidth, m_tInfo.fHeight, hMemDC,
		m_tFrame.iCol*m_tInfo.fWidth, m_tFrame.iRow*m_tInfo.fHeight,
		m_tInfo.fWidth, m_tInfo.fHeight, RGB(255, 255, 255));
}

void CPlayer::Release()
{
}

void CPlayer::KeyInput()
{
	m_tFrame.eState = STATE_IDLE;

	//왼쪽으로 이동
	if (CKeyMgr::GetInstance()->KeyPressing(KEY_LEFT))
	{
		if (CKeyMgr::GetInstance()->KeyPressing(KEY_UP))
		{
			m_tInfo.fX -= m_tInfo.fXSpeed / ROOT2;
			CScrollMgr::XScroll -= m_tInfo.fXSpeed / ROOT2;
			m_tFrame.iRow = PLAYER_NORTH_WEST;
		}
		else if (CKeyMgr::GetInstance()->KeyPressing(KEY_DOWN))
		{
			m_tInfo.fX -= m_tInfo.fXSpeed / ROOT2;
			CScrollMgr::XScroll -= m_tInfo.fXSpeed / ROOT2;
			m_tFrame.iRow = PLAYER_SOUTH_WEST;
		}
		else
		{
			m_tInfo.fX -= m_tInfo.fXSpeed;
			CScrollMgr::XScroll -= m_tInfo.fXSpeed;
			m_tFrame.iRow = PLAYER_WEST;
		}

		m_tFrame.eState = STATE_RUN;
		m_tFrame.wstrObjectKey = L"Player_Run";
	}

	//오른쪽으로 이동
	if (CKeyMgr::GetInstance()->KeyPressing(KEY_RIGHT))
	{
		if (CKeyMgr::GetInstance()->KeyPressing(KEY_UP))
		{
			m_tInfo.fX += m_tInfo.fXSpeed / ROOT2;
			CScrollMgr::XScroll += m_tInfo.fXSpeed / ROOT2;
			m_tFrame.iRow = PLAYER_EAST_NORTH;
		}
		else if (CKeyMgr::GetInstance()->KeyPressing(KEY_DOWN))
		{
			m_tInfo.fX += m_tInfo.fXSpeed / ROOT2;
			CScrollMgr::XScroll += m_tInfo.fXSpeed / ROOT2;
			m_tFrame.iRow = PLAYER_EAST_SOUTH;
		}
		else
		{
			m_tInfo.fX += m_tInfo.fXSpeed;
			CScrollMgr::XScroll += m_tInfo.fXSpeed;
			m_tFrame.iRow = PLAYER_EAST;
		}

		m_tFrame.eState = STATE_RUN;
		m_tFrame.wstrObjectKey = L"Player_Run";
	}

	//북쪽으로 이동
	if (CKeyMgr::GetInstance()->KeyPressing(KEY_UP))
	{
		if (CKeyMgr::GetInstance()->KeyPressing(KEY_LEFT))
		{
			m_tInfo.fY -= m_tInfo.fYSpeed / ROOT2;
			CScrollMgr::YScroll -= m_tInfo.fYSpeed / ROOT2;
			m_tFrame.iRow = PLAYER_NORTH_WEST;
		}
		else if (CKeyMgr::GetInstance()->KeyPressing(KEY_RIGHT))
		{
			m_tInfo.fY -= m_tInfo.fYSpeed / ROOT2;
			CScrollMgr::YScroll -= m_tInfo.fYSpeed / ROOT2;
			m_tFrame.iRow = PLAYER_EAST_NORTH;
		}
		else
		{
			m_tInfo.fY -= m_tInfo.fYSpeed;
			CScrollMgr::YScroll -= m_tInfo.fYSpeed;
			m_tFrame.iRow = PLAYER_NORTH;
		}

		m_tFrame.eState = STATE_RUN;
		m_tFrame.wstrObjectKey = L"Player_Run";
	}

	//남쪽으로 이동
	if (CKeyMgr::GetInstance()->KeyPressing(KEY_DOWN))
	{
		if (CKeyMgr::GetInstance()->KeyPressing(KEY_LEFT))
		{
			m_tInfo.fY += m_tInfo.fYSpeed / ROOT2;
			CScrollMgr::YScroll += m_tInfo.fYSpeed / ROOT2;
			m_tFrame.iRow = PLAYER_SOUTH_WEST;
		}
		else if (CKeyMgr::GetInstance()->KeyPressing(KEY_RIGHT))
		{
			m_tInfo.fY += m_tInfo.fYSpeed / ROOT2;
			CScrollMgr::YScroll += m_tInfo.fYSpeed / ROOT2;
			m_tFrame.iRow = PLAYER_EAST_SOUTH;
		}
		else
		{
			m_tInfo.fY += m_tInfo.fYSpeed;
			CScrollMgr::YScroll += m_tInfo.fYSpeed;
			m_tFrame.iRow = PLAYER_SOUTH;
		}

		m_tFrame.eState = STATE_RUN;
		m_tFrame.wstrObjectKey = L"Player_Run";
	}
}

void CPlayer::IsFrame()
{
	m_tFrame.dwCurTime = GetTickCount();

	if (m_tFrame.dwCurTime - m_tFrame.dwOldTime >= m_tFrame.dwFrameSpeed)
		m_tFrame.iCol += 1;

	if (m_tFrame.iCol > m_tFrame.iFrameCount)
		m_tFrame.iCol = 0;
}
