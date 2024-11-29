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
	// ƒ{ƒ^ƒ“‚ğ‰Ÿ‚µ‚½‚©‚Ç‚¤‚©
	bool GetShootFlag()const { return m_isShot; }
	// À•W‚ğ“n‚·
	Vec2 GetShootPos()const { return m_pos; }

	
private:
	// Player‚Ì‰æ‘œ‚Ìæ“¾•Ï”
	int m_graficHandle;
	int m_joyPad;
	int m_tCount;
	float m_moveX;
	float m_moveY;
	float m_length;
	// ‹…‚ğ‘Å‚Á‚Ä‚¢‚é‚©‚Ç‚¤‚©
	bool m_isShot;
	Enemy* m_pEnemy;
	Vec2 m_pos;
};

