#include "stdafx.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Title.h"
#include "MyEdit.h"
#include "Stage.h"


IMPLEMENT_SINGLETON(CSceneMgr)


CSceneMgr::CSceneMgr()
	:m_eCurSceneType(SCENE_END), m_ePreSceneType(SCENE_END), m_pCurScene(nullptr)
{
}


CSceneMgr::~CSceneMgr()
{
	Release();
}

void CSceneMgr::ChangeScene(SCENE_TYPE eSceneType)
{
	m_eCurSceneType = eSceneType;

	if (m_ePreSceneType != m_eCurSceneType)
	{
		SAFE_RELEASE(m_pCurScene);

		switch (m_eCurSceneType)
		{
		case SCENE_TITLE:
			m_pCurScene = new CTitle;
			break;
		case SCENE_EDIT:
			m_pCurScene = new MyEdit;
			break;
		case SCENE_STAGE:
			m_pCurScene = new CStage;
			break;
		}

		m_pCurScene->Initialize();
		m_ePreSceneType = m_eCurSceneType;
	}
}

void CSceneMgr::Update()
{
	m_pCurScene->Update();
}

void CSceneMgr::Render(HDC hDC)
{
	m_pCurScene->Render(hDC);
}

void CSceneMgr::Release()
{
	SAFE_RELEASE(m_pCurScene);
}
