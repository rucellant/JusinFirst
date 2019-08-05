#pragma once

class CBmp;

class CBmpMgr
{
DECLARE_SINGLETON(CBmpMgr)

private:
	CBmpMgr();
	~CBmpMgr();

private:
	map<wstring, CBmp*> m_mapBmp;

public:
	void LoadBmp(const wstring& wstrFilePath, const wstring& wstrObjectKey);

	//Get
	HDC GetMemDC(const wstring& wstrObjectKey) const;

private:
	void Release();
};

