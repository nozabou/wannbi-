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
	// Enemy�̉摜�̎擾�ϐ�
	int GHandle = 0;
	// Enemy�̕\���ʒu�̕ϐ�
	int enemyPosX = 100;
	int enemyPosY = 100;
	const int enemySize = 48;
	bool enemyRightMove;
	// ���ϐ�
	int BulletX = enemyPosX;
	int BulletY = enemyPosY;

	const int BulletSpeed = 10;
	const int BulletR = 5;
	const int kScreenHeight = 720;
};

