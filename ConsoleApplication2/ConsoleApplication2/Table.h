#pragma once


#include <iostream>
#include <vector>

#pragma warning(disable : 4996)

class Table
{
	// i -> string; j -> columns; d1 -> top left - bottom right; d2 -> bottom left - top right;

	//int isWinner(void);
public:
	char table[25];
	int i1 = 0, i2 = 0, i3 = 0, j1 = 0, j2 = 0, j3 = 0, d1 = 0, d2 = 0;
	std::vector<int> data;
	Table();
	~Table();
	friend void print(Table, int);
	void updateStats(int, int, int);
	void gonew(void);
};