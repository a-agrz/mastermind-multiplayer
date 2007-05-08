#include "cCodeBreaker.h"
#include "cCodeMaker.h"
#include <ctime>
#include <cstdlib>

class cPlayer{
public:
	cPlayer() {cBreak =0; cMake =0;};

	//Will be used to point to these objects created upon the memory heap 
	cCodeBreaker* cBreak;
	cCodeMaker* cMake;


};

class cHumanPlayer : public cPlayer{

public:
	cHumanPlayer() {};

};

class cCompPlayer: public cPlayer{

public:
 	cCompPlayer() {};
void make_sequence();   
void guess_sequence(int (*iCode)[4],int (*iClue)[4]);

};
