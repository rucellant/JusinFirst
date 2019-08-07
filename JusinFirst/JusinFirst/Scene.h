#pragma once
class CScene
{
protected:
	bool isDrawLine;
	float fLineX;
	float fLineY;

public:
	CScene();
	virtual ~CScene();

public:
	virtual void Initialize() = 0;
	virtual int Update() = 0;
	virtual void Render(HDC hDC) = 0;

private:
	virtual void Release() = 0;

public:
	void DrawTileLine(HDC hDC);
	void ToggleLineState();
};