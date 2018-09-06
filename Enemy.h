#pragma once
#include "MyGraphicsLib.h"
#include <iostream>
#include <vector>
using namespace std;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

class Enemy {
public:
	Enemy();
	~Enemy();
	void Draw();
	void Update();
private:
	float x, y;
	int angle;
	int type;
	struct PointXY
	{
		float x, y;
	};
	vector<PointXY> points;
};

