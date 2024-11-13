#include "Player.h"
#include "DxLib.h"
#include "assert.h"

Player::Player()
{
}

Player::~Player()
{
	DeleteGraph(GrHandle);
}

void Player::Init()
{
	GrHandle = LoadGraph("data/image/Player.png");
	//assert(GrHandle == 0);
}

void Player::Update()
{
}

void Player::Draw()
{
	DrawGraph(100,100,GrHandle,false);

	//DrawExtendGraph(100, 100, 200, 200, GrHandle, true);
}
