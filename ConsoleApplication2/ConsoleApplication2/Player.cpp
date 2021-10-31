#include "pch.h"
#include "Player.h"

using namespace std;

Player::Player() :score(0), wins(0), games(0)
{
}


Player::~Player()
{
}

void Player::setNicname(string text) {
	nicname = text;
}

void Player::changeStats(int key) {
	//key == 1 -> win; key == 0 -> draw; key == -1 -> defeat
	games++;
	switch (key)
	{
	case(0):
		score += 5;
		break;
	case(1):
		score += 10;
		++wins;
		break;
	case(-1):
		break;
	}
}

void Player::moveaim(Table& t, char c, int uuu) {
	int i = 0, j = 0, pos = 0;
	bool goon = true;
	while (goon) {
		char input = getch();
		int code = input;
		if (code == 72) {
			i--;
		}
		if (code == 80) {
			i++;
		}
		if (code == 77) {
			j++;
		}
		if (code == 75) {
			j--;
		}
		if (code == 13) {
			if (t.table[pos] == '@'){
				pos = j + i * 5;
				t.table[pos] = c;
				goon = false;
				t.updateStats(i, j, uuu);
		}
		}
		if (j < 0) { j++; }
		if (j > 4) { j--; }
		if (i > 4) { i--; }
		if (i < 0) { i++; }
		pos = j + i * 5;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		print(t, pos);
	}
	
}