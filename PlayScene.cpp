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
	// 動きの速さを調節するためのタイマー
	static float timer = 0.0f;
	timer += 0.05f; // ここを大きくすると速くなる

	// 振幅
	float amplitude = 2.0f;

	// 座標の設定
	// sin関数は -1.0 〜 1.0 の間で変化
	ot_.position_.x = sinf(timer) * amplitude;
	ot_.position_.y = 0.0f;
	ot_.position_.z = 0.0f;

	// スケールと回転
	ot_.scale_ = { 0.5f, 0.5f, 0.5f };
	ot_.rotate_.y += 0.1f;
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
