#pragma once
#include "Shot.h"
#include "Vec2.h"

class Vec2;
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
	
private:
	// Playerの画像の取得変数
	int m_graficHandle;
	int m_joyPad;
	float m_moveX;
	float m_moveY;
	float m_length;
	Shot* m_pShot;
	Enemy* m_pEnemy;
	Vec2 m_pos;
};

