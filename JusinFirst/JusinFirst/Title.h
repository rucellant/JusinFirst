#pragma once
#include "Scene.h"

class CTitle : public CScene
{
public:
	CTitle();
	virtual ~CTitle();

public:
	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;

private:
	virtual void Release() override;
};

