#pragma once

class CBmp
{
private:
	HDC m_hMemDC;

	HBITMAP m_hBitmap;
	HBITMAP m_hOldbmp;

public:
	CBmp();
	~CBmp();

public:
	void LoadBmp(const wstring& wstrFilePath);

	HDC GetMemDC() const;

private:
	void Release();
};

