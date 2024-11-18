#include "Enemy.h"
#include "DxLib.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
	// •`‰æ‚µ‚½ŠG‚ğÁ‚·
	DeleteGraph(GHandle);
}

void Enemy::Init()
{
	// Enemy‚ÌŠG‚Ìæ“¾
	GHandle = LoadGraph("data/image/Enemy.png");
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	// Enemy‚Ì•\¦ˆÊ’u
	DrawGraph(enemyPosX,enemyPosY,GHandle,true);
}
