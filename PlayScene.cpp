#include "PlayScene.h"
#include "Engine/Model.h"
#include "Player.h"

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
	Instantiate<Player>(this);
}

void PlayScene::Update()
{
	// 動きの速さを調節するためのタイマー
	static float timer = 0.0f;
	static float rot   = 0.0f;
	timer += 0.03f; //移動する速さ
	rot   += 0.3f;  //回る速さ

	// 振幅 amplitude
	float ampx = 6.0f;
	float ampy = 1.5f;

	// 座標の設定
	// sin関数は -1.0 〜 1.0 の間で変化
	float posx;
	float posy;
	posx = sin(timer) * ampx;
	posy = cos(timer) * ampy;
	ot_.position_ = { posx,posy,10.0f };

	// スケールと回転
	ot_.scale_  = { 0.5f, 0.5f, 0.5f };
	ot_.rotate_ = {0.0f, rot, 0.0f};
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