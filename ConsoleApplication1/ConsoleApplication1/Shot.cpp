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
	// 取得した絵を消す
	DeleteGraph(m_graphicHandle);
}

void Shot::Init()
{
	// 絵の取得
	m_graphicHandle = LoadGraph("data/image/Player.png");
}

void Shot::Update()
{
	if (m_shotFlag)
	{
		// 弾が上方向に16ずつ進む
		m_pos.Y -= 16;
		// shotPosYが-80より小さくなったら発動してshotFlagをfalseを代入する
		if (m_pos.Y< -10)
		{
			m_shotFlag = false;
		}

	}
}

void Shot::Draw()
{
	// Shotの表示位置
 	DrawGraph(m_pos.X, m_pos.Y, m_graphicHandle, true);
}
