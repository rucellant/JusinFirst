#include "stdafx.h"
#include "EditScene.h"


CEditScene::CEditScene()
{
}


CEditScene::~CEditScene()
{
}

void CEditScene::Initialize()
{
	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Edit/Edit_Background.bmp", L"Edit_Background");
}

int CEditScene::Update()
{
	if (CKeyMgr::GetInstance()->KeyDown(KEY_1))
		CSceneMgr::GetInstance()->SetSceneState(SCENE_TITLE);
	else if (CKeyMgr::GetInstance()->KeyDown(KEY_ESCAPE))
		DestroyWindow(g_hWnd);
	else {}

	return SCENE_CHANGE;
}

void CEditScene::Render(HDC hDC)
{
	HDC hMemDC = CBmpMgr::GetInstance()->GetMemDC(L"Edit_Background");
	BitBlt(hDC, 0, 0, GAMECX, GAMECY, hMemDC, 0, 0, SRCCOPY);
}

void CEditScene::Release()
{
}
