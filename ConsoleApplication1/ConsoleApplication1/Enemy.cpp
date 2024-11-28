#include "Enemy.h"
#include "DxLib.h"
#include "game.h"

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
	enemyRightMove;
	/// エネミーが右に動いているかを判断する
	for (int i = 0; i < 3; i++)
	{
		enemyRightMove = true;
	}
	
}

void Enemy::Update()
{
	// エネミーが右に進む
	if (enemyRightMove == true)
	{
		enemyPosX += 3;
	}
	// エネミーが左に進む
	else
	{
		enemyPosX -=  3;
	}
	// エネミーが画面外に出ないようにする
	for (int i = 0; i < 3; i++)
	{
		if (enemyPosX > 680)
		{
			enemyPosX = 680;
			enemyRightMove = false;
		}
		else if (enemyPosX < 0)
		{
			enemyPosX = 0;
			enemyRightMove = true;
		}
	}
	//敵の弾の座標更新処理
	BulletY += BulletSpeed;

	// エネミーが弾を撃つ
	if (BulletY > kScreenHeight + BulletR * 2)
	{
		BulletX = enemyPosX;
		BulletY = enemyPosY;
	}
	//弾の描画
	DrawBox(BulletX,BulletY, BulletX + BulletR, BulletY + BulletR, 0xffff00, false);
	DrawCircle(BulletX , BulletY, BulletR, GetColor(255, 255, 255), true);
}

void Enemy::Draw()
{
	// Enemyの表示位置
	DrawGraph(enemyPosX,enemyPosY,GHandle,true);
}
