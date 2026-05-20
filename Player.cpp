#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Bullet.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("SpaceShip.fbx");
	assert(hModel_ >= 0);
	tr_.position_ = { tr_.position_.x,-3.0f,0.0f };       //位置、ポジション
	tr_.scale_ = { 0.5f,0.5f,0.5f };                      //大きさ
}

void Player::Update()
{
	//左移動
	if (Input::IsKey(DIK_LEFT) || Input::IsKey(DIK_A))
	{
		tr_.position_.x -= 0.2;
	}

	//右移動
	if (Input::IsKey(DIK_RIGHT) || Input::IsKey(DIK_D))
	{
		tr_.position_.x += 0.2;
	}

	//弾の発射
	if (Input::IsKey(DIK_SPACE))
	{
	//	Instantiate<Bullet>(this);
	}
}

void Player::Draw()
{
	Model::SetTransform(hModel_, tr_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
