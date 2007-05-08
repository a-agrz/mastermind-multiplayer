#include"cButton.h"
#include<iostream>

cButton::cButton(int x, int y, int w, int h, SDL_Surface* skin, SDL_Event* eventpass, SDL_Surface* window, bool status)
{
	screen = window;
	events = eventpass;
	button = skin;
	enabled = status;

    box.x = x;
	box.y = y;
	box.w=w;
	box.h = h;

	// Buttons image clipping values

	clip[0].x = 0;
	clip[0].y =0;
	clip[0].w= w;
	clip[0].h =h;

    clip[1].x = w+1;
	clip[1].y =0;
	clip[1].w= w;
	clip[1].h =h;

};



bool cButton::event_handler()
{
	
	int x, y;
	bool n = false;
    
		if((events->type == SDL_MOUSEMOTION) )
		{

			 x = events->motion.x;
			 y =events->motion.y;
						if( x>= box.x && x<= (box.x+box.w) && y>= box.y && y<= (box.y+box.h))
					{
                         crayon.print_surface(box.x,box.y,screen,button,&clip[1]);
					}


		}

		if((events->type == SDL_MOUSEBUTTONDOWN))
		{
		       x= events->button.x;
			   y= events->button.y;

			   		if(x>= box.x && x<= (box.x+box.w) && y>= box.y && y<= (box.y+box.h))
					{
						n = true;
                          crayon.print_surface(box.x,box.y,screen,button,&clip[1]);
						 SDL_Flip(screen);
						  SDL_Delay(10);
						  crayon.print_surface(box.x,box.y,screen,button,&clip[0]);
						  SDL_Flip(screen);
						   SDL_Delay(10);
					  crayon.print_surface(box.x,box.y,screen,button,&clip[1]);
						  SDL_Flip(screen);
					  
					}


		}

		   return n;
	

}

