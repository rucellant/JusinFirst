#pragma once
#include "Scene.h"

class CStageScene : public CScene
{
public:
	CStageScene();
	virtual ~CStageScene();

public:
	// CScene을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	
private:
	virtual void Release() override;
};

