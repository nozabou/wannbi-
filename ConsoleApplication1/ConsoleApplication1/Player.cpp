#include "Player.h"
#include "DxLib.h"
#include "assert.h"
#include "Shot.h"
#include "Enemy.h"
#include <cmath>
#include "Vec2.h"
#include "game.h"
#include <math.h>

namespace
{
	//�O���t�B�b�N�T�C�Y�������蔻��
	constexpr int kPlayerGraphW = 48;
	constexpr int kPlayerGraphH = 48;
	constexpr int kSpeed = 3;
}

Player::Player():
	m_graficHandle(-1),
	m_joyPad(1),
	m_pos(Game::kScreenWidthCenter, Game::kScreenHeightCenter),
	m_isShot(false)
{
}

Player::~Player()
{
	// �擾�����G������
	DeleteGraph(m_graficHandle);
	delete m_pEnemy;
}

void Player::Init()
{
	// �G�̎擾
	m_graficHandle = LoadGraph("data/image/Player.png");
	m_pEnemy = new Enemy();
}

void Player::Update()
{
	// �L�����N�^�[�̑���
	m_joyPad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if ((m_joyPad & PAD_INPUT_UP) != 0)
	{
		//m_pos.Y -= kSpeed;
		m_moveY = -kSpeed;
	}
	if ((m_joyPad & PAD_INPUT_DOWN) != 0)
	{
		//m_pos.Y += kSpeed;
		m_moveY = kSpeed;
	}
	if((m_joyPad & PAD_INPUT_UP) == 0 && (m_joyPad &PAD_INPUT_DOWN) == 0)
	{
		//m_pos.Y += kSpeed;
		m_moveY = 0;
	}
	if ((m_joyPad & PAD_INPUT_RIGHT) != 0)
	{
		//m_pos.X += kSpeed;
		m_moveX = kSpeed;
	}
	if ((m_joyPad & PAD_INPUT_LEFT) != 0)
	{
		//m_pos.X -= kSpeed;
		m_moveX = -kSpeed;
	}
	if ((m_joyPad & PAD_INPUT_RIGHT) == 0 && (m_joyPad & PAD_INPUT_LEFT) == 0)
	{
		//m_pos.X += kSpeed;
		m_moveX = 0;
	}
	// A�{�^������������e��ł�
	m_isShot = false;
	m_tCount++;
	if (m_tCount == 10)
	{
		if (m_joyPad & PAD_INPUT_A)
		{
			m_isShot = true;
		}
		m_tCount = 0;
	}
	m_length = sqrtf(m_moveX * m_moveX + m_moveY * m_moveY);

	if (m_length > 0)
	{
		m_moveX /= m_length;
		m_moveY /= m_length;
	}
		
		m_pos.X += m_moveX * kSpeed;
		m_pos.Y += m_moveY * kSpeed;
	// �v���C���[����ʂ̍��[�𒴂��Ȃ��悤�ɂ���
	if (m_pos.X < 0)
	{
		m_pos.X = 0;
	}
	// ��ʂ̉E�[�𒴂��Ȃ��悤�ɂ���
	if (m_pos.X > Game::kScreenWidth - kPlayerGraphW)
	{
		m_pos.X = Game::kScreenWidth - kPlayerGraphW;
	}
	// ��ʂ̏�𒴂��Ȃ��悤�ɂ���
	if (m_pos.Y < 0)
	{
		m_pos.Y = 0;
	}
	// ��ʂ̉��𒴂��Ȃ��悤�ɂ���
	if (m_pos.Y > Game::kScreenHeight - kPlayerGraphH)
	{
		m_pos.Y = Game::kScreenHeight - kPlayerGraphH;
	}
	// �����蔻��(��)
	

	printfDx("%f\n",m_pos.Y);
}

void Player::Draw()
{
	DrawBox(m_pos.X , m_pos.Y , m_pos.X + kPlayerGraphW, m_pos.Y + kPlayerGraphH, 0xffff00, false);

	// Player�̕\���ʒu
	DrawGraph(m_pos.X, m_pos.Y, m_graficHandle, true);
	
}
