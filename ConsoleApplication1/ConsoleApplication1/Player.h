#pragma once
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
	int playerX = 320;
	int playerY = 600;
	// Playerの移動時の力
	int movepowerX = 0;
	int movepowerY = 0;
	int JoyPad;
private:
};

