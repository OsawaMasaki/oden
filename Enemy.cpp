#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel_(-1)
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Enemy.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { transform_.position_.x,-3.0f,0.0f };       //位置、ポジション
	transform_.scale_ = { 0.5f,0.5f,0.5f };                      //大きさ
	SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 0.5f);
	AddCollider(collider);
}

void Enemy::Update()
{
	// 動きの速さを調節するためのタイマー
	static float timer = 0.0f;
	static float rot = 0.0f;
	timer += 0.03f; //移動する速さ
	rot += 0.3f;  //回る速さ

	// 振幅 amplitude
	float ampx = 6.0f;
	float ampy = 1.5f;

	// 座標の設定
	// sin関数は -1.0 〜 1.0 の間で変化
	float posx;
	float posy;
	posx = sin(timer) * ampx;
	posy = cos(timer) * ampy;
	transform_.position_ = { posx,posy,10.0f };

	// スケールと回転
	transform_.scale_ = { 0.5f, 0.5f, 0.5f };
	transform_.rotate_ = { 0.0f, rot, 0.0f };
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Bullet")
	{
		pTarget->KillMe();  
		KillMe();          
	}
}
