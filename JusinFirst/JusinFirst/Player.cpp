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
	m_tFrame.dwFrameSpeed = 30;
	m_tFrame.eState = STATE_IDLE;
	m_tFrame.eDir = DIR_DOWN;
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
	Moving();
	IsFrame();

	return NO_EVENT;
}

void CPlayer::Render(HDC hDC)
{
	HDC hMemDC = 0;

	switch (m_tFrame.eState)
	{
	case STATE_IDLE:
		m_tFrame.wstrObjectKey = L"Player_Idle";
		hMemDC = CBmpMgr::GetInstance()->GetMemDC(m_tFrame.wstrObjectKey);
		m_tInfo.fWidth = PLAYER_IDLE_WIDTH;
		m_tInfo.fHeight = PLAYER_IDLE_HEIGHT;
		break;
	case STATE_RUNNING:
		m_tFrame.wstrObjectKey = L"Player_Run";
		hMemDC = CBmpMgr::GetInstance()->GetMemDC(m_tFrame.wstrObjectKey);
		m_tInfo.fWidth = PLAYER_RUN_WIDTH;
		m_tInfo.fHeight = PLAYER_RUN_HEIGHT;
		break;
	}

	CGameObj::UpdateRect();

	GdiTransparentBlt(hDC, int(m_tRect.left - CScrollMgr::XScroll), int(m_tRect.top - CScrollMgr::YScroll),
		int(m_tInfo.fWidth*0.5f), int(m_tInfo.fHeight*0.5f), hMemDC,
		m_tFrame.iCol*m_tInfo.fWidth, m_tFrame.iRow*m_tInfo.fHeight,
		m_tInfo.fWidth, m_tInfo.fHeight, RGB(255, 255, 255));
}

void CPlayer::Release()
{
}

void CPlayer::KeyInput()
{
	//아무것도 입력하지 않았을 시
	m_tFrame.eState = STATE_IDLE;

	if (CKeyMgr::GetInstance()->KeyPressing(KEY_LEFT))
	{
		m_tFrame.eState = STATE_RUNNING;

		if (CKeyMgr::GetInstance()->KeyPressing(KEY_UP))
			m_tFrame.eDir = DIR_LEFT_UP;
		else if (CKeyMgr::GetInstance()->KeyPressing(KEY_DOWN))
			m_tFrame.eDir = DIR_DOWN_LEFT;
		else
			m_tFrame.eDir = DIR_LEFT;
	}

	if (CKeyMgr::GetInstance()->KeyPressing(KEY_RIGHT))
	{
		m_tFrame.eState = STATE_RUNNING;

		if (CKeyMgr::GetInstance()->KeyPressing(KEY_UP))
			m_tFrame.eDir = DIR_UP_RIGHT;
		else if (CKeyMgr::GetInstance()->KeyPressing(KEY_DOWN))
			m_tFrame.eDir = DIR_RIGHT_DOWN;
		else
			m_tFrame.eDir = DIR_RIGHT;
	}


	if (CKeyMgr::GetInstance()->KeyPressing(KEY_UP))
	{
		m_tFrame.eState = STATE_RUNNING;

		if (CKeyMgr::GetInstance()->KeyPressing(KEY_LEFT))
			m_tFrame.eDir = DIR_LEFT_UP;
		else if (CKeyMgr::GetInstance()->KeyPressing(KEY_RIGHT))
			m_tFrame.eDir = DIR_UP_RIGHT;
		else
			m_tFrame.eDir = DIR_UP;
	}


	if (CKeyMgr::GetInstance()->KeyPressing(KEY_DOWN))
	{
		m_tFrame.eState = STATE_RUNNING;

		if (CKeyMgr::GetInstance()->KeyPressing(KEY_LEFT))
			m_tFrame.eDir = DIR_DOWN_LEFT;
		else if (CKeyMgr::GetInstance()->KeyPressing(KEY_RIGHT))
			m_tFrame.eDir = DIR_RIGHT_DOWN;
		else
			m_tFrame.eDir = DIR_DOWN;
	}
}

void CPlayer::Moving()
{
	if (m_tFrame.eState == STATE_RUNNING)
	{
		switch (m_tFrame.eDir)
		{
		case DIR_UP:
			m_tInfo.fY -= m_tInfo.fYSpeed;
			CScrollMgr::YScroll -= m_tInfo.fYSpeed;
			break;
		case DIR_UP_RIGHT:
			m_tInfo.fY -= m_tInfo.fYSpeed / ROOT2;
			CScrollMgr::YScroll -= m_tInfo.fYSpeed / ROOT2;
			m_tInfo.fX += m_tInfo.fXSpeed / ROOT2;
			CScrollMgr::XScroll += m_tInfo.fXSpeed / ROOT2;
			break;
		case DIR_RIGHT:
			m_tInfo.fX += m_tInfo.fXSpeed;
			CScrollMgr::XScroll += m_tInfo.fXSpeed;
			break;
		case DIR_RIGHT_DOWN:
			m_tInfo.fY += m_tInfo.fYSpeed / ROOT2;
			CScrollMgr::YScroll += m_tInfo.fYSpeed / ROOT2;
			m_tInfo.fX += m_tInfo.fXSpeed / ROOT2;
			CScrollMgr::XScroll += m_tInfo.fXSpeed / ROOT2;
			break;
		case DIR_DOWN:
			m_tInfo.fY += m_tInfo.fYSpeed;
			CScrollMgr::YScroll += m_tInfo.fYSpeed;
			break;
		case DIR_DOWN_LEFT:
			m_tInfo.fY += m_tInfo.fYSpeed / ROOT2;
			CScrollMgr::YScroll += m_tInfo.fYSpeed / ROOT2;
			m_tInfo.fX -= m_tInfo.fXSpeed / ROOT2;
			CScrollMgr::XScroll -= m_tInfo.fXSpeed / ROOT2;
			break;
		case DIR_LEFT:
			m_tInfo.fX -= m_tInfo.fXSpeed;
			CScrollMgr::XScroll -= m_tInfo.fXSpeed;
			break;
		case DIR_LEFT_UP:
			m_tInfo.fY -= m_tInfo.fYSpeed / ROOT2;
			CScrollMgr::YScroll -= m_tInfo.fYSpeed / ROOT2;
			m_tInfo.fX -= m_tInfo.fXSpeed / ROOT2;
			CScrollMgr::XScroll -= m_tInfo.fXSpeed / ROOT2;
			break;
		}
	}
}

void CPlayer::IsFrame()
{
	m_tFrame.dwCurTime = GetTickCount();

	m_tFrame.iRow = m_tFrame.eDir;

	if (m_tFrame.dwCurTime - m_tFrame.dwOldTime >= m_tFrame.dwFrameSpeed)
		m_tFrame.iCol += 1;

	if (m_tFrame.iCol > m_tFrame.iFrameCount)
		m_tFrame.iCol = 0;
}
