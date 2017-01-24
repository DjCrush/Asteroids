#pragma once
#include <SDL.h>

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const int BPP;
extern const int DEPTH;

void SetPixel(SDL_Surface *screen, int x, int y, Uint8 r, Uint8 g, Uint8 b);
void DrawLine(SDL_Surface *screen, int x1, int y1, int x2, int y2, Uint8 r, Uint8 g, Uint8 b);
void ClearScreen(SDL_Surface *screen);