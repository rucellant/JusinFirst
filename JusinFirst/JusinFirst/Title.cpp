#include "stdafx.h"
#include "Title.h"
#include "TitleButton.h"


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

	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Title/Title_Start.bmp", L"Title_Start");
	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Title/Title_Edit.bmp", L"Title_Edit");
	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Title/Title_Exit.bmp", L"Title_Exit");

	CGameObj* pButton = CAbstractFactory<CTitleButton>::
		CreateObj(GAMECX*0.5f, GAMECY*0.5f, L"Title_Start");
	CObjMgr::GetInstance()->AddObj(TYPE_UI, pButton);

	pButton = CAbstractFactory<CTitleButton>::
		CreateObj(GAMECX*0.5f, GAMECY*0.5f + TITLE_UI_HEIGHT, L"Title_Edit");
	CObjMgr::GetInstance()->AddObj(TYPE_UI, pButton);

	pButton = CAbstractFactory<CTitleButton>::
		CreateObj(GAMECX*0.5f, GAMECY*0.5f + TITLE_UI_HEIGHT * 2, L"Title_Exit");
	CObjMgr::GetInstance()->AddObj(TYPE_UI, pButton);
}

int CTitle::Update()
{
	if (CKeyMgr::GetInstance()->KeyDown(KEY_SPACE))
	{
		CSceneMgr::GetInstance()->ChangeScene(SCENE_STAGE);
		return SCENE_CHANGE;
	}

	CObjMgr::GetInstance()->Update();

	return 0;
}

void CTitle::Render(HDC hDC)
{
	HDC hMemDC = CBmpMgr::GetInstance()->GetMemDC(L"Title_Background");

	StretchBlt(hDC, 0, 0, GAMECX, GAMECY, hMemDC, 0, 0, 1920, 1080, SRCCOPY);

	hMemDC = CBmpMgr::GetInstance()->GetMemDC(L"Title_Logo");
	GdiTransparentBlt(hDC, int(GAMECX*0.5f - 211), int(GAMECY*0.2f), 422, 76,
		hMemDC, 0, 0, 422, 76, RGB(255, 255, 255));

	CObjMgr::GetInstance()->Render(hDC);
}

void CTitle::Release()
{
	CObjMgr::GetInstance()->ReleaseGroup(TYPE_UI);
}
