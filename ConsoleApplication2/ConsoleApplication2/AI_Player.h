#pragma once
#include "Table.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

class AI_Player
{

	int move_num = 0;
public:
	std::ofstream log_file;
	std::ofstream mov_f;
	std::vector<int> dda;
	int team;
	AI_Player();
	~AI_Player();
	void setteam(int i) { team = i; }
	int anydanger(Table&);
	void nextMove(Table&);
	int findmax(Table&);
	void init_log(void);
	void set_team(int a) { team = a; }
	int checkline(Table&, int&);
	int myp(Table&, int&);
};

