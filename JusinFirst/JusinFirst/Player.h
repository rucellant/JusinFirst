#pragma once
#include "GameObj.h"

class CPlayer : public CGameObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	// CGameObj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	
private:
	virtual void Release() override;

private:
	void KeyInput();
	void Moving();
	void IsFrame();
};

