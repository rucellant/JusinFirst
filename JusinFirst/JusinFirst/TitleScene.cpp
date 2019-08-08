#include "stdafx.h"
#include "TitleScene.h"
#include "TitleButton.h"


CTitleScene::CTitleScene()
{
}


CTitleScene::~CTitleScene()
{
	Release();
}

void CTitleScene::Initialize()
{
	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Title/Title_Background.bmp", L"Title_Background");
	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Title/Title_Logo.bmp", L"Title_Logo");

	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Title/Title_Start.bmp", L"Title_Start");
	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Title/Title_Edit.bmp", L"Title_Edit");
	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Title/Title_Exit.bmp", L"Title_Exit");

	CGameObj* pObj = CAbstractFactory<CTitleButton>::
		CreateObj(GAMECX*0.4f, GAMECY*0.4f, L"Title_Start");
	CObjMgr::GetInstance()->AddObj(TYPE_UI, pObj);

	pObj = CAbstractFactory<CTitleButton>::
		CreateObj(GAMECX*0.4f, GAMECY*0.4f + 83.f, L"Title_Edit");
	CObjMgr::GetInstance()->AddObj(TYPE_UI, pObj);

	pObj = CAbstractFactory<CTitleButton>::
		CreateObj(GAMECX*0.4f, GAMECY*0.4f + 83.f * 2, L"Title_Exit");
	CObjMgr::GetInstance()->AddObj(TYPE_UI, pObj);
}

int CTitleScene::Update()
{
	if (CKeyMgr::GetInstance()->KeyDown(KEY_1))
		CSceneMgr::GetInstance()->SetSceneState(SCENE_EDIT);
	else if (CKeyMgr::GetInstance()->KeyDown(KEY_ESCAPE))
		DestroyWindow(g_hWnd);
	else {}

	CObjMgr::GetInstance()->Update();

	return 0;
}

void CTitleScene::Render(HDC hDC)
{
	HDC hMemDC = CBmpMgr::GetInstance()->GetMemDC(L"Title_Background");
	StretchBlt(hDC, 0, 0, GAMECX, GAMECY, hMemDC, 0, 0, 1920, 1080, SRCCOPY);

	hMemDC = CBmpMgr::GetInstance()->GetMemDC(L"Title_Logo");
	GdiTransparentBlt(hDC, int(GAMECX*0.5f - 211), int(GAMECY*0.2f), 422, 76,
		hMemDC, 0, 0, 422, 76, RGB(255, 255, 255));

	CObjMgr::GetInstance()->Render(hDC);
}

void CTitleScene::Release()
{
	CObjMgr::GetInstance()->ReleaseGroup(TYPE_UI);
}
