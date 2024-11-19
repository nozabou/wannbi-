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
	// 取得した絵を消す
	DeleteGraph(GrHandle);
	delete PEnemy;
	delete PShot;
}

void Player::Init()
{
	// 絵の取得
	GrHandle = LoadGraph("data/image/Player.png");
	PShot = new Shot();
	PEnemy = new Enemy();
}

void Player::Update()
{
	// キャラクターの操作
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
	// スペースキーが押されたら弾を発射する
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		/// shotFlagがfalseの場合発動する
		if (PShot->shotFlag == false)
		{ 
			int PlayerW, PlayerH, ShotW, ShotH;
			///  画像のサイズ
   			GetGraphSize(GrHandle, &PlayerW, &PlayerH);
			GetGraphSize(PShot->GtHandle, &ShotW, &ShotH);
			/// 弾の出る場所のX座標を指定
			PShot->shotPosX = (PlayerW - ShotW) / 2 + playerPosX;
			/// 弾の出る場所のY座標を指定
			PShot->shotPosY = (PlayerH - ShotH) / 2 + playerPosY;
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
	if (playerPosX > 680)
	{
		playerPosX = 680;
	}
	// 画面の上を超えないようにする
	if (playerPosY < 0)
	{
		playerPosY = 0;
	}
	/// 画面の下を超えないようにする
	if (playerPosY > 740 - 64)
	{
		playerPosY = 740 - 64;
	}
	// 当たり判定(仮)
	int a = (playerPosX + (playerSize / 2)) - PEnemy->BulletX;
	int b = (playerPosY + (playerSize / 2)) - PEnemy->BulletY;
	int sum = sqrt(pow(a, 2) + pow(b, 2));
	//当たっていたらbreakでゲームを終了
	if (sum <= (playerSize / 2) + PEnemy->BulletR) 
	{
		DeleteGraph(GrHandle);
	}
	
}

void Player::Draw()
{
	// Playerの表示位置
	DrawGraph(playerPosX,playerPosY,GrHandle,true);
}
