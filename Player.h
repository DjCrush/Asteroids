#pragma once
#include <cmath>
#include <array>
#include "MyGraphicsLib.h"
using namespace std;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const float DEG;

class Player {
public:
	Player();
	~Player();
	void Update();
	void Rotate(int direction_rotate);
	void Move();
	float GetCoordX();
	float GetCoordY();
	int GetAngle();
private:
	struct PointXY 
	{
		float x, y;
	};
	array<PointXY, 3> points;
	float x, y;
	int speed, angle;
};


