#include "stdafx.h"
#include "GameObj.h"


CGameObj::CGameObj()
{
}


CGameObj::~CGameObj()
{
}

void CGameObj::UpdateRect()
{
	m_tRect.left	= LONG(m_tInfo.fX - 0.5f*m_tInfo.fWidth);
	m_tRect.right	= LONG(m_tInfo.fX + 0.5f*m_tInfo.fWidth);
	m_tRect.top		= LONG(m_tInfo.fY - 0.5f*m_tInfo.fHeight);
	m_tRect.bottom	= LONG(m_tInfo.fY + 0.5f*m_tInfo.fHeight);
}

INFO CGameObj::GetInfo() const
{
	return m_tInfo;
}

RECT CGameObj::GetRect() const
{
	return m_tRect;
}

FRAME CGameObj::GetFrame() const
{
	return m_tFrame;
}

void CGameObj::SetXPos(const float _fX)
{
	m_tInfo.fX = _fX;
}

void CGameObj::SetYPos(const float _fY)
{
	m_tInfo.fY = _fY;
}

void CGameObj::SetPos(const float _fX, const float _fY)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
}

void CGameObj::SetXSpeed(const float _fXSpeed)
{
	m_tInfo.fXSpeed = _fXSpeed;
}

void CGameObj::SetYSpeed(const float _fYSpeed)
{
	m_tInfo.fYSpeed = _fYSpeed;
}

void CGameObj::SetSpeed(const float _fXSpeed, const float _fYSpeed)
{
	m_tInfo.fXSpeed = _fXSpeed;
	m_tInfo.fYSpeed = _fYSpeed;
}

void CGameObj::SetWidth(const float _fWidth)
{
	m_tInfo.fWidth = _fWidth;
}

void CGameObj::SetHeight(const float _fHeight)
{
	m_tInfo.fHeight = _fHeight;
}

void CGameObj::SetIsDead(const bool _bIsDead)
{
	m_tInfo.bIsDead = _bIsDead;
}

void CGameObj::SetState(const OBJ_STATE _eState)
{
	m_tFrame.eState = _eState;
}

void CGameObj::SetCol(int _iCol)
{
	m_tFrame.iCol = _iCol;
}

void CGameObj::SetRow(int _iRow)
{
	m_tFrame.iRow = _iRow;
}

void CGameObj::SetObjectKey(const wstring & _wstrObjectKey)
{
	m_tFrame.wstrObjectKey = _wstrObjectKey;
}
