#pragma once
class Item
{
public:
	Item();
	~Item();
	void Init();
	void Update();
	void Draw();
	// �A�C�e���̉摜�擾�ϐ�
	int graphicHandle;
	// �A�C�e���̕\���ʒu�̕ϐ�
	int itemX = 300;
	int itemY = 300;
private:
};

