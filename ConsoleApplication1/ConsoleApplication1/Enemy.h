#pragma once
class Enemy
{
public:
	Enemy();
	~Enemy();
	void Init();
	void Update();
	void Draw();
	// Enemyの画像の取得変数
	int GHandle = 0;
	// Enemyの表示位置の変数
	int enemyX = 100;
	int enemyY = 100;
private:
};

