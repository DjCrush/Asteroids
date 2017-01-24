#include <SDL.h>
#include "Player.h"


Player::Player(SDL_Surface *screen)
{
	coordX[0] = 0;
	coordX[1] = 15;
	coordX[2] = 0;
	coordX[3] = -15;
	coordY[0] = -30;
	coordY[1] = 30;
	coordY[2] = 15;
	coordY[3] = 30;
	angle = 0;
	speed = 0;
	player_x = SCREEN_WIDTH / 2;
	player_y = SCREEN_HEIGHT / 2;
	this->screen = screen;

}

Player::~Player()
{

}

void Player::Update()
{
	DrawLine(screen, coordX[0] + player_x, coordY[0] + player_y, coordX[1] + player_x, coordY[1] + player_y, 0, 255, 0);
	DrawLine(screen, coordX[1] + player_x, coordY[1] + player_y, coordX[2] + player_x, coordY[2] + player_y, 0, 255, 0);
	DrawLine(screen, coordX[2] + player_x, coordY[2] + player_y, coordX[3] + player_x, coordY[3] + player_y, 0, 255, 0);
	DrawLine(screen, coordX[3] + player_x, coordY[3] + player_y, coordX[0] + player_x, coordY[0] + player_y, 0, 255, 0);
}

void Player::Rotate(int direction_rotate)
{
	float xt, rad;
	angle += direction_rotate;
	if (angle > 359) angle = 0;
	if (angle < 0)   angle = 359;
	if (direction_rotate > 0) rad = 0.01745329251994329576923690768489f; else rad = -0.01745329251994329576923690768489f;


	for (int i = 0; i < 4; i++)
	{
		xt = coordX[i] * cos(rad) - coordY[i] * sin(rad);
		coordY[i] = coordX[i] * sin(rad) + coordY[i] * cos(rad);
		coordX[i] = xt;
	}



}

void Player::Move()
{
	player_x += sin(angle * M_PI / 180);
	player_y += -cos(angle * M_PI / 180);
}

float Player::GetCoordX()
{
	return player_x;
}

float Player::GetCoordY()
{
	return player_y;
}

int Player::GetAngle()
{
	return angle;
}