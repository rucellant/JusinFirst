#include "stdafx.h"
#include "TitleButton.h"


CTitleButton::CTitleButton()
{
}


CTitleButton::~CTitleButton()
{
	Release();
}

void CTitleButton::Initialize()
{
	m_tInfo.fWidth = TITLE_UI_WIDTH;
	m_tInfo.fHeight = TITLE_UI_HEIGHT;
	m_tInfo.bIsDead = false;

	m_tFrame.iCol = 0;
	m_tFrame.iRow = 0;

	CGameObj::UpdateRect();
}

int CTitleButton::Update()
{
	CGameObj::UpdateRect();

	POINT pt = {};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	if (PtInRect(&m_tRect, pt))
	{

		if (CKeyMgr::GetInstance()->KeyUp(KEY_LBUTTON))
		{
			if (!lstrcmp(L"Title_Start", m_tFrame.wstrObjectKey.c_str()))
			{
				CSceneMgr::GetInstance()->ChangeScene(SCENE_STAGE);
				return SCENE_CHANGE;
			}
			else if (!lstrcmp(L"Title_Edit", m_tFrame.wstrObjectKey.c_str()))
			{
				CSceneMgr::GetInstance()->ChangeScene(SCENE_EDIT);
				return SCENE_CHANGE;
			}
			else if (!lstrcmp(L"Title_Exit", m_tFrame.wstrObjectKey.c_str()))
			{
				DestroyWindow(g_hWnd);
				return SCENE_CHANGE;
			}
		}
		m_tFrame.iCol = 1;
	}
	else
		m_tFrame.iCol = 0;

	return NO_EVENT;
}

void CTitleButton::Render(HDC hDC)
{
	HDC hMemDC = CBmpMgr::GetInstance()->GetMemDC(m_tFrame.wstrObjectKey);

	BitBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fWidth, m_tInfo.fHeight,
		hMemDC, m_tFrame.iCol*m_tInfo.fWidth, 0, SRCCOPY);
}

void CTitleButton::Release()
{
}

void CTitleButton::isPicking()
{
	
}
