#include "pch.h"
#include "Table.h"

using namespace std;

Table::Table()
{
	for (int i = 0; i < 25; ++i) {
			table[i] = '@';
	}
	for (int i = 0; i < 12; ++i) {
		data.push_back(0);
	}
}


Table::~Table()
{
}


void print(Table t, int pos) {
	for (int i = 0; i < 25; ++i) {
		if (i == pos) {
			cout << "*";
		}
		else {
			cout << t.table[i];
		}
		if ((i % 5) == 4) {
			cout << endl;
		}
	}
}

void Table::updateStats(int i, int j, int upd){
	if (i == j) {
		data[10] += upd;
		//cout << endl << "D1 " << data[10] << endl;
	}
	if (i == 0) {
		data[0] += upd;
		//cout << endl << "I1 " << data[0] << endl;
	}
	if (i == 1) {
		data[1] += upd;
		//cout << endl << "I2 " << data[1] << endl;
	}
	if (i == 2) {
		data[2] += upd;
		//cout << endl << "I3 " << data[2] << endl;
	}
	if (i == 3) {
		data[3] += upd;
		//cout << endl << "I4 " << data[3] << endl;
	}
	if (i == 4) {
		data[4] += upd;
		//cout << endl << "I5 " << data[4] << endl;
	}
	if (j == 0) {
		data[5] += upd;
		//cout << endl << "=j1 " << data[5] << endl;
	}
	if (j == 1) {
		data[6] += upd;
		//cout << endl << "J2 " << data[6] << endl;
	}
	if (j == 2) {
		data[7] += upd;
		//cout << endl << "J3 " << data[7] << endl;
	}
	if (j == 3) {
		data[8] += upd;
		//cout << endl << "J4 " << data[8] << endl;
	}
	if (j == 4) {
		data[9] += upd;
		//cout << endl << "J5 " << data[9] << endl;
	}
	if (i + j == 4) {
		data[11] += upd;
		//cout << endl << "D2 " << data[11] << endl;
	}
}

void Table::gonew(void) {
	for (auto it = data.begin(); it != data.end(); ++it) {
		*it = 0;
	}
	for (int i = 0; i < 25; ++i) {
		table[i] = '@';
	}
}