//This only holds attempt_ rem for now, but is created in class form  with the idea of expansion in later versions

#define TOTAL_ATT 8 // this is the total amount of attemtps each player will have
class cCodeBreaker{

public:
	cCodeBreaker(){ attempts_rem = TOTAL_ATT;};
	// This holds the attempts remaining and is used to find the current postion code breaking
	int attempts_rem;

};