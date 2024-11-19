#include "Player.h"
#include "DxLib.h"
#include "assert.h"
#include "Shot.h"
#include "Enemy.h"
#include <cmath>



Player::Player()
{
}

Player::~Player()
{
	// �擾�����G������
	DeleteGraph(GrHandle);
	delete PEnemy;
	delete PShot;
}

void Player::Init()
{
	// �G�̎擾
	GrHandle = LoadGraph("data/image/Player.png");
	PShot = new Shot();
	PEnemy = new Enemy();
}

void Player::Update()
{
	// �L�����N�^�[�̑���
	JoyPad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if ((JoyPad & PAD_INPUT_UP) != 0)
	{
		movePowerY = -3;
	}
	if ((JoyPad & PAD_INPUT_DOWN) != 0)
	{
		movePowerY = 3;
	}
	if((JoyPad & PAD_INPUT_UP) == 0 && (JoyPad &PAD_INPUT_DOWN) == 0)
	{
		movePowerY = 0;
	}
	if ((JoyPad & PAD_INPUT_RIGHT) != 0)
	{
		movePowerX = 3;
	}
	if ((JoyPad & PAD_INPUT_LEFT) != 0)
	{
		movePowerX = -3;
	}
	if ((JoyPad & PAD_INPUT_RIGHT) == 0 && (JoyPad & PAD_INPUT_LEFT) == 0)
	{
		movePowerX = 0;
	}
	playerPosY += movePowerY;
	playerPosX += movePowerX;
	// �X�y�[�X�L�[�������ꂽ��e�𔭎˂���
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		/// shotFlag��false�̏ꍇ��������
		if (PShot->shotFlag == false)
		{ 
			int PlayerW, PlayerH, ShotW, ShotH;
			///  �摜�̃T�C�Y
   			GetGraphSize(GrHandle, &PlayerW, &PlayerH);
			GetGraphSize(PShot->GtHandle, &ShotW, &ShotH);
			/// �e�̏o��ꏊ��X���W���w��
			PShot->shotPosX = (PlayerW - ShotW) / 2 + playerPosX;
			/// �e�̏o��ꏊ��Y���W���w��
			PShot->shotPosY = (PlayerH - ShotH) / 2 + playerPosY;
			/// shotFlag��true��������
			PShot->shotFlag = true;
		}
	}
	/// �v���C���[����ʂ̍��[�𒴂��Ȃ��悤�ɂ���
	if (playerPosX < 0)
	{
		playerPosX = 0;
	}
	/// ��ʂ̉E�[�𒴂��Ȃ��悤�ɂ���
	if (playerPosX > 680)
	{
		playerPosX = 680;
	}
	// ��ʂ̏�𒴂��Ȃ��悤�ɂ���
	if (playerPosY < 0)
	{
		playerPosY = 0;
	}
	/// ��ʂ̉��𒴂��Ȃ��悤�ɂ���
	if (playerPosY > 740 - 64)
	{
		playerPosY = 740 - 64;
	}
	// �����蔻��(��)
	int a = (playerPosX + (playerSize / 2)) - PEnemy->BulletX;
	int b = (playerPosY + (playerSize / 2)) - PEnemy->BulletY;
	int sum = sqrt(pow(a, 2) + pow(b, 2));
	//�������Ă�����break�ŃQ�[�����I��
	if (sum <= (playerSize / 2) + PEnemy->BulletR) 
	{
		DeleteGraph(GrHandle);
	}
	
}

void Player::Draw()
{
	// Player�̕\���ʒu
	DrawGraph(playerPosX,playerPosY,GrHandle,true);
}
