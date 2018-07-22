#include <iostream>
#include <math.h>
#include <cmath>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>
#include <stack>
#include <array>
#include <ctime>
#include <queue>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>
#include <string>

using namespace std;
typedef array<array<int,2>,2> mat2;
typedef queue<array<int,2>> cola2;
typedef vector<array<int,2>> vec2;
typedef array<int,2> arr2;
typedef array<array<int,19>,19> mat19;

struct nodo {    			// This is the board i.e. the game status
 array<array<int,19>,19> tablero;	// Board Status
 array<int,2> p1,p2;			// Postions
 int d1,d2;				// Minimum distances to objective
 int walles1;
 int walles2;
};

extern int m;
extern nodo a;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern bool mini1;

//The window we'll be rendering to
extern SDL_Window* gWindow;

//The window renderer
extern SDL_Renderer* gRenderer;
