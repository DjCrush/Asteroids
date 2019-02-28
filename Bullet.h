#pragma once
#include "MyGraphicsLib.h"
using namespace std;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const double DEG;

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
