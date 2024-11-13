#include "DxLib.h"
#include "game.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	//一部のDxlib関数はDxLib_Init()の前に呼ぶ必要がある

	//フルスクリーンではなく、ウインドウモードで開くようになる
	ChangeWindowMode(Game::kDefaultWindowMode);
	//画面サイズ変更
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorBitNum);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	//ここに書くと一瞬フルスクリーンになるので書かない
	//ChangeWindowMode(true);
	//SetGraphMode(1280, 720, 32);

	//描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);
	// ここから下に変数を書く
	Player p_player;
	p_player.Init();
	Enemy e_enemy;
	e_enemy.Init();
	Item i_item;
	i_item.Init();
	
	//ゲームループ
	while (ProcessMessage() == 0) // Windowsが行う処理を待つ
	{

		//今回のループが始まった時間を覚えておく
		LONGLONG time = GetNowHiPerformanceCount();

		//画面全体をクリア
		ClearDrawScreen();

		////ここにゲームの処理を書く
		//DrawCircle(100, 100, 10, 0xFFFF00, TRUE);
		p_player.Update();
		p_player.Draw();
		e_enemy.Update();
		e_enemy.Draw();
		i_item.Update();
		i_item.Draw();
		

		//画面の切り替わりを待つ必要がある
		ScreenFlip();//1/60秒経過するまで待つ

		//FPSを60に固定
		while (GetNowHiPerformanceCount() - time < 16667);
		{

		}
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}