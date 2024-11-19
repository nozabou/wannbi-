#include "Enemy.h"
#include "DxLib.h"
#include "game.h"

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
	enemyRightMove;
	/// �G�l�~�[���E�ɓ����Ă��邩�𔻒f����
	for (int i = 0; i < 3; i++)
	{
		enemyRightMove = true;
	}
	
}

void Enemy::Update()
{
	//// �G�l�~�[���E�ɐi��
	//if (enemyRightMove == true)
	//{
	//	enemyPosX += 3;
	//}
	//// �G�l�~�[�����ɐi��
	//else
	//{
	//	enemyPosX -=  3;
	//}
	// �G�l�~�[����ʔ����ɏo�Ȃ��悤�ɂ���
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
	//�G�̒e�̍��W�X�V����
	BulletY += BulletSpeed;

	if (BulletY > kScreenHeight + BulletR * 2) {
		BulletX = enemyPosX;
		BulletY = enemyPosY;
	}
	// �G�l�~�[���e������
	BulletY += BulletSpeed;
	if (BulletY > kScreenHeight + BulletR * 2)
	{
		BulletX = enemyPosX;
		BulletY = enemyPosY;
	}
	//�e�̕`��
	
	
	DrawCircle(BulletX + BulletR, BulletY + BulletR, BulletR, GetColor(255, 255, 255), true);
}

void Enemy::Draw()
{
	// Enemy�̕\���ʒu
	DrawGraph(enemyPosX,enemyPosY,GHandle,true);
}
