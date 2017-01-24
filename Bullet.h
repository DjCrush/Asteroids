#pragma once
#include <SDL.h>
#include <vector>
#include "MyGraphicsLib.h"
#include "Player.h"


using namespace std;


extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

typedef struct {
	float x;
	float y;
	int angle;
} bullet_s;


class Player;

class Bullet
{
private:
	float bullet_x, bullet_y;
	int bullet_angle;
	SDL_Surface *screen;
	vector <bullet_s> bullet;

public:

	Bullet(SDL_Surface *screen);
	~Bullet();
	void Update();
	void AddBullet(Player& p);
};



