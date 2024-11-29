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
	// �擾�����G������
	DeleteGraph(m_graphicHandle);
}

void Shot::Init()
{
	// �G�̎擾
	m_graphicHandle = LoadGraph("data/image/Player.png");
	m_pos.X = Game::kScreenWidth / 2;
	m_pos.Y = Game::kScreenHeight;
}

void Shot::Update()
{
	if (m_shotFlag)
	{
		// �e���������16���i��
		m_pos.Y -= 16;
	}
}

void Shot::Draw()
{
	// Shot�̕\���ʒu
 	/*DrawGraph(m_pos.X, m_pos.Y, m_graphicHandle, true);*/
	DrawCircle(m_pos.X, m_pos.Y, 8,GetColor(255, 255, 0), true);
}

// ���ˍ��W���󂯎��
void Shot::SetPos(Vec2 pos)
{
	m_pos.X = pos.X + 48 / 2;
	m_pos.Y = pos.Y;
}
