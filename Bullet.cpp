#include "Bullet.h"

Bullet::Bullet(SDL_Renderer* pRenderer, double dX, double dY, int nAngle) : 
	m_pRenderer(pRenderer), m_dCoordX(dX), m_dCoordY(dY), m_iAngle(nAngle) {}

void Bullet::update()
{
	m_dCoordX += sin(m_iAngle * M_PI / 180);
	m_dCoordY += -cos(m_iAngle * M_PI / 180);
}

double Bullet::getCoordX() const
{
	return m_dCoordX;
}

double Bullet::getCoordY() const
{
	return m_dCoordY;
}

void Bullet::render() const
{
	SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawPoint(m_pRenderer, m_dCoordX, m_dCoordY);
}
