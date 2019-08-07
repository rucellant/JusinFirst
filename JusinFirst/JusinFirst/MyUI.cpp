#include "stdafx.h"
#include "MyUI.h"


CMyUI::CMyUI()
	:m_pPlayer(nullptr)
{
}


CMyUI::~CMyUI()
{
	Release();
}

void CMyUI::Initialize()
{
}

int CMyUI::Update()
{
	return 0;
}

void CMyUI::Render(HDC hDC)
{
}

void CMyUI::Release()
{
}
