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
	void SetPos(Vec2 pos);
	// ”­ŽË‚·‚é–½—ß‚ðŽó‚¯Žæ‚Á‚½
	void SetShotFlag(bool ShootFlag) { m_shotFlag = ShootFlag; }
	bool GetShotFlag()const { return m_shotFlag; }
	Vec2 GetPos()const { return m_pos; }
	int GetSize()const { return 8; }
private:
	Vec2 m_pos;
	bool m_shotFlag;
	int m_graphicHandle;
};

