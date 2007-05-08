
#include "cVideoHandler.h"

using namespace std;

class cButton {
  
public:
	    cVideoHandler crayon;
		SDL_Rect clip[2];
		SDL_Rect box;
		SDL_Surface *button;
		SDL_Surface *screen;
		SDL_Event* events;
		bool enabled;
		cButton(int x, int y, int w, int h,SDL_Surface* skin, SDL_Event* eventpass, SDL_Surface* window, bool status);
		//~cButton(){SDL_FreeSurface(button);};	  
		bool event_handler();

	

		 
};