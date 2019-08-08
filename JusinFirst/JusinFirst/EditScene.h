#pragma once
#include "Scene.h"

class CEditScene : public CScene
{
public:
	CEditScene();
	virtual ~CEditScene();

public:
	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	
private:
	virtual void Release() override;
};

