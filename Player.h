#pragma once
#include <cmath>
#include <array>
#include "GraphicsLib.h"
using namespace std;

class Player {
public:
	Player();
	void Update();
	void Rotate(int direction_rotate);
	void Move();
	float GetCoordX();
	float GetCoordY();
	int GetAngle();
private:
	array<pair<double x, y>, 3> points;
	double x, y;
	int speed, angle;
};
