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
	int enemyX = 100;
	int enemyY = 100;
private:
};

