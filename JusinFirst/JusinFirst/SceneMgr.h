#pragma once

class CScene;

class CSceneMgr
{
DECLARE_SINGLETON(CSceneMgr)

private:
	CSceneMgr();
	~CSceneMgr();

private:
	SCENE_TYPE m_eCurSceneType;
	SCENE_TYPE m_ePreSceneType;

	CScene* m_pCurScene;

public:
	void ChangeScene(SCENE_TYPE eSceneType);
	void Update();
	void Render(HDC hDC);

private:
	void Release();
};

