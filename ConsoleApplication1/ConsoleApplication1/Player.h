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
	// �{�^�������������ǂ���
	bool GetShootFlag()const { return m_isShot; }
	// ���W��n��
	Vec2 GetShootPos()const { return m_pos; }

	
private:
	// Player�̉摜�̎擾�ϐ�
	int m_graficHandle;
	int m_joyPad;
	int m_tCount;
	float m_moveX;
	float m_moveY;
	float m_length;
	// ����ł��Ă��邩�ǂ���
	bool m_isShot;
	Enemy* m_pEnemy;
	Vec2 m_pos;
};

