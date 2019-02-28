#include "Player.h"

Player::Player() : angle(0), speed(0), x(SCREEN_WIDTH / 2), y(SCREEN_HEIGHT / 2), points{ 0.0, 20.0, -7.0, -10.0, 7.0, -10.0}
{}

void Player::Update()
{
	DrawLine(points[0].x + x, points[0].y + y, points[1].x + x, points[1].y + y, 0, 255, 0);
	DrawLine(points[1].x + x, points[1].y + y, points[2].x + x, points[2].y + y, 0, 255, 0);
	DrawLine(points[2].x + x, points[2].y + y, points[0].x + x, points[0].y + y, 0, 255, 0);
}

void Player::Rotate(int direction_rotate)
{
	double xt, rad;
	angle += direction_rotate;
	if (angle > 359)
	{
		angle = 0;
	}
	if (angle < 0)
	{
		angle = 359;
	}
	if (direction_rotate > 0)
	{
		rad = DEG;
	}
	else 
	{
		rad = -DEG;
	}
	for (int i = 0; i < 3; i++)
	{
		xt = points[i].x * cos(rad) - points[i].y * sin(rad);
		points[i].y = points[i].x * sin(rad) + points[i].y * cos(rad);
		points[i].x = xt;
	}
}

void Player::Move()
{
	x += sin(angle * DEG);
	y += -cos(angle * DEG);
}

double Player::GetCoordX()
{
	return x;
}

double Player::GetCoordY()
{
	return y;
}

int Player::GetAngle()
{
	return angle;
}
