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
	// �擾�����G������
	DeleteGraph(m_graphicHandle);
}

void Shot::Init()
{
	// �G�̎擾
	m_graphicHandle = LoadGraph("data/image/Player.png");
}

void Shot::Update()
{
	if (m_shotFlag)
	{
		// �e���������16���i��
		m_pos.Y -= 16;
		// shotPosY��-80��菬�����Ȃ����甭������shotFlag��false��������
		if (m_pos.Y< -10)
		{
			m_shotFlag = false;
		}

	}
}

void Shot::Draw()
{
	// Shot�̕\���ʒu
 	DrawGraph(m_pos.X, m_pos.Y, m_graphicHandle, true);
}
