#pragma once
#include <SDL.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

class Asteroid
{

public:
	Asteroid(SDL_Renderer* renderer, int x, int y, int radius);
	void update();
	double getCoordX() const;
	double getCoordY() const;
	int getRadius() const;
	void render() const;

private:
	SDL_Renderer* m_pRenderer;
	double m_dCoordX;
	double m_dCoordY;
	double m_ddX;
	double m_ddY;
	int m_iRadius;
};

