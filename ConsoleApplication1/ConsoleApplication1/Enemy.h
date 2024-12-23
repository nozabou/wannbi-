#pragma once
class Enemy
{
public:
	Enemy();
	~Enemy();
	void Init();
	void Update();
	void Draw();
	int GetPosX()const { return enemyPosX; };
	int GetPosY()const { return enemyPosY; };
	int GetSize()const { return enemySize; };

private:
	// Enemyの画像の取得変数
	int GHandle = 0;
	// Enemyの表示位置の変数
	int enemyPosX = 100;
	int enemyPosY = 100;
	const int enemySize = 48;
	bool enemyRightMove;
	// 仮変数
	int BulletX = enemyPosX;
	int BulletY = enemyPosY;

	const int BulletSpeed = 10;
	const int BulletR = 5;
	const int kScreenHeight = 720;
};

