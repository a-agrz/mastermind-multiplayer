#include "SDL\SDL_image.h"
#include <string>

using namespace std;

class cVideoHandler {

     public:
    cVideoHandler(){ };
	SDL_Surface* load_pic(string pic);
    void print_surface(int x, int y, SDL_Surface* dest, SDL_Surface* source, SDL_Rect* clip = NULL);
};