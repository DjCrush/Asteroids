#pragma once
#include "Bullet.h"


Bullet::Bullet(SDL_Surface *screen)
{
	this->screen = screen;
}

Bullet::~Bullet()
{

}

void Bullet::AddBullet(Player& p)
{
	bullet_x = p.GetCoordX();
	bullet_y = p.GetCoordY();
	bullet_angle = p.GetAngle();

	bullet_x += sin(bullet_angle * M_PI / 180) * 30;
	bullet_y += -cos(bullet_angle * M_PI / 180) * 30;

	bullet.push_back({ bullet_x, bullet_y, bullet_angle });

}

void Bullet::Update()
{

		
	for (int i = 0; i < bullet.size(); i++)
	{
		SetPixel(screen, bullet[i].x, bullet[i].y, 255, 255, 255);

		bullet[i].x += sin(bullet[i].angle * M_PI / 180) * 2;
		bullet[i].y += -cos(bullet[i].angle * M_PI / 180) * 2;
		if (bullet[i].x >(SCREEN_WIDTH) || bullet[i].x<0 || bullet[i].y>(SCREEN_HEIGHT - 1) || bullet[i].y < 0)
			bullet.erase(bullet.begin() + i);

	}

	


}