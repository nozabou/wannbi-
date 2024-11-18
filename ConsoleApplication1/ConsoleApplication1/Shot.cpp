#include "Shot.h"
#include "DxLib.h"

Shot::Shot()
{
}

Shot::~Shot()
{
	// �擾�����G������
	DeleteGraph(GtHandle);
}

void Shot::Init()
{
	// �G�̎擾
	GtHandle = LoadGraph("data/image/Player.png");
}

void Shot::Update()
{
	if (shotFlag)
	{
		// �e���������16���i��
		shotPosY -= 16;
		// shotPosY��-80��菬�����Ȃ����甭������shotFlag��false��������
		if (shotPosY < 80)
		{
			shotFlag = false;
		}

	}
}

void Shot::Draw()
{
	// Shot�̕\���ʒu
	DrawGraph(shotPosX,shotPosY,GtHandle, true);
}
