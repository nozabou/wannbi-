#pragma once
class Shot
{
public:
	Shot();
	~Shot();
	void Init();
	void Update();
	void Draw();
	int shotX;
	int shotY;
	int shotFlag;
private:
};

