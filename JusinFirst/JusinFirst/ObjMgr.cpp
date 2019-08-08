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
	//������ ��ü�� �з��Ͽ� ������ ����Ʈ�� ��´�.
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
			//Update�� ����� ���� �̺�Ʈ�� ��´�
			m_iEvent = (*iter_Begin)->Update();

			//������Ʈ�� ����� ���� ������ ��ü���� �ٸ��� �ļ� ó���Ѵ�.
			if (m_iEvent == OBJ_DEAD)
			{
				SAFE_RELEASE(*iter_Begin);
				iter_Begin = m_ObjList[i].erase(iter_Begin);
			}
			//���� ������ �߻��� ��� ��ü�� ������Ʈ �Լ��� SCENE_CHANGE�� ��ȯ�ϰ� 
			//���� NextSceneState�� ���������μ� Delete this�� ���ش�.
			else if (m_iEvent == SCENE_CHANGE)
				return;
			else
				++iter_Begin;
		}
	}

}

void CObjMgr::Render(HDC hDC)
{
	//�� ü������ �Ͼ���� �ٷ� �����Ѵ�.
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
