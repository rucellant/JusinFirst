#include "stdafx.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "TitleScene.h"
#include "EditScene.h"
#include "StageScene.h"


IMPLEMENT_SINGLETON(CSceneMgr)


CSceneMgr::CSceneMgr()
	:m_pCurrentScene(nullptr), m_eCurSceneType(SCENE_END), m_eNextSceneType(SCENE_TITLE)
{
}


CSceneMgr::~CSceneMgr()
{
	Release();
}

void CSceneMgr::SceneChange()
{
	if (m_eCurSceneType == m_eNextSceneType)
		return;

	m_eCurSceneType = m_eNextSceneType;
	
	SAFE_RELEASE(m_pCurrentScene);

	switch (m_eCurSceneType)
	{
	case SCENE_TITLE:
		m_pCurrentScene = new CTitleScene;
		break;
	case SCENE_EDIT:
		m_pCurrentScene = new CEditScene;
		break;
	case SCENE_STAGE:
		m_pCurrentScene = new CStageScene;
		break;
	case SCENE_END:
		m_pCurrentScene = nullptr;
		break;
	}

	if (m_pCurrentScene != nullptr)
		m_pCurrentScene->Initialize();
}

void CSceneMgr::Update()
{
	m_pCurrentScene->Update();
}

void CSceneMgr::Render(HDC hDC)
{
	m_pCurrentScene->Render(hDC);
}

void CSceneMgr::Release()
{
	SAFE_RELEASE(m_pCurrentScene);
}

void CSceneMgr::SetSceneState(SCENE_TYPE eSceneType)
{
	m_eNextSceneType = eSceneType;
}
