#pragma once
#include "Bullet.h"

Bullet::Bullet(double x, double y, int angle) : x(x), y(y), angle(angle) {}

void Bullet::Update()
{
	x += sin(angle * DEG) * 5;
	y += -cos(angle * DEG) * 5;
}

void Bullet::Draw()
{
	SetPixel(x, y, 255, 0, 0);
}

double Bullet::GetCoordX()
{
	return x;
}

double Bullet::GetCoordY()
{
	return y;
}
