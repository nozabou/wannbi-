#pragma once
#include "Shot.h"

class Shot;

class Player
{
public:
	Player();
	~Player();

	void Init();
	void Update();
	void Draw();
	// Player‚Ì‰æ‘œ‚Ìæ“¾•Ï”
	int GrHandle = 0;
	// Player‚Ì•\¦ˆÊ’u
	int playerPosX = 320;
	int playerPosY = 600;
	// Player‚ÌˆÚ“®‚Ì—Í
	int movepowerX = 0;
	int movepowerY = 0;
	int JoyPad;
private:
	Shot *PShot;
};

