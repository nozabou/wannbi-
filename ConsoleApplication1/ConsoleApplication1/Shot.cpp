#include "Shot.h"
#include "DxLib.h"
#include "game.h"

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
	m_pos.X = Game::kScreenWidth / 2;
	m_pos.Y = Game::kScreenHeight;
}

void Shot::Update()
{
	if (m_shotFlag)
	{
		// 弾が上方向に16ずつ進む
		m_pos.Y -= 16;
	}
}

void Shot::Draw()
{
	// Shotの表示位置
 	/*DrawGraph(m_pos.X, m_pos.Y, m_graphicHandle, true);*/
	DrawCircle(m_pos.X, m_pos.Y, 8,GetColor(255, 255, 0), true);
}

// 発射座標を受け取る
void Shot::SetPos(Vec2 pos)
{
	m_pos.X = pos.X + 48 / 2;
	m_pos.Y = pos.Y;
}
