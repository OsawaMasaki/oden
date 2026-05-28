#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Player.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hModel_(-1),speed_(0.5)
{
}

void Bullet::Initialize()
{
	//hModel_ = Model::Load("Enemy.fbx");
	hModel_ = Model::Load("Bullet.fbx");
	assert(hModel_ >= 0);
	
	//  ↓いらない 書かなくてもPlayerの場所を探してくれる
	//Player* player = (Player*)GetParent();            //Playerの情報を読み込む
	//transform_.position_ = player->GetPosition();     //Playerの位置を探す

	//transform_.position_ = { 0.0f,-3.0f,0.0f };            //位置、ポジション
	transform_.scale_ = { 0.1f,0.1,0.3f };            //大きさ
	transform_.rotate_ = { 0.0f,0.0f,0.0f };          //回転

	SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f),0.2f);
	AddCollider(collider);

}

void Bullet::Update()
{
	//弾の移動速度
	transform_.position_.z += speed_;


	//弾の回転
	transform_.rotate_.z -= 15;
	if (transform_.rotate_.z <= 0)   //無限に数値が変わるのを防ぐ
	{
		transform_.rotate_.z = 360;
	}

	//自分を消す
	if (transform_.position_.z >= 100.0f) {
		KillMe();
	}
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
