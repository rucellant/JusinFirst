#pragma once
#include "Scene.h"

class MyEdit : public CScene
{
public:
	MyEdit();
	virtual ~MyEdit();

public:
	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;

private:
	virtual void Release() override;
};

