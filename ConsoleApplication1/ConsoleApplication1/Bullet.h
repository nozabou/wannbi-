#pragma once
#include "Enemy.h"

class nemy;
class Plater;

class Bullet
{
public:
	Bullet();
	~Bullet();
	void Init();
	void Update();
	void Draw();
	
private:
	Enemy* m_pEnemy;
	
};

