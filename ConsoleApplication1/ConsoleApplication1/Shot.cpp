#include "Shot.h"
#include "DxLib.h"

namespace
{
	constexpr int kPlayerGraphW = 48;
	constexpr int kPlayerGraphH = 48;
}

Shot::Shot():
	m_graphicHandle(-1),
	m_shotFlag(false)
{
}

Shot::~Shot()
{
	// æ“¾‚µ‚½ŠG‚ğÁ‚·
	DeleteGraph(m_graphicHandle);
}

void Shot::Init()
{
	// ŠG‚Ìæ“¾
	m_graphicHandle = LoadGraph("data/image/Player.png");
}

void Shot::Update()
{
	if (m_shotFlag)
	{
		// ’e‚ªã•ûŒü‚É16‚¸‚Âi‚Ş
		m_pos.Y -= 16;
		// shotPosY‚ª-80‚æ‚è¬‚³‚­‚È‚Á‚½‚ç”­“®‚µ‚ÄshotFlag‚ğfalse‚ğ‘ã“ü‚·‚é
		if (m_pos.Y< -10)
		{
			m_shotFlag = false;
		}

	}
}

void Shot::Draw()
{
	// Shot‚Ì•\¦ˆÊ’u
 	DrawGraph(m_pos.X, m_pos.Y, m_graphicHandle, true);
}
