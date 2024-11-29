#include "DxLib.h"
#include "game.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
#include "Shot.h"


// 四角形の判定チェック
bool IsCheckHit(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	if (x2 < x3) return false;
	if (x1 > x4) return false;
	if (y2 < y3) return false;
	if (y1 > y4) return false;

	return true;
}

class Player;
class Enemy;
class Item;
class Shot;
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
	Player* p_player = new Player();
	p_player->Init();
	Enemy* p_enemy = new Enemy();
	p_enemy->Init();
	Item* p_item = new Item();
	p_item->Init();
	Shot* p_shot[256];
	for (int i = 0; i < 256; i++)
	{
		p_shot[i] = new Shot;
	}
	for (int i = 0; i < 256; i++)
	{
		p_shot[i]->Init();
	}
	int x[5] = {0,1,2,3,4};

	bool isEnemyDead = false;

	//ゲームループ
	while (ProcessMessage() == 0) // Windowsが行う処理を待つ
	{

		//今回のループが始まった時間を覚えておく
		LONGLONG time = GetNowHiPerformanceCount();

		//画面全体をクリア
		ClearDrawScreen();

		//ここにゲームの処理を書く
		p_player->Update();
		p_player->Draw();
		p_enemy->Update();
		if (!isEnemyDead)
		{
			p_enemy->Draw();
		}
		p_item->Update();
		p_item->Draw();
		for (int i = 0; i < 256; i++)
		{
			if (!p_shot[i]->GetShotFlag())
			{
				if (p_player->GetShootFlag())
				{
					p_shot[i]->SetShotFlag(true);
					p_player->GetShootPos();
					p_shot[i]->SetPos(p_player->GetShootPos());
					break;
				}
			}
		}
		for (int i = 0; i < 256; i++)
		{
			p_shot[i]->Update();
			bool isHit = IsCheckHit(
				p_shot[i]->GetPos().X,
				p_shot[i]->GetPos().Y,
				p_shot[i]->GetPos().X + p_shot[i]->GetSize(),
				p_shot[i]->GetPos().Y + p_shot[i]->GetSize(),
				p_enemy->GetPosX(),
				p_enemy->GetPosY(),
				p_enemy->GetPosX() + p_enemy->GetSize(),
				p_enemy->GetPosY() + p_enemy->GetSize());

			if (isHit)
			{
				isEnemyDead = true;
			}
		}
		for (int i = 0; i < 256; i++)
		{
			p_shot[i]->Draw();
		}
		
		
		

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