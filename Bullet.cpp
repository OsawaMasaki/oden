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
	trB_.position_ = { trB_.position_.x,-3.0f,0.0f };       //位置、ポジション
	trB_.scale_ = { 0.1f,0.1f,0.3f };           //大きさ
	trB_.rotate_ = { 0.0f,0.0f,trB_.rotate_.z }; //回転
}

void Bullet::Update()
{
	//弾の移動
	trB_.position_.x += 5;

	//弾の回転
	trB_.rotate_.z += 4;
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, trB_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
