#pragma once

class CGameObj
{
protected:
	INFO	m_tInfo;
	RECT	m_tRect;
	FRAME	m_tFrame;

public:
	CGameObj();
	virtual ~CGameObj();

public:
	virtual void Initialize() = 0;
	virtual int Update() = 0;
	virtual void Render(HDC hDC) = 0;

protected:
	virtual void Release() = 0;

public:
	void UpdateRect();

public:
	//Get
	INFO	GetInfo() const;
	RECT	GetRect() const;
	FRAME	GetFrame() const;

	//Set
	void SetXPos(const float _fX);
	void SetYPos(const float _fY);
	void SetPos(const float _fX, const float _fY);
	void SetXSpeed(const float _fXSpeed);
	void SetYSpeed(const float _fYSpeed);
	void SetSpeed(const float _fXSpeed, const float _fYSpeed);
	void SetWidth(const float _fWidth);
	void SetHeight(const float _fHeight);
	void SetIsDead(const bool _bIsDead);
	void SetState(const OBJ_STATE _eState);
	void SetCol(int _iCol);
	void SetRow(int _iRow);
	void SetObjectKey(const wstring& _wstrObjectKey);
};

