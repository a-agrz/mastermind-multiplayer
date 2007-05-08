
class cGameboard
{
public:
cGameboard()
{
							for( int i = 0; i <TOTAL_ATT; i++)
								{
									for(int j = 0; j<4; j++)
									{
										game_sheet[i][j] = 6;			
									    clue_sheet[i][j] = 7;
									}

								}
};
//Array to hold mantermind game area,
//where different values represent different textures
 int game_sheet[TOTAL_ATT][4];

// Array to hold the part of the mastermind game area to contain the clue pegs,
// where different values represent different textures
 int clue_sheet[TOTAL_ATT][4] ;
};