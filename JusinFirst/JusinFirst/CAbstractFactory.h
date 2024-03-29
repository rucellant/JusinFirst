#pragma once

class CGameObj;

template<typename T>
class CAbstractFactory
{
public:
	static CGameObj* CreateObj()
	{
		CGameObj* pObj = new T;
		pObj->Initialize();

		return pObj;
	}

	static CGameObj* CreateObj(const float _fX, const float _fY)
	{
		CGameObj* pObj = new T;
		pObj->Initialize();
		pObj->SetPos(_fX, _fY);

		return pObj;
	}

	static CGameObj* CreateObj(const float _fX, const float _fY, const wstring& wstrObjectKey)
	{
		CGameObj* pObj = new T;
		pObj->SetPos(_fX, _fY);
		pObj->Initialize();
		pObj->SetObjectKey(wstrObjectKey);

		return pObj;
	}
};