#include "pch.h"
#include "AI_Player.h"

using namespace std;

AI_Player::AI_Player()
{
	init_log();  //открыть лог.тхт
}


AI_Player::~AI_Player()
{
}

void AI_Player::init_log(void){
	log_file.open("log.txt");
}



int AI_Player::anydanger(Table &t) {   // return -1 -> no danger    провер€ет полностью все значени€(строки, столбцы, диагонали), если есть угроза. 
	//≈сли в р€ду больше 3 и нет его фишек, он ставит
	int code = 0;
	if (team == 1) {		// 1 -> X
		for (auto it = t.data.begin(); it != t.data.end(); ++it) {
			if (*it <= -3 && myp(t, code) ==  0){
				return code;
			}
			++code;
		}
		return -1;
	}
	if (team == -1) {		// -1 -> O
		for (auto it = t.data.begin(); it != t.data.end(); ++it) {
			if (*it >= 3 && myp(t, code) == 0) {
				return code;
			}
			++code;
		}
		return -1;
	}
}

int AI_Player::findmax(Table &t) {   //где больше его фишек, чтоб выйграть, больше на диагональ уклон
	int code = 0;
	int ret = -1;
	int max = 0;
	int min = 0;
	if (team == 1) {
		for (auto it = t.data.begin(); it != t.data.end(); ++it) {
			if (*it == max && max != 0) {
					if (checkline(t, code) != 1) {
							//log_file << endl << "go for ch because ch = " << ch << " and checkline = " << checkline(t, code) << endl;
							ret = code;
					}
			}
			if (*it > max) {
				if (checkline(t, code) != 1) {
					ret = code;
				}
			}
			++code;
		}
		log_file << endl << "move number " << move_num << "  findmax ret " << ret << "  value on that line " << t.data[abs(ret)] << endl << "TEAM   " << team << endl;
		return ret;
	}
	if (team == -1) {
		for (auto it = t.data.begin(); it != t.data.end(); ++it) {
			if (*it == min && min != 0) {
				srand(time(0));
				int ch = (rand() % 100);
					if (checkline(t, code) != 1) {
						
							//log_file << endl << "go for ch because ch = " << ch << " and checkline = " << checkline(t, code) << endl;
							ret = code;
						
					}
			}
			if (*it < min) {
				if (checkline(t, code) != 1) {
					ret = code;
				}
			}
			++code;
		}
		log_file << endl << "move number " << move_num << "findmax ret " << ret << "  value on that line   " << t.data[abs(ret)] << endl << "TEAM   " << team << endl;
		return ret;
	}
}

int AI_Player::checkline(Table &t, int &line) {			   //возвращает сколько фишек в р€ду(1-полный р€д, 3-хот€ бы одна вражеска€, 0 - нет вражеских и есть пустое место)	
	int mycounter = 0;
	int enmycount = 0;
	int neutral = 0;
	if (team == 1) {
		if (line >= 0 && line < 5) {
			for (int i = 0; i < 5; ++i) {
				if (t.table[line * 5 + i] == 'O') {
					++enmycount;
				}
				if (t.table[line * 5 + i] == 'X') {
					++mycounter;
				}
				if (t.table[line * 5 + i] == '@') {
					++neutral;
				}
			}
		}
		if (line >= 5 && line < 10) {
			for (int i = 0; i < 5; ++i) {
				if (t.table[(5 * i) + (line % 5)] == 'O') {
					++enmycount;
				}
				if (t.table[(5 * i) + (line % 5)] == 'X') {
					++mycounter;
				}
				if (t.table[(5 * i) + (line % 5)] == '@') {
					++neutral;
				}
			}
		}
		if (line == 10) {
			for (int i = 0; i < 5; ++i) {
				if (t.table[i + 5 * i] == 'O') {
					++enmycount;
				}
				if (t.table[i + 5 * i] == 'X') {
					++mycounter;
				}
				if (t.table[i + 5 * i] == '@') {
					++neutral;
				}
			}
		}
		if (line == 11) {
			for (int i = 0; i < 5; ++i) {
				if (t.table[i * 4 + 4] == 'O') {
					++enmycount;
				}
				if (t.table[i * 4 + 4] == 'X') {
					++mycounter;
				}
				if (t.table[i * 4 + 4] == '@') {
					++neutral;
				}
			}
		}
	}
	if (team == -1) {
		if (line >= 0 && line < 5) {
			for (int i = 0; i < 5; ++i) {
				if (t.table[line * 5 + i] == 'X') {
					++enmycount;
				}
				if (t.table[line * 5 + i] == 'O') {
					++mycounter;
				}
				if (t.table[line * 5 + i] == '@') {
					++neutral;
				}
			}
		}
		if (line >= 5 && line < 10) {
			for (int i = 0; i < 5; ++i) {
				if (t.table[line + (i * 5) - 5] == 'X') {
					++enmycount;
				}
				if (t.table[line + (i * 5) - 5] == 'O') {
					++mycounter;
				}
				if (t.table[line + (i * 5) - 5] == '@') {
					++neutral;
				}
			}
		}
		if (line == 10) {
			for (int i = 0; i < 5; ++i) {
				if (t.table[i + 5 * i] == 'X') {
					++enmycount;
				}
				if (t.table[i + 5 * i] == 'O') {
					++mycounter;
				}
				if (t.table[i + 5 * i] == '@') {
					++neutral;
				}
			}
		}
		if (line == 11) {
			for (int i = 0; i < 5; ++i) {
				if (t.table[i * 4 + 4] == 'X') {
					++enmycount;
				}
				if (t.table[i * 4 + 4] == 'O') {
					++mycounter;
				}
				if (t.table[i * 4 + 4] == '@') {
					++neutral;
				}
			}
		}
	}
	log_file << endl << "LINE IS " << line << " values(my/enemy/neutral): " << mycounter << " " << enmycount << " " << neutral << endl;
	if (neutral == 0) {
		log_file << endl << "RETURN " << 1 << endl;
		return 1;
	}
	if (enmycount != 0) {
		log_file << endl << "RETURN " << 3 << endl;
		return 3;
	}
	log_file << endl << "RETURN " << 0 << endl;
	return 0;
}

void AI_Player::nextMove(Table &t) {
	int i = anydanger(t);
	bool dangdone = false;
	for (auto it = dda.begin(); it != dda.end(); ++it) {
		if (*it == i && i != -1) {
			dangdone = true;
		}
	}
	int qq = findmax(t);  //лини€ где выгодней ставить
	log_file << "Before move  " << endl;
	for (int i = 0; i < 25; ++i) {
		log_file << t.table[i];
		if ((i % 5) == 4) {
			log_file << endl;
		}
	}
	if (move_num != 0) {
		if (i == -1 || dangdone) {	// no danger
			log_file << endl << "no danger " << endl;
			if (qq >= 0 && qq < 5) {			//max -> i
				srand(time(0));
				int delta = (rand() % 5);
				bool go_on = true;
				//log_file << endl << "Move  " << move_num << "  findmax result  " << qq << "  anydanger result  " << i << endl;
				//-----------------------------------------------------------------
				while (go_on) {
					if (t.table[5 * qq + delta] == '@') {
						if (team == 1) {
							t.table[5 * qq + delta] = 'X';
						}
						else {
							t.table[5 * qq + delta] = 'O';
						}
						int i = qq;
						int j = delta;
						t.updateStats(i, j, team);
						log_file << "i=  " << i << "   j=   " << j << endl;
						go_on = false;
					}
					else {
						++delta;
						if (delta > 4) {
							delta = 0;
						}
					}
				}
				//-----------------------------------------------------------------
			}

			if (qq >= 5 && qq < 10 && !dangdone) {       // max -> j
				srand(time(0));
				int delta = (rand() % 5);
				bool go_on = true;
				//log_file << endl << "Move  " << move_num << "  findmax result  " << qq << "  anydanger result  " << i << endl;
				//-----------------------------------------------------------------
				while (go_on) {
					if (t.table[ (qq % 5) + (delta * 5) ] == '@') {
						if (team == 1) {
							t.table[ (qq % 5) + (delta * 5) ] = 'X';
						}
						else {
							t.table[ (qq % 5) + (delta * 5)]  = 'O';
						}
						int i = delta;
						int j = qq - 5;
						t.updateStats(i, j, team);
						log_file << "i=  " << i << "   j=   " << j << endl;
						go_on = false;
					}
					else {
						++delta;
						if (delta > 4) {
							delta = 0;
						}
					}
				}
				//-----------------------------------------------------------------
			}
			if (qq == 10) {     //max -> main diagonal
				srand(time(0));
				int delta = (rand() % 5);
				bool go_on = true;
				while (go_on) {
					if (t.table[6 * delta] == '@') {
						if (team == 1) {
							t.table[6 * delta] = 'X';
						}
						else {
							t.table[6 * delta] = 'O';
						}
						go_on = false;
						t.updateStats(delta, delta, team);
						log_file << "i=  " << delta << "   j=   " << delta << endl;
					}
					else {
						++delta;
						if (delta > 4) {
							delta = 0;
						}
					}
				}
			}

			if (qq == 11) {     //max -> side diagonal
				srand(time(0));
				int delta = (rand() % 5);
				bool go_on = true;
				while (go_on) {
					if (t.table[4 * (delta + 1)] == '@') {
						if (team == 1) {
							t.table[4 * (delta + 1)] = 'X';
						}
						else {
							t.table[4 * (delta + 1)] = 'O';
						}
						go_on = false;
						t.updateStats(delta, 4 - delta, team);
						log_file << "i=  " << delta << "   j=   " << 4 - delta << endl;
					}
					else {
						++delta;
						if (delta > 4) {
							delta = 0;
						}
					}
				}
			}
		}
		else {  // there is danger
		log_file << endl << "Danger " << i << endl;
			if (i >= 0 && i < 5) {			//max -> i
				srand(time(0));
				int delta = (rand() % 5);
				bool go_on = true;
				//log_file << endl << "Move  " << move_num << "  findmax result  " << qq << "  anydanger result  " << i << endl;
				//-----------------------------------------------------------------
				while (go_on) {
					if (t.table[5 * i + delta] == '@') {
						if (team == 1) {
							t.table[5 * i + delta] = 'X';
						}
						else {
							t.table[5 * i + delta] = 'O';
						}
						int tt = i;   
						int j = delta;
						t.updateStats(tt, j, team);
						go_on = false;
					}
					else {
						++delta;
						if (delta > 4) {
							delta = 0;
						}
					}
				}
				//-----------------------------------------------------------------
			}

			if (i >= 5 && i < 10) {       // max -> j
				srand(time(0));
				int delta = (rand() % 5);
				bool go_on = true;
				//log_file << endl << "Move  " << move_num << "  findmax result  " << qq << "  anydanger result  " << i << endl;
				//-----------------------------------------------------------------
				while (go_on) {
					if (t.table[5 * delta + i] == '@') {
						if (team == 1) {
							t.table[5 * delta + i] = 'X';
						}
						else {
							t.table[5 * delta + i] = 'O';
						}
						int tt = delta;
						int j = i;
						t.updateStats(tt, j, team);
						go_on = false;
					}
					else {
						++delta;
						if (delta > 4) {
							delta = 0;
						}
					}
				}
				//-----------------------------------------------------------------
			}
			if (i == 10) {     //max -> main diagonal
				srand(time(0));
				int delta = (rand() % 5);
				bool go_on = true;
				while (go_on) {
					if (t.table[6 * delta] == '@') {
						if (team == 1) {
							t.table[6 * delta] = 'X';
						}
						else {
							t.table[6 * delta] = 'O';
						}
						go_on = false;
						t.updateStats(delta, delta, team);
					}
					else {
						++delta;
						if (delta > 4) {
							delta = 0;
						}
					}
				}
			}

			if (i == 11) {     //max -> side diagonal
				srand(time(0));
				int delta = (rand() % 5);
				bool go_on = true;
				while (go_on) {
					if (t.table[4 * (delta + 1)] == '@') {
						if (team == 1) {
							t.table[4 * (delta + 1)] = 'X';
						}
						else {
							t.table[4 * (delta + 1)] = 'O';
						}
						go_on = false;
						t.updateStats(delta, 4 - delta, team);
					}
					else {
						++delta;
						if (delta > 4) {
							delta = 0;
						}
					}
				}

			}
			++move_num;
		}
	}
else {
srand(time(0));
int delta = rand();
bool go_on = true;
while (go_on) {
	int uu = delta % 25;
	if (t.table[uu] == '@') {
		if (team == 1) {
			t.table[uu] = 'X';
		}
		else {
			t.table[uu] = 'O';
		}
		int i = uu / 5;
		int j = uu % 5;
		t.updateStats(i, j, team);
		++move_num;
		go_on = false;
	}
	else {
		delta = delta * 3;
		delta -= qq;
		delta += delta % 17;
		
	}
}
}
	log_file << endl << "After move" << endl;
	for (int i = 0; i < 25; ++i) {
		log_file << t.table[i];
		if ((i % 5) == 4) {
			log_file << endl;
		}
	}
}

int AI_Player::myp(Table& t, int& line) {     //возвращает кол-во фишек игрока
	int mycounter = 0;
	int enmycount = 0;
	int neutral = 0;
	if (team == 1) {
		if (line >= 0 && line < 5) {
			for (int i = 0; i < 5; ++i) {
				if (t.table[line * 5 + i] == 'O') {
					++enmycount;
				}
				if (t.table[line * 5 + i] == 'X') {
					++mycounter;
				}
				if (t.table[line * 5 + i] == '@') {
					++neutral;
				}
			}
		}
		if (line >= 5 && line < 10) {
			for (int i = 0; i < 5; ++i) {
				if (t.table[(5 * i) + (line % 5)] == 'O') {
					++enmycount;
				}
				if (t.table[(5 * i) + (line % 5)] == 'X') {
					++mycounter;
				}
				if (t.table[(5 * i) + (line % 5)] == '@') {
					++neutral;
				}
			}
		}
		if (line == 10) {
			for (int i = 0; i < 5; ++i) {
				if (t.table[i + 5 * i] == 'O') {
					++enmycount;
				}
				if (t.table[i + 5 * i] == 'X') {
					++mycounter;
				}
				if (t.table[i + 5 * i] == '@') {
					++neutral;
				}
			}
		}
		if (line == 11) {
			for (int i = 0; i < 5; ++i) {
				if (t.table[i * 4 + 4] == 'O') {
					++enmycount;
				}
				if (t.table[i * 4 + 4] == 'X') {
					++mycounter;
				}
				if (t.table[i * 4 + 4] == '@') {
					++neutral;
				}
			}
		}
	}
	if (team == -1) {
		if (line >= 0 && line < 5) {
			for (int i = 0; i < 5; ++i) {
				if (t.table[line * 5 + i] == 'X') {
					++enmycount;
				}
				if (t.table[line * 5 + i] == 'O') {
					++mycounter;
				}
				if (t.table[line * 5 + i] == '@') {
					++neutral;
				}
			}
		}
		if (line >= 5 && line < 10) {
			for (int i = 0; i < 5; ++i) {
				if (t.table[line + (i * 5) - 5] == 'X') {
					++enmycount;
				}
				if (t.table[line + (i * 5) - 5] == 'O') {
					++mycounter;
				}
				if (t.table[line + (i * 5) - 5] == '@') {
					++neutral;
				}
			}
		}
		if (line == 10) {
			for (int i = 0; i < 5; ++i) {
				if (t.table[i + 5 * i] == 'X') {
					++enmycount;
				}
				if (t.table[i + 5 * i] == 'O') {
					++mycounter;
				}
				if (t.table[i + 5 * i] == '@') {
					++neutral;
				}
			}
		}
		if (line == 11) {
			for (int i = 0; i < 5; ++i) {
				if (t.table[i * 4 + 4] == 'X') {
					++enmycount;
				}
				if (t.table[i * 4 + 4] == 'O') {
					++mycounter;
				}
				if (t.table[i * 4 + 4] == '@') {
					++neutral;
				}
			}
		}
	}
	//log_file << endl << "LINE IS " << line << " values(my/enemy/neutral): " << mycounter << " " << enmycount << " " << neutral << endl;
	return mycounter;
}