#include "cPlayer.h"
#define TOTAL_ATT 8 // this is the total amount of attemtps each player will have
#define WHITE 11 //White clue peg, meaning correct peg , but wrong position
#define  BLACK_SPOT 12 // White clue peg with black spot, meaning right postition and colour
#define EMPTY 7 // No clue peg meaning this postion has a useless peg

void cCompPlayer::make_sequence()
{
	

	for(int i =0;i<4;i++)
	{
		srand(time(0) + i);
		cMake->the_code[i] =  (rand()%6);

	}
	
	
};   


void cCompPlayer::guess_sequence(int (*iCode)[4],int (*iClue)[4])
{
	int security[4];
	int current_pos =TOTAL_ATT - ( cBreak->attempts_rem);

	if (current_pos == 0)
	{
			for(int i =0;i<4;i++)
				{
					srand(time(NULL) + i);
					iCode[current_pos][i]=  (rand()%6);

				}
	}
	else
	{
	//	 int pervious_code_hold[4];
		   // Lock any position that  is in the correct place and color, also save temp postion of previous  code
                for(int i =0;i<4;i++)
				{
				//	pervious_code_hold[i] = iCode[current_pos-1][i]; 

                    if( iClue[current_pos-1][i] == BLACK_SPOT)
					{ 
						security [i] = 1;
					}
					else 
					{
                       security [i] = 0;
					}
				}

				// Loop through the previous sequences and make a new unique sequence
				for(int i =0;i<4;i++)
				{
	                  if(security [i] == 1)
					  {
						  iCode[current_pos][i] =iCode[current_pos-1][i];
						  continue;

					  }
					  else if(security [i] == 0)
					  {
						  if( i<3)
						  {
							  if (iClue[current_pos-1][i] == EMPTY)
							  {            
								           iCode[current_pos][i] = 0;
										   for(int j = 0; j<current_pos; j++)
										   { 
											    for(int m = 0; m<current_pos; m++)
										        {
												   if((iCode[m][i]) == (iCode[current_pos][i]))
												   {
													   (iCode[current_pos][i])++; 
												   }
												}
										   }
							  }
                           else if (iClue[current_pos-1][i] == WHITE)
						   {

							   switch(security [i+1])
							   {

							   case 0:
								   if(iClue[current_pos-1][i+1] == EMPTY)
								   {
										   iCode[current_pos][i+1] =iCode[current_pos-1][i];
										   iCode[current_pos][i] = 0;
										   
										   for(int j = 0; j<current_pos; j++)
										   { 
											    for(int m = 0; m<current_pos; m++)
										        {
												   if((iCode[m][i]) == (iCode[current_pos][i]))
												   {
													   (iCode[current_pos][i])++; 
												   }
												}
										   }
								   }
								   else if(iClue[current_pos-1][i+1] == WHITE)
								   {
										   int temp = iCode[current_pos-1][i+1];
											iCode[current_pos][i+1] =iCode[current_pos-1][i];
										   iCode[current_pos][i] = temp;					
				
								   }
								   break;

								   
							   
								   
							   case 1:

								   if(i<2)
								   {
								 switch(security [i+2])
								 {

										   case 0:
													   if(iClue[current_pos-1][i+2] == EMPTY)
													   {
															   iCode[current_pos][i+2] =iCode[current_pos-1][i];
															   iCode[current_pos][i] = 0;													   
											
																   for(int j = 0; j<current_pos; j++)
																   { 
																		for(int m = 0; m<current_pos; m++)
																		{
																		   if((iCode[m][i]) == (iCode[current_pos][i]))
																		   {
																			   (iCode[current_pos][i])++; 
																		   }
																		}
																   }
													   }
													   else if(iClue[current_pos-1][i+2] == WHITE)
													   {
															   int temp = iCode[current_pos-1][i+2];
																iCode[current_pos][i+2] =iCode[current_pos-1][i];
															   iCode[current_pos][i] = temp;					
									
													   }			
											   break;

											   
										   case 1:
											             if (i==0)
														 {
														switch(security [i+3])
														   {

														   case 0:
																	   if(iClue[current_pos-1][i+3] == EMPTY)
																	   {
																			   iCode[current_pos][i+3] =iCode[current_pos-1][i];
																			   iCode[current_pos][i] = 0;
																			   
																						   for(int j = 0; j<current_pos; j++)
																						   { 
																								for(int m = 0; m<current_pos; m++)
																								{
																								   if((iCode[m][i]) == (iCode[current_pos][i]))
																								   {
																									   (iCode[current_pos][i])++; 
																								   }
																								}
																						   }
																	   }
																	   else if(iClue[current_pos-1][i+3] == WHITE)
																	   {
																			   int temp = iCode[current_pos-1][i+3];
																				iCode[current_pos][i+3] =iCode[current_pos-1][i];
																			   iCode[current_pos][i] = temp;					
													
																	   }			
															   break;

															   }
														 }

											   break;
										   }
								   }
								   else
								   {
                                      // Enter the values to handle positoins 2 and 3 accessing positions 1 and 2

									switch(security [i-1])
								 {

										   case 0: // Go back to position at -1 current code position
													   if(iClue[current_pos-1][i-1] == EMPTY)
													   {
															   iCode[current_pos][i-1] =iCode[current_pos-1][i];
															   iCode[current_pos][i] = 0;													   
											
																   for(int j = 0; j<current_pos; j++)
																   { 
																		for(int m = 0; m<current_pos; m++)
																		{
																		   if((iCode[m][i]) == (iCode[current_pos][i]))
																		   {
																			   (iCode[current_pos][i])++; 
																		   }
																		}
																   }
													   }
													   else if(iClue[current_pos-1][i-1] == WHITE)
													   {
															   int temp = iCode[current_pos-1][i-1];
																iCode[current_pos][i-1] =iCode[current_pos-1][i];
															   iCode[current_pos][i] = temp;					
									
													   }			
											   break;

											   
										   case 1: // Go back to position at -2 current code position
											             if (i>1)
								                        {
														switch(security [i-2])
														   {

														   case 0:
																	   if(iClue[current_pos-1][i-2] == EMPTY)
																	   {
																			   iCode[current_pos][i-2] =iCode[current_pos-1][i];
																			   iCode[current_pos][i] = 0;
																			   
																						   for(int j = 0; j<current_pos; j++)
																						   { 
																								for(int m = 0; m<current_pos; m++)
																								{
																								   if((iCode[m][i]) == (iCode[current_pos][i]))
																								   {
																									   (iCode[current_pos][i])++; 
																								   }
																								}
																						   }
																	   }
																	   else if(iClue[current_pos-1][i-2] == WHITE)
																	   {
																			   int temp = iCode[current_pos-1][i-2];
																				iCode[current_pos][i-2] =iCode[current_pos-1][i];
																			   iCode[current_pos][i] = temp;					
													
																	   }			
															   break;

															  case 1:
																   if (i=3)
																	  {
																		      switch(security [i-3])
																			  {

																		case 0:
																					 if(iClue[current_pos-1][i-3] == EMPTY)
																					{
																					    iCode[current_pos][i-3] =iCode[current_pos-1][i];
																					     iCode[current_pos][i] = 0;
																												   
																						 for(int j = 0; j<current_pos; j++)
																						 { 
																							for(int m = 0; m<current_pos; m++)
																							{
																								 if((iCode[m][i]) == (iCode[current_pos][i]))
																								 {
																									 (iCode[current_pos][i])++; 
																								 }
																							 }
																						  }
																					 }
																				     else if(iClue[current_pos-1][i-3] == WHITE)
																			        {
																						int temp = iCode[current_pos-1][i-3];
																						 iCode[current_pos][i-3] =iCode[current_pos-1][i];
																				         iCode[current_pos][i] = temp;					
																						
																					}			
																	   break;

															                  }
														                 }

											              break;
															   }
														 }

											   break;
										   }
								   }
								   break;
							   }
                                                        
						     }
						   }
						   else if((iClue[current_pos-1][i] == EMPTY) &&(i==3))
						   {
                              	 iCode[current_pos][i] = 0;
										   
										   for(int j = 0; j<current_pos; j++)
										   { 
											    for(int m = 0; m<current_pos; m++)
										        {
												   if((iCode[m][i]) == (iCode[current_pos][i]))
												   {
													   (iCode[current_pos][i])++; 
												   }
												}
										   }
						   }
					  }
				
				}
	}
	
	
};