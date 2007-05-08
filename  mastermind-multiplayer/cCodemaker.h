


class cCodeMaker{

public:
	void  enter_sequence(int (*iCode)[4]);
	int check_sequence(int (*iCode)[4],  int rem_chances);
	void handle_clues(int (*iCode)[4],int (*iClue)[4], int rem_chances);

	int the_code[4];

};