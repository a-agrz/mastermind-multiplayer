/*********************************
*       Mastermind- Alpha version*
*                             by *
*			        Edward Halls *
*                                *
*********************************/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

#include"SDL\SDL.h"
#include "cButton.h"
#include "cPlayer.h"
#include "cGameboard.h" 




#define TOTAL_ATT 8 // this is the total amount of attemtps each player will have

// Screen IDs 
#define MAIN_MENU        0
#define GAME_SCREEN   1

//Window's detials
const int SCREEN_WIDTH = 550; 
const int SCREEN_HEIGHT = 450; 
const int SCREEN_BPP = 16;

//Surfaces used to darw in window
SDL_Surface *screen = NULL;
SDL_Surface *background = NULL;
SDL_Surface *message = NULL;

//Vector of buttons used for Gui interface
vector<cButton> buttons;
vector<cButton>::iterator vPointer;

//Structure to hold events from event queue
SDL_Event events;

//An instance of the Video handler that shall
cVideoHandler crayon;

//Array of  pointers to the game textures for rendering
// with the game_sheet and clue sheet arrays
SDL_Surface* textures[15];

// Function declarations
void init(string caption);
void cleanse();
void load_files(int state);

// Beginning of Main function
	int main( int argc, char *argv[] )
	{

		 
		//Create the data for the two separate boards
		cGameboard board[2];

		// An Human player object used to access all human
		//  related tasks.
		 cHumanPlayer *hPlayer= new cHumanPlayer();

		// An Computer player object used to access all AI
		// related tasks.
		 cCompPlayer *cPlayer= new cCompPlayer();
				
		
		 //The following variables are for holding menu and event states
       
		int menu_state = 0;  // Menu state holds the screenID for the current screen being used
		bool files_loaded = true;  //Files_loaded  is used to determine files need to be loaded for a new menu state

		int sequence_pos = 0;  //Position of next entry in the game sheet array(on human player's gameboard) of current gameplay     
		bool sequence_made = true;   // Ensures the computer player generates its Codemaker's code only once at the start of the game

		 // This function call intialises SDL and sets-up the 
		//   work enviroment.
			init("Mastermind-Alpha");			
    
            //Start of  the Game loop, which exits on the event SDL_Quit
			while(1)
			{
                  
				// Loads Files  for a particular menu state( different screen setups)
				//  if they havent already been loaded

				 if(files_loaded)
						  {
							load_files(menu_state);
							   files_loaded = false;
						  }
			
				              
				             // Render BEGIN- Start of the rednering section of code
 
								   // Prints a background to the screen
				   //cout << "1why is it all the way out here!!!";
				                    crayon.print_surface(0,0,screen,background, NULL);

				                      // This loops through all buttons and draws them to screen , whilst also looping through
				                      // the textures array to draw non button related images to represent the gameboard
									 vPointer = buttons.begin();
									 for(int t=0; t<( int)buttons.size(); t++,vPointer++ )
										 {    
													
														 if(menu_state == MAIN_MENU)
														 {
													    // Draws  the buttons for the first two menus
															// cout << "2why is it all the way out here!!!";
														crayon.print_surface( vPointer->box.x, vPointer->box.y,screen,vPointer->button, &vPointer->clip[0]);
														
														}
														 else 
														 {
															 
																		if(t<6)	
																		 {
																			 
																			    // Draws  the peg selection buttons for the game menu
																			// cout << "3why is it all the way out here!!!";
                                												crayon.print_surface( vPointer->box.x, vPointer->box.y,screen,vPointer->button, &vPointer->clip[0]);
																	
																				
																		  }
																		else if(t>=8)
																		{
                                                                               // Draws  the menu style buttons for the game menu
																			 // cout << "4why is it all the way out here!!!";
                                                                               crayon.print_surface( vPointer->box.x, vPointer->box.y,screen,vPointer->button, &vPointer->clip[0]);
																				
																				 
																		}
																		else if( t >=13)
																		{
                                                                             crayon.print_surface( vPointer->box.x, vPointer->box.y,screen,vPointer->button, &vPointer->clip[0]);
																		}
	
																				//Draws the game board  
																				for(int i=0, y =SCREEN_HEIGHT-50 ; i<TOTAL_ATT; i++, y-=50)
																					 { 
																						  
															 										for(int j=0, x=0 ; j<5; j++, x+=50 )
																									{ 
																											if(j<4)
																											{
																												// Draws the main peg section of the game board  
																												//cout << "5why is it all the way out here!!!/n";
																												//cout << "Game sheet value used is"<< game_sheet[i][j] << "in position i  j" << i <<" " << j <<"/n" ;
																													crayon.print_surface( x, y,screen,textures[board[0].game_sheet[i][j]], NULL);
																											}
																											else if(j==4)
																											{
																												 // Draws the clue peg section of the game board 
																											//	cout << "6why is it all the way out here!!!";
																													crayon.print_surface( x, y,screen,textures[board[0].clue_sheet[i][0]], NULL);
																													crayon.print_surface( x+25, y,screen,textures[board[0].clue_sheet[i][1]], NULL);
																													crayon.print_surface( x, y+25,screen,textures[board[0].clue_sheet[i][2]], NULL);
																													crayon.print_surface( x+25, y+25,screen,textures[board[0].clue_sheet[i][3]], NULL);
																											}
																								
																									}
																					
																						  }

																				      																				//Draws the game board  
																				for(int i=0, y =SCREEN_HEIGHT-50 ; i<TOTAL_ATT; i++, y-=50)
																					 { 
																						  
															 										for(int j=0, x=300 ; j<5; j++, x+=50 )
																									{ 
																											if(j<4)
																											{
																												// Draws the main peg section of the game board  
																												//cout << "5why is it all the way out here!!!/n";
																												//cout << "Game sheet value used is"<< game_sheet[i][j] << "in position i  j" << i <<" " << j <<"/n" ;
																													crayon.print_surface( x, y,screen,textures[board[1].game_sheet[i][j]], NULL);
																											}
																											else if(j==4)
																											{
																												 // Draws the clue peg section of the game board 
																											//	cout << "6why is it all the way out here!!!";
																													crayon.print_surface( x, y,screen,textures[board[1].clue_sheet[i][0]], NULL);
																													crayon.print_surface( x+25, y,screen,textures[board[1].clue_sheet[i][1]], NULL);
																													crayon.print_surface( x, y+25,screen,textures[board[1].clue_sheet[i][2]], NULL);
																													crayon.print_surface( x+25, y+25,screen,textures[board[1].clue_sheet[i][3]], NULL);
																											}
																								
																									}
																					
																						  }

														                  }
																				    																															
											 }
                                      
									  // Render END - End of the rendering section
									
									 // Return the  vector pointer back to start of the buttons vector for use later
									// cout << "7why is it all the way out here!!!";
									 vPointer = buttons.begin();

              // Events Start - Start of the event handling section

             // Loops through all pending events,
			//  if there are no more pending events  the loop ends
		// cout << "8why is it all the way out here!!!";
            while(SDL_PollEvent(&events))
			{
                  
                //Loops and monitos all buttons in existences and performs tasks when they are clicked
				// Note: that i is used to tell which button was pressed in certain menu states
				//cout << "9why is it all the way out here!!!";
                for( int i=0; i<( int)(buttons.size()) ; i++, vPointer++ )
				   {
                                
				                 // If the button is pressed, the function will return 10,  then perform that button's operations 
								 if (vPointer->event_handler())
								 { 
									
									 // Uses th current menu state to sort out which tasks to perform
									 // for the specific button at variable i  in that menu
									 switch(menu_state)
									 {
									 case 0:
													  switch(i)
													 {
														 // Start game
														 case 0:
														
														    menu_state = GAME_SCREEN;
															files_loaded = true;
															hPlayer->cBreak = new cCodeBreaker();
															cPlayer->cMake = new cCodeMaker();
															hPlayer->cMake = new cCodeMaker();
															cPlayer->cBreak = new cCodeBreaker();
															 break;

													    //Exit game
														 case 1:
															cleanse();
															 return 0;
															 break;

															 
														 default:
															 break;

													  }
										 break;

									 case 1:
										 	  switch(i)
									     {
											 // Coloured peg buttons
											 // Performs the function of entering pegs into the current gameplay position
											 case 0:
											 case 1:
											 case 2:
											 case 3:
											 case 4:
										     case 5:
												 if(!(sequence_made))
												 {
														 if(sequence_pos ==4)
														 {
															 sequence_pos=0;
															
														 }
														 board[0].game_sheet[( TOTAL_ATT- ((hPlayer->cBreak)->attempts_rem))][sequence_pos] =  i;
														 sequence_pos++;
											
												 }
												 else if(sequence_made)
												 { 												 
														 if(sequence_pos ==4)
														 {
															 sequence_pos=0;
															
														 }
														 board[1].game_sheet[0][sequence_pos] =  i;
														 sequence_pos++;
														 
												 }
                                                 break;

                                              // End the turn and perform sequence funtions for players( checking ,etc.)
											 case 8:
												
											        
													    if(sequence_made)
														{
													        cPlayer->make_sequence();
															(hPlayer->cMake)->enter_sequence(board[1].game_sheet);
														}
                                                             if(!(sequence_made))
															 {
                                                         cPlayer->guess_sequence(board[1].game_sheet, board[1].clue_sheet);

													     int  check_one = ((cPlayer->cMake)->check_sequence(board[0].game_sheet, (hPlayer->cBreak)->attempts_rem));
														 int check_two = (hPlayer->cMake)->check_sequence(board[1].game_sheet, (cPlayer->cBreak)->attempts_rem);
													         cout <<"\nThis is the comp sequence"<< (cPlayer->cMake)->the_code[0] << (cPlayer->cMake)->the_code[1]  << (cPlayer->cMake)->the_code[2]  << (cPlayer->cMake)->the_code[3]  ;
																																					      																																	
                                                               //cout << "12why is it all the way out here!!!";
                                                              cout <<"\nThis is the human sequence"<< (hPlayer->cMake)->the_code[0] << (hPlayer->cMake)->the_code[1]  << (hPlayer->cMake)->the_code[2]  << (hPlayer->cMake)->the_code[3] ;
													         
												               
															   // cout << "13why is it all the way out here!!!";
															  if(check_two ==1 && check_one ==0)
															   {
                                                                  cout << "\nyou have lost!!!";
															   }
															  else if(check_one ==1 && check_two ==0)
															  {
                                                                        cout << "\nyou have won!!";
															  }
															   else if((cPlayer->cBreak)->attempts_rem ==0)
															   {
                                                                   cout << "\nyou have a draw!!!";
															   }
															   else
															   {

																   	//	   cout << "im inside the last else!!!/n";
															//	   cout << "handle clues function implemented by cPlayer is the problem if stopped here!!!";
                                                               (cPlayer->cMake)->handle_clues(board[0].game_sheet,board[0].clue_sheet, (hPlayer->cBreak)->attempts_rem);
														//		   cout << "hplayer decrementing is the problem if stopped here!!!";
																	  ((hPlayer->cBreak)->attempts_rem)--;

                                                             //cout << "13why is it all the way out here!!!";
                                                              (hPlayer->cMake)->handle_clues(board[1].game_sheet,board[1].clue_sheet, (cPlayer->cBreak)->attempts_rem);
								                              ((cPlayer->cBreak)->attempts_rem)--;
															  sequence_pos=0;
															 // cout << "14why is it all the way out here!!!";
															   }

															 }
														 
												         sequence_made = false;
											
										         break;

											 case 9:
												  // Save game
										         break;

											 case 10:
												 // Exit game to main menu
												 menu_state = MAIN_MENU;
												files_loaded = true;
												sequence_made = true;
												//buttons.clear();
												delete hPlayer;
												delete cPlayer;
										         break;

												 
											 default:
												break;
										  }
										 break;
										 
							            default:
						                   break;
									 }
                 
								 }
						 
				   }

				    // Events END - End of the event handling section

				   // Return the  vector pointer back to start of the buttons vector for use later
		            vPointer = buttons.begin();
			
		              if(events.type != SDL_QUIT)
					  {
							   //Update the screen 
							   if( SDL_Flip(screen) == -1 ) { return 1; }
					  }
					  else
					  {
 
			           cleanse();
					   SDL_Quit();		
					  return 0;

					  }
			}
	  }
		
     // End of Main function
	 return 0;
	}

//Intialises SDL and the window environment
	void init(string caption)
	{

			if ( SDL_Init(SDL_INIT_EVERYTHING ) == -1)
				{

				}
                 //SDL_SetVideoMode creates a window and returns a pointer to the area within the window, referred to as screen from now on
                screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_SWSURFACE);

			   SDL_WM_SetCaption( caption.c_str(), NULL );

			   	//If there was an error in setting up the screen
		   	if( screen == NULL ) 
			{ 
					 cout << "The screen wasnt setup properly";
			}
				

	}

	// Function for loading files for different menu states( passed as state to the function)
	void load_files(int state)
	{
	    
		SDL_Surface* buttonskin;
		background =  crayon.load_pic("background.png");

		if( state ==0)			         
		{
							for(int i=0; i<(int)buttons.size(); i++, vPointer++)
							 { 
							SDL_FreeSurface(vPointer->button);		              
							 }

							 buttons.clear();

			string filename[]= {"menu1_1.png","menu1_2.png" };
						 for(int i=0, y =100; i<2; i++, y+= 70)
							 { 
			       			buttonskin = crayon.load_pic(filename[i]);	
							buttons.push_back(cButton((SCREEN_WIDTH-(buttonskin->w/2))/2,y,150,50,buttonskin , &events, screen,true));
						              
							 }

							 vPointer= buttons.begin();
						//	 cout << "I made it this far wohooo 14";

		}
		else if( state ==1)
		{
			string filename[15]= {"blue_peg.png", "green_peg.png", "oran_peg.png", "purp_peg.png", "teal_peg.png","yel_peg.png", "peg_hole.png", "peg_hole2.png","menu3_1.png", "VS.png","menu3_2.png", "peg_hole3.png", "peg_hole4.png", "human.png", "machine.png" };
			       // This is used when player becomes a the code breaker
		
							for(int i=0; i<(int)buttons.size(); i++, vPointer++)
							 { 
							SDL_FreeSurface(vPointer->button);		              
							 }

							 buttons.clear();
				
                       
						 for(int i=0, z = 50; i<15; i++)
							 { 
						        
			       			     buttonskin = crayon.load_pic(filename[i]);
								 textures[i] = buttonskin;
								 if (i<=5)
								 {
							     buttons.push_back(cButton(250, z ,50,50,buttonskin , &events, screen, true));
								 	z+=50;
								 }
								 else if (i==6)
								 {
                                   buttons.push_back(cButton(0, 0 ,0,0,NULL , &events, NULL, false));
								 }
								 else if (i==7)
								 {
									buttons.push_back(cButton(0, 0 ,0,0,NULL , &events, NULL, false));
								 }
								 else if(i>7 && i<=10)
								 {
									 if( i != 9)
									 {
                                 buttons.push_back(cButton(250,z ,50,50,buttonskin , &events, screen, true));
								 z+=50;
								     }
									 else
									 {
                                      buttons.push_back(cButton(250,0 ,50,50,buttonskin , &events, screen, false));
									 }
								  
								 }
								 else if(i>10 && i<13)
								 {
                                   buttons.push_back(cButton(0, 0 ,0,0,NULL , &events, NULL, false));
								   //just reseting z for 13 onwards
								    if( i == 12)
									{
										z =0;
									}
								 }
								 else if (i>=13)
								 {
                                 buttons.push_back(cButton(z,0 ,250,50,buttonskin , &events, screen, false));
								 z+=300;
								 }
								
						              
							 }
							 vPointer= buttons.begin();               
				

						//	 cout << "I made it this far wohooo 14";

		}
	}

   // Clears up any mess left behind by sdl
  //  In effect handling possible memory leaks
	void cleanse()
	{ 
		vPointer= buttons.begin();      
		SDL_FreeSurface(background);
		for(int i=0; i<(int)buttons.size(); i++, vPointer++)
		{ 
		SDL_FreeSurface(vPointer->button);		              
		 }	

	}

