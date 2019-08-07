#pragma once


//키 입력 상수
const DWORD KEY_UP		= 0x00000001;
const DWORD KEY_DOWN	= 0x00000002;
const DWORD KEY_LEFT	= 0x00000004;
const DWORD KEY_RIGHT	= 0x00000008;
const DWORD KEY_SPACE	= 0x00000010;
const DWORD KEY_E		= 0x00000020;
const DWORD KEY_R		= 0x00000040;
const DWORD KEY_F		= 0x00000080;
const DWORD KEY_Z		= 0x00000100;
const DWORD KEY_Q		= 0x00000200;
const DWORD KEY_ALT		= 0x00000400;
const DWORD KEY_TAB		= 0x00000800;
const DWORD KEY_ESCAPE	= 0x00001000;
const DWORD KEY_SHIFT	= 0x00002000;
const DWORD KEY_1		= 0x00004000;
const DWORD KEY_2		= 0x00008000;
const DWORD KEY_3		= 0x00010000;
const DWORD KEY_4		= 0x00020000;
const DWORD KEY_5		= 0x00040000;

//플레이어 이미지 RECT 크기
const UINT PLAYER_IDLE_WIDTH	= 92;
const UINT PLAYER_IDLE_HEIGHT	= 116;
const UINT PLAYER_RUN_WIDTH		= 88;
const UINT PLAYER_RUN_HEIGHT	= 132;

//타일 이미지 RECT 크기
const UINT TILE_WIDTH	= 32;
const UINT TILE_HEIGHT	= 32;

//플레이어 방향

const int PLAYER_EAST			= 2;
const int PLAYER_EAST_NORTH		= 1;
const int PLAYER_NORTH			= 0;
const int PLAYER_NORTH_WEST		= 7;
const int PLAYER_WEST			= 6;
const int PLAYER_SOUTH_WEST		= 5;
const int PLAYER_SOUTH			= 4;
const int PLAYER_EAST_SOUTH		= 3;