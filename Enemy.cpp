#include "Enemy.h"

Enemy::Enemy() : x{ rand() % SCREEN_WIDTH }, y{ rand() % SCREEN_HEIGHT }, 
				 angle{ rand() % 360 }, type{1}, points{ {0, 10}, {0, 20}, {10, 30}, {10, 20}, {20, 30}, {30, 20} } 
{}

void Enemy::Draw()
{
	for (int i = 1; i < points.size(); ++i)
	{
		DrawLine(points[i - 1].x + x, points[i - 1].y + y, points[i].x + x, points[i].y + y, 255, 255, 0);
	}
}
void Enemy::Update()
{
	x += sin(angle * M_PI / 180);
	y += -cos(angle * M_PI / 180);
	if (x > SCREEN_WIDTH) x -= SCREEN_WIDTH;
	if (x < 0) x += SCREEN_WIDTH;
	if (y > SCREEN_HEIGHT) y -= SCREEN_HEIGHT;
	if (y < 0) y += SCREEN_HEIGHT;
}
