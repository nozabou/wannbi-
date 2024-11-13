#pragma once
class Item
{
public:
	Item();
	~Item();
	void Init();
	void Update();
	void Draw();
	// アイテムの画像取得変数
	int GtHandle;
	// アイテムの表示位置の変数
	int itemX = 300;
	int itemY = 300;
private:
};

