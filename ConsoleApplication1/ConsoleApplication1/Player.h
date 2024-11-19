#pragma once
#include "Shot.h"

class Shot;
class Enemy;
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
	int playerPosX = 320;
	int playerPosY = 600;
	int playerSize = 50;
	// Player�̈ړ����̗�
	int movePowerX = 0;
	int movePowerY = 0;
	int JoyPad;
private:
	Shot *PShot;
	Enemy* PEnemy;
};

