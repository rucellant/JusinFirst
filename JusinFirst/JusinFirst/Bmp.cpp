#include "stdafx.h"
#include "Bmp.h"


CBmp::CBmp()
{
}


CBmp::~CBmp()
{
}

void CBmp::LoadBmp(const wstring & wstrFilePath)
{
	m_hBitmap = (HBITMAP)LoadImage(nullptr, wstrFilePath.c_str(), IMAGE_BITMAP,
		0, 0, LR_CREATEDIBSECTION || LR_LOADFROMFILE);

	HDC hDC = GetDC(g_hWnd);
	m_hMemDC = CreateCompatibleDC(hDC);
	ReleaseDC(g_hWnd, hDC);

	m_hOldbmp = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);
}

HDC CBmp::GetMemDC() const
{
	return m_hMemDC;
}

void CBmp::Release()
{
	SelectObject(m_hMemDC, m_hOldbmp);
	DeleteDC(m_hMemDC);
	DeleteObject(m_hBitmap);
}
