#pragma once

#define GAMECX	1280
#define GAMECY	720

#define NO_EVENT		0
#define OBJ_DEAD		1
#define SCENE_CHANGE	2


/////////////////////////////////////////////////////////////////

#define DECLARE_SINGLETON(ClassName)	\
public:									\
static ClassName* GetInstance();		\
void DestroyInstance();					\
private:								\
	static ClassName* m_pInstance;

#define IMPLEMENT_SINGLETON(ClassName)			\
ClassName* ClassName::m_pInstance = nullptr;	\
ClassName* ClassName::GetInstance()				\
{												\
	if (nullptr == m_pInstance)					\
		m_pInstance = new ClassName;			\
	return m_pInstance;							\
}												\
void ClassName::DestroyInstance()				\
{												\
	if (m_pInstance)							\
	{											\
		delete m_pInstance;						\
		m_pInstance = nullptr;					\
	}											\
}