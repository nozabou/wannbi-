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
	int enemyPosX = 100;
	int enemyPosY = 100;
	const int enemySize = 50;
	bool enemyRightMove;
	// 仮変数
	int BulletX = enemyPosX;
	int BulletY = enemyPosY;

	const int BulletSpeed = 10;
	const int BulletR = 5;
	const int kScreenHeight = 720;
private:
};

