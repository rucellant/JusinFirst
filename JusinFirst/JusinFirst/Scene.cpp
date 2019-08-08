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
		while (fLineX <= GAMECX)
		{
			MoveToEx(hDC, fLineX, 0, nullptr);
			LineTo(hDC, fLineX, GAMECY);
			fLineX += 64.f;
		}

		while (fLineY <= GAMECY)
		{
			MoveToEx(hDC, 0, fLineY, nullptr);
			LineTo(hDC, GAMECX, fLineY);
			fLineY += 64.f;
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
