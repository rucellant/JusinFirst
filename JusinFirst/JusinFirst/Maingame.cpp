#include "stdafx.h"
#include "Maingame.h"


CMaingame::CMaingame()
{
}


CMaingame::~CMaingame()
{
	Release();
}

void CMaingame::Initialize()
{
	m_hDC = GetDC(g_hWnd);

	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Backbuffer/Backbuffer.bmp", L"Backbuffer");
	
	CSceneMgr::GetInstance()->ChangeScene(SCENE_TITLE);
}

void CMaingame::Update()
{
	CKeyMgr::GetInstance()->Update();
	CSceneMgr::GetInstance()->Update();
}

void CMaingame::Render()
{
	HDC hBackbuffer = CBmpMgr::GetInstance()->GetMemDC(L"Backbuffer");

	CSceneMgr::GetInstance()->Render(hBackbuffer);

	BitBlt(m_hDC, 0, 0, GAMECX, GAMECY, hBackbuffer, 0, 0, SRCCOPY);
	//GdiTransparentBlt(m_hDC, 0, 0, GAMECX, GAMECY, hBackbuffer, 0, 0, GAMECX, GAMECY, RGB(255, 255, 255));
}

void CMaingame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);
	CKeyMgr::GetInstance()->DestroyInstance();
	CObjMgr::GetInstance()->DestroyInstance();
	CBmpMgr::GetInstance()->DestroyInstance();
	CSceneMgr::GetInstance()->DestroyInstance();
}
