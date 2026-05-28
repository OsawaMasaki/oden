#pragma once
#include "Engine\\GameObject.h"

class Enemy :
	public GameObject
{
public:
	//コンストラクタ
//引数：parent  親オブジェクト（SceneManager）
	Enemy(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
	void OnCollision(GameObject* pTarget);
private:
	int hModel_;         //モデルのハンドル
	float timer = 0.0f;
	float randamx;
	float randamy;
	float posx;
	float posy;
};

