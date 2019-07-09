#include "GraphicsLib.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int BPP = 4;
const int DEPTH = 32;
const float DEG = 0.01745329251994329576923690768489f;

void ClearScreen()
{
	SDL_Rect desc = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	SDL_FillRect(screen, &desc, 0);
}

//Drawing a line using the Brezenheim algorithm
void DrawLine(int x1, int y1, int x2, int y2, Uint8 r, Uint8 g, Uint8 b)
{
	const int deltaX = abs(x2 - x1);
	const int deltaY = abs(y2 - y1);
	const int signX = x1 < x2 ? 1 : -1;
	const int signY = y1 < y2 ? 1 : -1;
	int error = deltaX - deltaY;
	SetPixel(x2, y2, r, g, b);
	while (x1 != x2 || y1 != y2)
	{
		SetPixel(x1, y1, r, g, b);
		const int error2 = error * 2;
		if (error2 > -deltaY)
		{
			error -= deltaY;
			x1 += signX;
		}
		if (error2 < deltaX)
		{
			error += deltaX;
			y1 += signY;
		}
	}
}

void SetPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b)
{
	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{
		Uint32 *pixmem32;
		Uint32 colour;
		int ytimesw = y*screen->pitch / BPP;
		colour = SDL_MapRGB(screen->format, r, g, b);
		pixmem32 = (Uint32*)screen->pixels + ytimesw + x;
		*pixmem32 = colour;
	}
}
