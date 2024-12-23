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
	// ボタンを押したかどうか
	bool GetShootFlag()const { return m_isShot; }
	// 座標を渡す
	Vec2 GetShootPos()const { return m_pos; }

	
private:
	// Playerの画像の取得変数
	int m_graficHandle;
	int m_joyPad;
	int m_tCount;
	float m_moveX;
	float m_moveY;
	float m_length;
	// 球を打っているかどうか
	bool m_isShot;
	Enemy* m_pEnemy;
	Vec2 m_pos;
};

