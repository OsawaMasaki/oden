#include "Line.h"
#include "Engine/Model.h"
#include "Player.h"

Line::Line(GameObject* parent)
	:GameObject(parent, "Line"), hModel_(-1)
{
}

void Line::Initialize()
{
	hModel_ = Model::Load("Ball.fbx");
	assert(hModel_ >= 0);

	transform_.position_ = { 0.0f,0.0f,0.0f };            //位置、ポジション
	transform_.scale_ = { 0.01f,0.01f,50.0f };            //大きさ
}

void Line::Update()
{
}

void Line::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Line::Release()
{
}
