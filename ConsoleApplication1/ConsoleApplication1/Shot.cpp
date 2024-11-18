#include "Shot.h"
#include "DxLib.h"

Shot::Shot()
{
}

Shot::~Shot()
{
	// æ“¾‚µ‚½ŠG‚ğÁ‚·
	DeleteGraph(GtHandle);
}

void Shot::Init()
{
	// ŠG‚Ìæ“¾
	GtHandle = LoadGraph("data/image/Player.png");
}

void Shot::Update()
{
	if (shotFlag)
	{
		// ’e‚ªã•ûŒü‚É16‚¸‚Âi‚Ş
		shotPosY -= 16;
		// shotPosY‚ª-80‚æ‚è¬‚³‚­‚È‚Á‚½‚ç”­“®‚µ‚ÄshotFlag‚ğfalse‚ğ‘ã“ü‚·‚é
		if (shotPosY < 80)
		{
			shotFlag = false;
		}

	}
}

void Shot::Draw()
{
	// Shot‚Ì•\¦ˆÊ’u
	DrawGraph(shotPosX,shotPosY,GtHandle, true);
}
