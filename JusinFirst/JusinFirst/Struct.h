#pragma once

typedef struct tagInfo
{
	float fX;			//x��ǥ
	float fY;			//y��ǥ

	float fXSpeed;		//x��ǥ �ӵ�
	float fYSpeed;		//y��ǥ �ӵ�

	float fWidth;		//�ʺ�
	float fHeight;		//����
	
	bool bIsDead;		//���翩��
}INFO;

typedef struct tagFrame
{
	int iCol;				//������ ��	
	int iRow;				//������ ��
	int iFrameCount;		//������ ����

	wstring wstrObjectKey;	//������ Ű

	DWORD dwOldTime;		//���� �ð�
	DWORD dwCurTime;		//���� �ð�
	DWORD dwFrameSpeed;		//������ ��� �ӵ�

	OBJ_STATE eState;		//����
}FRAME;