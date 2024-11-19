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
	// Playerの画像の取得変数
	int GrHandle = 0;
	// Playerの表示位置
	int playerPosX = 320;
	int playerPosY = 600;
	int playerSize = 50;
	// Playerの移動時の力
	int movePowerX = 0;
	int movePowerY = 0;
	int JoyPad;
private:
	Shot *PShot;
	Enemy* PEnemy;
};

