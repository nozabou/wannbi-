#include "Player.h"
#include "DxLib.h"
#include "assert.h"
#include "Shot.h"

Player::Player()
{
}

Player::~Player()
{
	// �擾�����G������
	DeleteGraph(GrHandle);

	delete PShot;
}

void Player::Init()
{
	// �G�̎擾
	GrHandle = LoadGraph("data/image/Player.png");
	PShot = new Shot();
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
	playerPosY += movepowerY;
	playerPosX += movepowerX;
	// �X�y�[�X�L�[�������ꂽ��e�𔭎˂���
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		/// shotFlag��false�̏ꍇ��������
		if (PShot->shotFlag == false)
		{
			int Playerw, Playerh, Shotw, Shoth;
			///  �摜�̃T�C�Y
			GetGraphSize(GrHandle, &Playerw, &Playerh);
			GetGraphSize(PShot->GtHandle, &Shotw, &Shoth);
			/// �e�̏o��ꏊ��X���W���w��
			PShot->shotPosX = (Playerw - Shotw) / 2 + playerPosX;
			/// �e�̏o��ꏊ��Y���W���w��
			PShot->shotPosY = (Playerh - Shoth) / 2 + playerPosY;
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
	if (playerPosX > 730 - 64)
	{
		playerPosX = 730 - 64;
	}
	// ��ʂ̏�𒴂��Ȃ��悤�ɂ���
	if (playerPosY < 0)
	{
		playerPosY = 0;
	}
	/// ��ʂ̉��𒴂��Ȃ��悤�ɂ���
	if (playerPosY > 730 - 64)
	{
		playerPosY = 730 - 64;
	}

}

void Player::Draw()
{
	// Player�̕\���ʒu
	DrawGraph(playerPosX,playerPosY,GrHandle,true);
}
