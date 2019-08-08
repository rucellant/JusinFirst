#pragma once

typedef struct tagInfo
{
	float fX;			//x좌표
	float fY;			//y좌표

	float fXSpeed;		//x좌표 속도
	float fYSpeed;		//y좌표 속도

	float fWidth;		//너비
	float fHeight;		//높이
	
	bool bIsDead;		//생사여부
}INFO;

typedef struct tagFrame
{
	int iCol;				//프레임 열	
	int iRow;				//프레임 행
	int iFrameCount;		//프레임 갯수

	wstring wstrObjectKey;	//프레임 키

	DWORD dwOldTime;		//현재 시간
	DWORD dwCurTime;		//예전 시간
	DWORD dwFrameSpeed;		//프레임 재생 속도

	OBJ_STATE eState;		//상태
	OBJ_DIRECTION eDir;		//방향
}FRAME;

typedef struct tagTileInfo
{
	float fX;				//x좌표
	float fY;				//y좌표

	float fWidth;			//너비
	float fHeight;			//높이

	int iDrawID;			//타일번호
	int iOption;			//옵션

	bool bCanStand;			//플에이어가 갈 수 있으면 true
}TILE_INFO;