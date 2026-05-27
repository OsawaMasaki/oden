#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Bullet.h"
#include "missile.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("SpaceShip.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { transform_.position_.x,0.0f,0.0f };   //位置、ポジション
	transform_.scale_ = { 0.5f,0.6f,0.5f };                        //大きさ
}

void Player::Update()
{
	//左移動
	if (Input::IsKey(DIK_LEFT) || Input::IsKey(DIK_A))
	{
		transform_.position_.x -= 0.2;
	}
	//右移動
	if (Input::IsKey(DIK_RIGHT) || Input::IsKey(DIK_D))
	{
		transform_.position_.x += 0.2;
	}
	//上移動
	if (Input::IsKey(DIK_UP) || Input::IsKey(DIK_W))
	{
		transform_.position_.y += 0.2;
	}
	//下移動
	if (Input::IsKey(DIK_DOWN) || Input::IsKey(DIK_S))
	{
		transform_.position_.y -= 0.2;
	}

	//弾の発射
	if (Input::IsKeyUp(DIK_SPACE))
	{
		Bullet* pBullet = Instantiate<Bullet>(this->GetParent());
		pBullet->SetPosition(transform_.position_);
	}
	if (Input::IsKeyUp(DIK_B))
	{
		missile* pBullet = Instantiate<missile>(this->GetParent());
		pBullet->SetPosition(transform_.position_);
	}
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
