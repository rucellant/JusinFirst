#include "stdafx.h"
#include "Scene.h"


CScene::CScene()
{
}


CScene::~CScene()
{
}

void CScene::DrawTileLine(HDC hDC)
{
	fLineX = 0.f;
	fLineY = 0.f;

	if (isDrawLine)
	{
		while (fLineX - CScrollMgr::XScroll <= GAMECX)
		{
			MoveToEx(hDC, int(fLineX - CScrollMgr::XScroll), int(-CScrollMgr::YScroll), nullptr);
			LineTo(hDC, int(fLineX - CScrollMgr::XScroll), int(GAMECY - CScrollMgr::YScroll));
			fLineX += 32.f;
		}

		while (fLineY - CScrollMgr::YScroll <= GAMECY)
		{
			MoveToEx(hDC, int(-CScrollMgr::XScroll), int(fLineY - CScrollMgr::YScroll), nullptr);
			LineTo(hDC, int(GAMECX - CScrollMgr::XScroll), int(fLineY - CScrollMgr::YScroll));
			fLineY += 32.f;
		}
	}
}

	void CScene::ToggleLineState()
{
	if (isDrawLine)
		isDrawLine = false;
	else
		isDrawLine = true;
}
