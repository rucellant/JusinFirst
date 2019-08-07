#include "stdafx.h"
#include "Title.h"


CTitle::CTitle()
{
}


CTitle::~CTitle()
{
	Release();
}

void CTitle::Initialize()
{
	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Title/Title_Background.bmp", L"Title_Background");
	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Title/Title_Logo.bmp", L"Title_Logo");
}

int CTitle::Update()
{
	if (CKeyMgr::GetInstance()->KeyDown(KEY_SPACE))
	{
		CSceneMgr::GetInstance()->ChangeScene(SCENE_STAGE);
		return 0;
	}

	if (CKeyMgr::GetInstance()->KeyDown(KEY_ESCAPE))
		DestroyWindow(g_hWnd);

	return 0;
}

void CTitle::Render(HDC hDC)
{
	HDC hMemDC = CBmpMgr::GetInstance()->GetMemDC(L"Title_Background");
	BitBlt(hDC, 0, 0, GAMECX, GAMECY, hMemDC, 0, 0, SRCCOPY);

	hMemDC = CBmpMgr::GetInstance()->GetMemDC(L"Title_Logo");
	GdiTransparentBlt(hDC, int(GAMECX*0.5f - 211), int(GAMECY*0.2f), 422, 76,
		hMemDC, 0, 0, 422, 76, RGB(255, 255, 255));
}

void CTitle::Release()
{
}
