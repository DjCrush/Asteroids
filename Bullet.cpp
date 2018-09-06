#pragma once
#include "Bullet.h"


Bullet::Bullet(float x, float y, int angle) : x(x), y(y), angle(angle)
{}

Bullet::~Bullet()
{}

void Bullet::Update()
{
	x += sin(angle * DEG) * 5;
	y += -cos(angle * DEG) * 5;
}

void Bullet::Draw()
{
	SetPixel(x, y, 255, 0, 0);
}
float Bullet::GetCoordX()
{
	return x;
}

float Bullet::GetCoordY()
{
	return y;
}