#include "Item.h"
#include "DxLib.h"

Item::Item()
{
}

Item::~Item()
{
	// �`�悵���G������
	DeleteGraph(GtHandle);
}

void Item::Init()
{
	// Item�̊G�̎擾
	/*GtHandle = LoadGraph("data/image/Bell.png");*/
}

void Item::Update()
{
}

void Item::Draw()
{
	// Item�̕\���ʒu
	DrawGraph(itemX, itemY, GtHandle, true);
}
