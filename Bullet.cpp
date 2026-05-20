#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Player.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hModel_(-1)

{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("missile.fbx");
	assert(hModel_ >= 0);
	trB_.position_ = { 0.0f,-3.0f,0.0f };       //位置、ポジション
	trB_.scale_ = { 0.1f,0.1f,0.3f };           //大きさ
	trB_.rotate_ = { 0.0f,0.0f,0.0f }; //回転
}

void Bullet::Update()
{
	//弾の移動
	trB_.position_.z += 0.07;


	//弾の回転
	trB_.rotate_.z += 4;

	if (trB_.position_.z < 0.03) {
		//自分を消す
	}
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, trB_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
