#pragma once

class CGameObj;

class CObjMgr
{
DECLARE_SINGLETON(CObjMgr)

private:
	CObjMgr();
	~CObjMgr();

private:
	OBJLIST m_ObjList[TYPE_END];
	int m_iEvent;

public:
	void Update();
	void Render(HDC hDC);

private:
	void Release();

public:
	void AddObj(OBJ_TYPE eType, CGameObj* _pObj);

	void ReleaseGroup(OBJ_TYPE eType);

public:
	CGameObj* GetPlayer() const;
};

