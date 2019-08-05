#include "stdafx.h"
#include "BmpMgr.h"
#include "Bmp.h"


IMPLEMENT_SINGLETON(CBmpMgr)


CBmpMgr::CBmpMgr()
{
}


CBmpMgr::~CBmpMgr()
{
	Release();
}

void CBmpMgr::LoadBmp(const wstring & wstrFilePath, const wstring & wstrObjectKey)
{
	auto iter_Find = m_mapBmp.find(wstrObjectKey);

	if (iter_Find != m_mapBmp.end())
		return;

	CBmp* pBmp = new CBmp;
	pBmp->LoadBmp(wstrFilePath);

	m_mapBmp.insert({ wstrObjectKey,pBmp });
}

HDC CBmpMgr::GetMemDC(const wstring & wstrObjectKey) const
{
	auto iter_Find = m_mapBmp.find(wstrObjectKey);

	if (iter_Find == m_mapBmp.end())
		return nullptr;

	return iter_Find->second->GetMemDC();
}

void CBmpMgr::Release()
{
	map<wstring, CBmp*>::iterator iter;

	for (iter = m_mapBmp.begin(); iter != m_mapBmp.end(); ++iter)
		SAFE_RELEASE(iter->second);

	m_mapBmp.clear();
}
