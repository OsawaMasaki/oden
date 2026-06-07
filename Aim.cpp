#include "Aim.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Player.h"

Aim::Aim(GameObject* parent)
	:GameObject(parent, "Aim"), hModel_(-1)
{
}

void Aim::Initialize()
{
	hModel_ = Model::Load("Aim.fbx");
	assert(hModel_ >= 0);

	transform_.position_ = { transform_.position_.x,transform_.position_.y,0.0f };   //位置、ポジション
	//transform_.scale_ = { 1.0f,1.0f,1.0f };                         //大きさ
}

void Aim::Update()
{
	//transform_.position_.x = transform_.position_.x;
	//transform_.position_.y = transform_.position_.y;
	//transform_.position_.x = GetParent()->GetPosition().x;
	//transform_.position_.y = GetParent()->GetPosition().y;

	//プレイヤーの位置から照準（線を自機の先から出す）
	Player* player = (Player*)GetParent();
}

void Aim::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Aim::Release()
{
}
