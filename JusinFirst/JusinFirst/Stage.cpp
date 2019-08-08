#include "stdafx.h"
#include "Stage.h"
#include "Player.h"


CStage::CStage()
{
}


CStage::~CStage()
{
	Release();
}

void CStage::Initialize()
{
	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Player/3065.bmp", L"Stage");
	CGameObj* pObj = CAbstractFactory<CPlayer>::CreateObj();
	CObjMgr::GetInstance()->AddObj(TYPE_PLAYER, pObj);

	isDrawLine = false;
	fLineX = 0.f;
	fLineY = 0.f;
}

int CStage::Update()
{
	CObjMgr::GetInstance()->Update();

	if (CKeyMgr::GetInstance()->KeyDown(KEY_ESCAPE))
		DestroyWindow(g_hWnd);

	if (CKeyMgr::GetInstance()->KeyDown(KEY_E))
		ToggleLineState();

	return 0;
}

void CStage::Render(HDC hDC)
{
	HDC hMemDC = CBmpMgr::GetInstance()->GetMemDC(L"Stage");
	BitBlt(hDC, 0, 0, GAMECX, GAMECY, hMemDC, 0, 0, SRCCOPY);
	
	CObjMgr::GetInstance()->Render(hDC);

	DrawTileLine(hDC);
}

void CStage::Release()
{
}
