#pragma once
class Enemy
{
public:
	Enemy();
	~Enemy();
	void Init();
	void Update();
	void Draw();
	// Enemy‚Ì‰æ‘œ‚Ìæ“¾•Ï”
	int GHandle = 0;
	// Enemy‚Ì•\¦ˆÊ’u‚Ì•Ï”
	int enemyPosX = 100;
	int enemyPosY = 100;
private:
};

