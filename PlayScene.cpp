#include "PlayScene.h"
#include "Engine/Model.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Engine/SceneManager.h"
#include "Engine/Camera.h"

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
	Instantiate<Enemy>(this);
	Instantiate<Enemy>(this);
	Instantiate<Enemy>(this);
	Instantiate<Enemy>(this);

	time = 0;

	Camera::SetPosition(XMFLOAT3(0.0f,5.0f,-10.0f));
	Camera::SetTarget(XMFLOAT3(0.0f, 0.0f, 10.0f));
}

void PlayScene::Update()
{
	time++;

	if (FindObject("Enemy") == nullptr)
	{
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);

	}

	if (time >= 150)
	{
		Instantiate<Enemy>(this);
		time = 0;
	}
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}