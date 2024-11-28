#pragma once
#include "Vec2.h"
class Shot
{
public:
	Shot();
	~Shot();
	void Init();
	void Update();
	void Draw();
	bool GetShotFlag()const { return m_shotFlag; }
	int m_graphicHandle;
	bool m_shotFlag;
	Vec2 m_pos;
private:
	
	
	
};

