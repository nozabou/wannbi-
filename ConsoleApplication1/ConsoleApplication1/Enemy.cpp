#include "Enemy.h"
#include "DxLib.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
	// 描画した絵を消す
	DeleteGraph(GHandle);
}

void Enemy::Init()
{
	// Enemyの絵の取得
	GHandle = LoadGraph("data/image/Enemy.png");
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	// Enemyの表示位置
	DrawGraph(enemyX,enemyY,GHandle,true);
}
