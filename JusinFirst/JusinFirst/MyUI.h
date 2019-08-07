#pragma once
#include "GameObj.h"

class CMyUI : public CGameObj
{
private:
	CGameObj* m_pPlayer;

public:
	CMyUI();
	virtual ~CMyUI();

public:
	// CGameObj��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	
private:
	virtual void Release() override;
};

