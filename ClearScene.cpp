#include "ClearScene.h"
#include"Engine/Image.h"
#include"Engine/Input.h"
#include"Engine/SceneManager.h"

ClearScene::ClearScene(GameObject* parent)
{
}

void ClearScene::Initialize()
{
	hTitlePic_ = Image::Load("Clear.png");
	assert(hTitlePic_ >= 0);
}

void ClearScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		//シーンマネージャーを探して、シーン切り替えの関数を呼ぶ
		// 見つからない場合はnullptrが返るので、nullptrでないことを確認してから呼ぶ
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

void ClearScene::Draw()
{
	//transform_.scale_ = { 2.0f,2.0f,2.0f };      //画像サイズを二倍に
	Image::SetTransform(hTitlePic_, transform_); //画像の位置や向きなどを設定
	Image::Draw(hTitlePic_); //画像を描画
}

void ClearScene::Release()
{
}
