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
}

void CMaingame::Update()
{
}

void CMaingame::Render()
{
}

void CMaingame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);
}
