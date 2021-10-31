#pragma once

#include <string>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>
#include "Table.h"

#pragma warning(disable : 4996)

class Player
{
	int pos = 0;
	int score;
	int wins;
	int games;
	std::string nicname;
public:
	Player();
	~Player();
	void setNicname(std::string);
	std::string getNicname(void) { return nicname; }
	void moveaim(Table&, char, int);
	void changeStats(int);
	int getWins(void) { return wins; }
	int getScore(void) { return score; }
	int getgames(void) { return games; }
};

