#include "Shot.h"
#include "DxLib.h"

Shot::Shot()
{
}

Shot::~Shot()
{
	// 取得した絵を消す
	DeleteGraph(GtHandle);
}

void Shot::Init()
{
	// 絵の取得
	GtHandle = LoadGraph("data/image/Player.png");
}

void Shot::Update()
{
	if (shotFlag)
	{
		// 弾が上方向に16ずつ進む
		shotPosY -= 16;
		// shotPosYが-80より小さくなったら発動してshotFlagをfalseを代入する
		if (shotPosY < 80)
		{
			shotFlag = false;
		}

	}
}

void Shot::Draw()
{
	// Shotの表示位置
	DrawGraph(shotPosX,shotPosY,GtHandle, true);
}
