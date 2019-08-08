#pragma once

class CGameObj;

class CObjMgr
{
DECLARE_SINGLETON(CObjMgr)

private:
	OBJLIST m_ObjList[TYPE_END];		// list<CGameObj*> == OBJLIST

	int m_iEvent;

private:
	CObjMgr();
	~CObjMgr();

public:
	void AddObj(OBJ_TYPE eType, CGameObj* pObj);
	void Update();
	void Render(HDC hDC);

private:
	void Release();

public:
	void ReleaseGroup(OBJ_TYPE eObjType);
};

