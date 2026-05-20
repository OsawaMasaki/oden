#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hModel_(-1)

{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("missile.fbx");
	assert(hModel_ >= 0);
	tr_.position_ = { 0.0f,-3.0f,0.0f };       //位置、ポジション
	tr_.scale_ = { 1.0f,1.0f,1.0f };                      //大きさ
}

void Bullet::Update()
{
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, tr_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
