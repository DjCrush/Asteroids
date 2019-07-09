#pragma once
#include "GraphicsLib.h"
#include <iostream>
#include <vector>
using namespace std;

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
	vector<pair<double, double>> points;
};
