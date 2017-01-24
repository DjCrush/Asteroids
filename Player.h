#pragma once
#include <SDL.h>
#include <SDL_audio.h>
#include <iostream>
#define _USE_MATH_DEFINES 
#include <math.h>
#include "MyGraphicsLib.h"


using namespace std;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

class Player {

public:
	Player(SDL_Surface *screen);
	~Player();
	void Update();
	void Rotate(int direction_rotate);
	void Move();
	float GetCoordX();
	float GetCoordY();
	int GetAngle();

private:
	int angle;
	float coordX[4];
	float coordY[4];
	float player_x;
	float player_y;
	int speed;
	SDL_Surface *screen;

};


