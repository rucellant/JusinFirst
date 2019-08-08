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

void CObjMgr::AddObj(OBJ_TYPE eType, CGameObj * pObj)
{
	//각각의 객체로 분류하여 포인터 리스트에 담는다.
	m_ObjList[eType].push_back(pObj);
}

void CObjMgr::Update()
{
	m_iEvent = NO_EVENT;

	for (int i = 0; i < TYPE_END; i++)
	{
		OBJLIST::iterator iter_Begin = m_ObjList[i].begin();
		OBJLIST::iterator iter_End = m_ObjList[i].end();

		for (; iter_Begin != iter_End;)
		{
			//Update의 결과로 나온 이벤트를 담는다
			m_iEvent = (*iter_Begin)->Update();

			//업데이트의 결과에 따라서 각각의 객체들을 다르게 후속 처리한다.
			if (m_iEvent == OBJ_DEAD)
			{
				SAFE_RELEASE(*iter_Begin);
				iter_Begin = m_ObjList[i].erase(iter_Begin);
			}
			//씬의 변경이 발생할 경우 객체의 업데이트 함수는 SCENE_CHANGE를 반환하고 
			//씬의 NextSceneState를 변경함으로서 Delete this를 없앤다.
			else if (m_iEvent == SCENE_CHANGE)
				return;
			else
				++iter_Begin;
		}
	}

}

void CObjMgr::Render(HDC hDC)
{
	//씬 체인지가 일어났으면 바로 종료한다.
	if (m_iEvent == SCENE_CHANGE)
		return;

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

		for (; iter_Begin != iter_End;)
			SAFE_RELEASE(*iter_Begin);

		m_ObjList[i].clear();
	}
}

void CObjMgr::ReleaseGroup(OBJ_TYPE eObjType)
{
	OBJLIST::iterator iter = m_ObjList[eObjType].begin();

	for (; iter != m_ObjList[eObjType].end(); ++iter)
		SAFE_RELEASE(*iter);

	m_ObjList[eObjType].clear();
}
