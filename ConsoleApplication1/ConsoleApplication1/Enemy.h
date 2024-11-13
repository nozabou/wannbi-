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
	int enemyX = 100;
	int enemyY = 100;
private:
};

