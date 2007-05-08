#include "cVideoHandler.h"



SDL_Surface* cVideoHandler::load_pic(string pic)
	{

          SDL_Surface* loadedimage = NULL;

		  SDL_Surface* fixedimage = NULL;

		  loadedimage = IMG_Load(pic.c_str());

		  if(loadedimage !=  NULL)
		  {
				  

				  fixedimage = SDL_DisplayFormat(loadedimage);

		  }

		  SDL_FreeSurface(loadedimage);

		  return fixedimage;

	}



void cVideoHandler::print_surface(int x, int y, SDL_Surface* dest, SDL_Surface* source, SDL_Rect* clip)
	{
        SDL_Rect offset;

		offset.x = x;
		offset.y = y;

		SDL_BlitSurface(source, clip, dest, &offset);
	}
