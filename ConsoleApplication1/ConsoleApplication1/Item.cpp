#include "Item.h"
#include "DxLib.h"

Item::Item()
{
}

Item::~Item()
{
	// 描画した絵を消す
	DeleteGraph(graphicHandle);
}

void Item::Init()
{
	// Itemの絵の取得
	/*GtHandle = LoadGraph("data/image/Bell.png");*/
}

void Item::Update()
{
}

void Item::Draw()
{
	// Itemの表示位置
	DrawGraph(itemX, itemY, graphicHandle, true);
}
