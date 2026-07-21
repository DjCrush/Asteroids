#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include <iostream>
#include <array>
#include <utility>
#define _USE_MATH_DEFINES 
#include <cmath>
using namespace std;

class Ship {
public:
	Ship();
	void render(SDL_Renderer* m_pRenderer) const;
	void setRotate(int rotationDirection);
	void setThrust(bool isAvailable, SDL_Renderer* renderer);
	void update();
	double getCoordX() const;
	double getCoordY() const;
	int getAngle() const;

private:
	double m_dCoordX;
	double m_dCoordY;
	double m_dDX;
	double m_dDY;
	int m_iAngleRotation;
	double m_iSpeed;
	int m_iRotationDirection;
	bool m_bThrust;
	std::array<std::pair<double, double>, 3> m_arPoints;
};

#endif