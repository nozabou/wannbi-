#pragma once
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
	int playerX = 320;
	int playerY = 600;
	// Player‚ÌˆÚ“®‚Ì—Í
	int movepowerX = 0;
	int movepowerY = 0;
	int JoyPad;
private:
};

