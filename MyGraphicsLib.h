#pragma once
#include <SDL.h>
using namespace std;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const int BPP;
extern const int DEPTH;
extern SDL_Surface* screen;

struct vertex
{
	float x;
	float y;
};

void SetPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b);
void DrawLine(int x1, int y1, int x2, int y2, Uint8 r, Uint8 g, Uint8 b);
void ClearScreen();