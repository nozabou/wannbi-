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
	//グラフィックサイズ兼当たり判定
	constexpr int kPlayerGraphW = 48;
	constexpr int kPlayerGraphH = 48;
	constexpr int kSpeed = 3;
}

Player::Player():
	m_graficHandle(-1),
	m_joyPad(1),
	m_pos(Game::kScreenWidthCenter, Game::kScreenHeightCenter)
{
}

Player::~Player()
{
	// 取得した絵を消す
	DeleteGraph(m_graficHandle);
	delete m_pEnemy;
	delete m_pShot;
}

void Player::Init()
{
	// 絵の取得
	m_graficHandle = LoadGraph("data/image/Player.png");
	m_pShot = new Shot();
	m_pEnemy = new Enemy();
}

void Player::Update()
{
	// キャラクターの操作
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
	// m_pShotのUpdate		
	m_pShot->Update();
	// Aボタンを押したら弾を打つ
		if (m_joyPad & PAD_INPUT_A)
		{
			// shotFlagがfalseの場合発動する
			if (m_pShot->GetShotFlag() == false)
			{
				m_pShot->Init();
				int PlayerW, PlayerH, ShotW, ShotH;
				//  画像のサイズ
				GetGraphSize(m_graficHandle, &PlayerW, &PlayerH);
				GetGraphSize(m_pShot->m_graphicHandle, &ShotW, &ShotH);
				// 弾の出る場所のX座標を指定
				m_pShot->m_pos.X = (PlayerW - ShotW) / 2 + m_pos.X - ShotW / 2;
				// 弾の出る場所のY座標を指定
				m_pShot->m_pos.Y = (PlayerH - ShotH) / 2 + m_pos.Y;
				// shotFlagにtrueを代入する
				m_pShot->m_shotFlag = true;
			}
		}

		m_length = sqrtf(m_moveX * m_moveX + m_moveY * m_moveY);

		if (m_length > 0)
		{
			m_moveX /= m_length;
			m_moveY /= m_length;
		}
		
		m_pos.X += m_moveX * kSpeed;
		m_pos.Y += m_moveY * kSpeed;
	// プレイヤーが画面の左端を超えないようにする
	if (m_pos.X < 0)
	{
		m_pos.X = 0;
	}
	// 画面の右端を超えないようにする
	if (m_pos.X > Game::kScreenWidth - kPlayerGraphW)
	{
		m_pos.X = Game::kScreenWidth - kPlayerGraphW;
	}
	// 画面の上を超えないようにする
	if (m_pos.Y < 0)
	{
		m_pos.Y = 0;
	}
	// 画面の下を超えないようにする
	if (m_pos.Y > Game::kScreenHeight - kPlayerGraphH)
	{
		m_pos.Y = Game::kScreenHeight - kPlayerGraphH;
	}
	// 当たり判定(仮)
	

	printfDx("%f\n",m_pos.Y);
}

void Player::Draw()
{
	DrawBox(m_pos.X , m_pos.Y , m_pos.X + kPlayerGraphW, m_pos.Y + kPlayerGraphH, 0xffff00, false);

	// Playerの表示位置
	DrawGraph(m_pos.X, m_pos.Y, m_graficHandle, true);
	if (m_pShot->GetShotFlag())
	{
		m_pShot->Draw();
	}
}
