#pragma once
#include "GameObj.h"
class CTitleButton : public CGameObj
{
public:
	CTitleButton();
	virtual ~CTitleButton();

public:
	// CGameObj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	
private:
	virtual void Release() override;

private:
	void isPicking();
};

