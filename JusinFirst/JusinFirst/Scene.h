#pragma once
class CScene
{
public:
	CScene();
	virtual ~CScene();

public:
	virtual void Initialize() = 0;
	virtual int Update() = 0;
	virtual void Render(HDC hDC) = 0;

private:
	virtual void Release() = 0;
};