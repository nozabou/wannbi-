#include "Enemy.h"
#include "DxLib.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
	// �`�悵���G������
	DeleteGraph(GHandle);
}

void Enemy::Init()
{
	// Enemy�̊G�̎擾
	GHandle = LoadGraph("data/image/Enemy.png");
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	// Enemy�̕\���ʒu
	DrawGraph(enemyPosX,enemyPosY,GHandle,true);
}
