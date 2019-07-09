#pragma once
#include "GraphicsLib.h"
using namespace std;

class Bullet
{
public:
	Bullet(double x, double y, int angle);
	void Draw();
	void Update();
	double GetCoordX();
	double GetCoordY();
private:
	double x, y;
	int angle;
};
