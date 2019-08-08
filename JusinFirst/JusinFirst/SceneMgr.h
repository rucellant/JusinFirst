#pragma once

class CScene;

class CSceneMgr
{
DECLARE_SINGLETON(CSceneMgr)

private:
	CScene* m_pCurrentScene;

	SCENE_TYPE m_eCurSceneType;
	SCENE_TYPE m_eNextSceneType;

private:
	CSceneMgr();
	~CSceneMgr();

public:
	void SceneChange();

	void Update();
	void Render(HDC hDC);

private:
	void Release();

public:
	void SetSceneState(SCENE_TYPE eSceneType);
};

