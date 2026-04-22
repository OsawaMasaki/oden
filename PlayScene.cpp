#include "PlayScene.h"
#include "Engine/Model.h"

namespace
{
	
}


PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"),hModel_(-1)
{
}

void PlayScene::Initialize()
{
	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);
}

void PlayScene::Update()
{
	static float time = 0.1f;

	ot_.position_ = { 0.0f,0.0f,0.0f };
	ot_.scale_ = { 0.5f,0.5f,0.5f };
	ot_.rotate_.y += time;

	
	
}

void PlayScene::Draw()
{
	//static Transform ot;                                      //モデルの位置やむきなどを管理するオブジェクト(おでん用のトランスフォーム)
	Model::SetTransform(hModel_, ot_);
	Model::Draw(hModel_);
}

void PlayScene::Release()
{
}
