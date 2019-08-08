#include "stdafx.h"
#include "StageScene.h"


CStageScene::CStageScene()
{
}


CStageScene::~CStageScene()
{
}

void CStageScene::Initialize()
{
	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Edit/Edit_Background.bmp", L"Edit_Background");
}

int CStageScene::Update()
{
	return 0;
}

void CStageScene::Render(HDC hDC)
{
	HDC hMemDC = CBmpMgr::GetInstance()->GetMemDC(L"Edit_Background");
	BitBlt(hDC, 0, 0, GAMECX, GAMECY, hMemDC, 0, 0, SRCCOPY);
}

void CStageScene::Release()
{
}
