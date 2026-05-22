#include "PlayScene.h"
#include "Engine/Model.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Engine/SceneManager.h"

namespace
{
	
}


PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"),hModel_(-1)
{
}

void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	Instantiate<Enemy>(this);
	//Instantiate<Bullet>(this);

	time = 0;
}

void PlayScene::Update()
{
	if (FindObject("Enemy") == nullptr)
	{
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);

	}

	//time++;
	//if (time == 1000)
	//{
	//	Instantiate<Enemy>(this);
	//	time = 0;
	//}
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}