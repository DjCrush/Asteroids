#include "MyGraphicsLib.h"

void ClearScreen(SDL_Surface *screen)
{
	SDL_Rect desc;
	desc.x = 0;
	desc.y = 0;
	desc.w = SCREEN_WIDTH - 1;
	desc.h = SCREEN_HEIGHT - 1;
	SDL_FillRect(screen, &desc, 0);
}

void DrawLine(SDL_Surface *screen, int x1, int y1, int x2, int y2, Uint8 r, Uint8 g, Uint8 b)
{
	const int deltaX = abs(x2 - x1);
	const int deltaY = abs(y2 - y1);
	const int signX = x1 < x2 ? 1 : -1;
	const int signY = y1 < y2 ? 1 : -1;

	int error = deltaX - deltaY;

	SetPixel(screen, x2, y2, r, g, b);
	while (x1 != x2 || y1 != y2)
	{
		SetPixel(screen, x1, y1, r, g, b);
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

void SetPixel(SDL_Surface *screen, int x, int y, Uint8 r, Uint8 g, Uint8 b)
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