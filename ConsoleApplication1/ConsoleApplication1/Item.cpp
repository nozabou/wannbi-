#include "Item.h"
#include "DxLib.h"

Item::Item()
{
}

Item::~Item()
{
	// •`‰æ‚µ‚½ŠG‚ğÁ‚·
	DeleteGraph(GtHandle);
}

void Item::Init()
{
	// Item‚ÌŠG‚Ìæ“¾
	/*GtHandle = LoadGraph("data/image/Bell.png");*/
}

void Item::Update()
{
}

void Item::Draw()
{
	// Item‚Ì•\¦ˆÊ’u
	DrawGraph(itemX, itemY, GtHandle, true);
}
