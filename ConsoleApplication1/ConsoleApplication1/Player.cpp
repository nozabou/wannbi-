#include "Player.h"
#include "DxLib.h"
#include "assert.h"

Player::Player()
{
}

Player::~Player()
{
	// �擾�����G������
	DeleteGraph(GrHandle);
}

void Player::Init()
{
	// �G�̎擾
	GrHandle = LoadGraph("data/image/Player.png");
	
	
}

void Player::Update()
{
	// �L�����N�^�[�̑���
	JoyPad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if ((JoyPad & PAD_INPUT_UP) != 0)
	{
		movepowerY = -3;
	}
	if ((JoyPad & PAD_INPUT_DOWN) != 0)
	{
		movepowerY = 3;
	}
	if((JoyPad & PAD_INPUT_UP) == 0 && (JoyPad &PAD_INPUT_DOWN) == 0)
	{
		movepowerY = 0;
	}
	if ((JoyPad & PAD_INPUT_RIGHT) != 0)
	{
		movepowerX = 3;
	}
	if ((JoyPad & PAD_INPUT_LEFT) != 0)
	{
		movepowerX = -3;
	}
	if ((JoyPad & PAD_INPUT_RIGHT) == 0 && (JoyPad & PAD_INPUT_LEFT) == 0)
	{
		movepowerX = 0;
	}
	playerY += movepowerY;
	playerX += movepowerX;
}

void Player::Draw()
{
	// Player�̕\���ʒu
	DrawGraph(playerX,playerY,GrHandle,true);
}
