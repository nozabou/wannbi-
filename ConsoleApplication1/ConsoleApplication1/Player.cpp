#include "Player.h"
#include "DxLib.h"
#include "assert.h"
#include "Shot.h"

Player::Player()
{
}

Player::~Player()
{
	// 取得した絵を消す
	DeleteGraph(GrHandle);

	delete PShot;
}

void Player::Init()
{
	// 絵の取得
	GrHandle = LoadGraph("data/image/Player.png");
	PShot = new Shot();
}

void Player::Update()
{
	// キャラクターの操作
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
	// スペースキーが押されたら弾を発射する
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		/// shotFlagがfalseの場合発動する
		if (PShot->shotFlag == false)
		{
			int Playerw, Playerh, Shotw, Shoth;
			///  画像のサイズ
			GetGraphSize(GrHandle, &Playerw, &Playerh);
			GetGraphSize(PShot->GtHandle, &Shotw, &Shoth);
			/// 弾の出る場所のX座標を指定
			PShot->shotPosX = (Playerw - Shotw) / 2 + playerPosX;
			/// 弾の出る場所のY座標を指定
			PShot->shotPosY = (Playerh - Shoth) / 2 + playerPosY;
			/// shotFlagにtrueを代入する
			PShot->shotFlag = true;
		}
	}
	/// プレイヤーが画面の左端を超えないようにする
	if (playerPosX < 0)
	{
		playerPosX = 0;
	}
	/// 画面の右端を超えないようにする
	if (playerPosX > 730 - 64)
	{
		playerPosX = 730 - 64;
	}
	// 画面の上を超えないようにする
	if (playerPosY < 0)
	{
		playerPosY = 0;
	}
	/// 画面の下を超えないようにする
	if (playerPosY > 730 - 64)
	{
		playerPosY = 730 - 64;
	}

}

void Player::Draw()
{
	// Playerの表示位置
	DrawGraph(playerPosX,playerPosY,GrHandle,true);
}
