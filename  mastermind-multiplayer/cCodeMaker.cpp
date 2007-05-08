#include "cCodeMaker.h"
#define BLANK 6
#define TOTAL_ATT 8 // this is the total amount of attemtps each player will have
#define WHITE 11 //White clue peg, meaning correct peg , but wrong position
#define  BLACK_SPOT 12 // White clue peg with black spot, meaning right postition and colour
#define EMPTY 7 // No clue peg meaning this postion has a useless peg


void cCodeMaker::enter_sequence(int (*iCode)[4])
{

	for(int i =0; i<4; i++)
	{
		 the_code[i]=iCode[0][i];
		 iCode[0][i] = BLANK;
	
	}

};

int cCodeMaker::check_sequence(int (*iCode)[4], int rem_chances)
{
	// 11is used because the system counts from 0 -10
    int current_pos = (TOTAL_ATT - rem_chances);
   int c = 0;
	for(int i =0; i<4; i++)
	{
		if( iCode[current_pos][i] == the_code[i])
		{
              c++;
		}
	}

	if ( c==4)
	  {
      	 return 1;
   
	  }
	 return 0;
};

void cCodeMaker::handle_clues(int (*iCode)[4],int (*iClue)[4], int rem_chances)
{
	// 11 is used because the system counts from 0-7
    int current_pos = (TOTAL_ATT - rem_chances);
 // used to allocate clues exclusively and not place them repeatedly, 
 //for ex. hidden code is 1234, and guess 1514 then clues are 12, 7, 11, 12,
// and that is wrong it should be 12,7, 7, 12 as the 1 was already accounted for
	bool clue_security[4] = {true,true,true,true};  
	for(int i =0; i<4; i++)
	{
		if( iCode[current_pos][i] == the_code[i])
		{
              iClue[current_pos][i] = BLACK_SPOT;
		}
		else
		{
            for(int j =1; j<4; j++)
			{
              if((iCode[current_pos][i] == the_code[j] ) && (iCode[current_pos][j] != the_code[j] ))
					{    
						if(clue_security[j])
						{
						  iClue[current_pos][i] = WHITE ;
						 clue_security[j] = false;
						}
					}
			}
		}
	}



};

