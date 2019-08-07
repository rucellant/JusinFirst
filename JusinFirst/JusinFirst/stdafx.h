// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.

//standard header
#include <vector>
#include <list>
#include <map>

using namespace std;

//user header
#include "Define.h"
#include "Extern.h"
#include "Enum.h"
#include "Struct.h"
#include "Constants.h"
#include "Function.h"
#include "Typedef.h"


//mgr header
#include "CAbstractFactory.h"
#include "KeyMgr.h"
#include "ObjMgr.h"
#include "BmpMgr.h"
#include "SceneMgr.h"
#include "UIMgr.h"
#include "ScrollMgr.h"


//visual leak detector
#include "vld.h"