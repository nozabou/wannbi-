#pragma once
class Player
{
public:
	Player();
	~Player();

	void Init();
	void Update();
	void Draw();
	// Player�̉摜�̎擾�ϐ�
	int GrHandle = 0;
	// Player�̕\���ʒu
	int playerX = 320;
	int playerY = 600;
	// Player�̈ړ����̗�
	int movepowerX = 0;
	int movepowerY = 0;
	int JoyPad;
private:
};

