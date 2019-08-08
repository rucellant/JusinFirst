#include "stdafx.h"
#include "ObjMgr.h"
#include "GameObj.h"

IMPLEMENT_SINGLETON(CObjMgr)


CObjMgr::CObjMgr()
	:m_iEvent(0)
{
}


CObjMgr::~CObjMgr()
{
	Release();
}

void CObjMgr::Update()
{
	m_iEvent = NO_EVENT;

	for (int i = 0; i < TYPE_END; i++)
	{
		OBJLIST::iterator iter_Begin	= m_ObjList[i].begin();
		OBJLIST::iterator iter_End		= m_ObjList[i].end();

		for (; iter_Begin != iter_End;)
		{
			m_iEvent = (*iter_Begin)->Update();

			if (m_iEvent == OBJ_DEAD)
			{
				SAFE_RELEASE(*iter_Begin);
				iter_Begin = m_ObjList[i].erase(iter_Begin);
			}
			else if (m_iEvent == SCENE_CHANGE)
				return;
			else
				++iter_Begin;
		}
	}
}

void CObjMgr::Render(HDC hDC)
{
	for (int i = 0; i < TYPE_END; i++)
	{
		OBJLIST::iterator iter_Begin = m_ObjList[i].begin();
		OBJLIST::iterator iter_End = m_ObjList[i].end();

		for (; iter_Begin != iter_End; ++iter_Begin)
			(*iter_Begin)->Render(hDC);
	}
}

void CObjMgr::Release()
{
	for (int i = 0; i < TYPE_END; i++)
	{
		OBJLIST::iterator iter_Begin = m_ObjList[i].begin();
		OBJLIST::iterator iter_End = m_ObjList[i].end();

		for (; iter_Begin != iter_End; ++iter_Begin)
			SAFE_RELEASE(*iter_Begin);
		
		m_ObjList[i].clear();
	}
}

void CObjMgr::AddObj(OBJ_TYPE eType, CGameObj * _pObj)
{
	m_ObjList[eType].push_back(_pObj);
}

void CObjMgr::ReleaseGroup(OBJ_TYPE eType)
{
	OBJLIST::iterator iter = m_ObjList[eType].begin();

	for (; iter != m_ObjList[eType].end(); ++iter)
		SAFE_RELEASE(*iter);

	m_ObjList[eType].clear();
}

CGameObj * CObjMgr::GetPlayer() const
{
	return m_ObjList[TYPE_PLAYER].front();
}
