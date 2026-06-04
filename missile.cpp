#include "missile.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

missile::missile(GameObject* parent)
	:GameObject(parent, "missile"), hModel_(-1), speed_(0.3)
{
}

void missile::Initialize()
{
	hModel_ = Model::Load("missile.fbx");
	assert(hModel_ >= 0);

	//tr_.position_ = { 0.0f,-3.0f,0.0f };            //位置、ポジション
	transform_.scale_ = { 0.3f,0.3f,0.5f };           //大きさ
	transform_.rotate_ = { 0.0f,0.0f,0.0f };          //回転

	SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 0.4f);
	AddCollider(collider);
}

void missile::Update()
{
	//弾の移動速度
	transform_.position_.z += speed_;


	//弾の回転
	transform_.rotate_.z -= 10;
	if (transform_.rotate_.z <= 0)   //無限に数値が変わるのを防ぐ
	{
		transform_.rotate_.z = 360;
	}

	//自分を消す
	if (transform_.position_.z > 100.0f) {
		KillMe();
	}
}

void missile::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void missile::Release()
{
}
