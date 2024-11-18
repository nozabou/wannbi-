#pragma once
class Shot
{
public:
	Shot();
	~Shot();
	void Init();
	void Update();
	void Draw();
	int shotPosX = 100;
	int shotPosY = 300;
	int GtHandle;
	bool shotFlag = false;
private:
};

