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

	// 動きの速さを調節するためのタイマー
	static float rot = 0.0f;

	rot += 0.0f;    //回る速さ


	// 座標の設定
	// sin関数は -1.0 〜 1.0 の間で変化
	float posx;
	float posy;
	randamx = rand() % 10;
	randamy = rand() % 5;
	posx = randamx;
	posy = randamy;
	transform_.position_ = { posx - 5,posy, 30.0f};
}

void Enemy::Update()
{
	// 振幅 amplitude
	float ampy = 1.5f;
	float ampx = 6.0f;
	timer += 0.02f; //移動する速さ

	// スケールと回転
	transform_.scale_ = { 0.5f, 0.5f, 0.5f };
	transform_.rotate_ = { 0.0f, 180.0f, 0.0f };
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