#include "Player.h"
#include "DxLib.h"
#include "assert.h"

Player::Player()
{
}

Player::~Player()
{
	// 取得した絵を消す
	DeleteGraph(GrHandle);
}

void Player::Init()
{
	// 絵の取得
	GrHandle = LoadGraph("data/image/Player.png");
	
	
}

void Player::Update()
{
	// キャラクターの操作
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
	// Playerの表示位置
	DrawGraph(playerX,playerY,GrHandle,true);
}
