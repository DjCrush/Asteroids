#ifndef BULLET_H
#define BULLET_H

#include <SDL.h>
#include <cmath>
#include "Ship.h"

class Bullet
{
public:
	Bullet(SDL_Renderer* m_pRenderer, double dX, double dY, int nAngle);
	void render() const;
	void update();
	double getCoordX() const;
	double getCoordY() const;
private:
	SDL_Renderer* m_pRenderer;
	double m_dCoordX;
	double m_dCoordY;
	int m_iAngle;
};

#endif