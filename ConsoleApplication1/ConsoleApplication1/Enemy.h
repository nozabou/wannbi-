#pragma once
class Enemy
{
public:
	Enemy();
	~Enemy();
	void Init();
	void Update();
	void Draw();
	// Enemy�̉摜�̎擾�ϐ�
	int GHandle = 0;
	// Enemy�̕\���ʒu�̕ϐ�
	int enemyPosX = 100;
	int enemyPosY = 100;
private:
};

