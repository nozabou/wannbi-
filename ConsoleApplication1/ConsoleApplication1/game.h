#pragma once

namespace Game//属性
{
	//画面の大きさを定数定義
	constexpr int kScreenWidth = 720;
	constexpr int kScreenHeight = 720;
	constexpr int kColorBitNum = 32;

	constexpr bool kDefaultWindowMode = true;

	//画面の中心
	constexpr int kScreenWidthCenter = kScreenWidth / 2;
	constexpr int kScreenHeightCenter = kScreenHeight / 2;
}

//基本16:9 (4:3もOK)
//このサイズ以外は特別な理由がない限り基本ダメ
#pragma once
