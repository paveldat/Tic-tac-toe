#include "pch.h"
#include "Player.h"

#include "Table.h"
#include <iostream>
#include <vector>

#include <string>
#include "AI_Player.h"

#pragma warning(disable : 4996)   

using namespace std;

//for 3x3
char board[9] = {};

void clrscr()
{
	for (int i = 0; i < 40; i++)
		cout << endl;
}

void clearBoard()
{
	for (int i = 0; i < 9; i++)
		board[i] = '@';
}

bool hasWon(char player)
{
	int wins[][3] = { {0,1,2},{3,4,5},{6,7,8},{6,3,0},{7,4,1},{8,5,2},{0,4,8},
	{2,4,6} };

	for (int i = 0; i < 8; i++)
	{
		int count = 0;
		for (int j = 0; j < 3; j++)
		{
			if (board[wins[i][j]] == player)
				count++;
		}
		if (count == 3)
			return true;
	}
	return false;
}

void printBoard(std::string indent)
{
	//board
	cout << "Game board:" << endl;
	cout << indent << board[6] << board[7] << board[8] << endl;
	cout << indent << board[3] << board[4] << board[5] << endl;
	cout << indent << board[0] << board[1] << board[2] << endl;
}

int get_move()
{
	cout << "Move options: \n";
	cout << "-7-|-8-|-9-" << endl;
	cout << "-4-|-5-|-6-" << endl;
	cout << "-1-|-2-|-3-" << endl;
	cout << endl;

	printBoard("");
	cout << endl << "Your move:";

	int move;
	cin >> move;
	//checking move
	while (move < 1 || move>9 || board[move - 1] != '@')
	{
		cout << endl << "Enter the move(1-9):";
		cin >> move;
	}
	return move;
}

char playAndGetWinner()
{
	int turn = 0;
	while (!hasWon('X') && !hasWon('O'))
	{
		clrscr();
		int move = get_move();
		cout << "Your move is:" << move << endl;
		if (turn % 2 == 0)
		{
			board[move - 1] = 'X';
			if (hasWon('X'))
			{
				cout << "X is won!" << endl;
				return 'X';
			}
		}
		else
		{
			board[move - 1] = 'O';
			if (hasWon('Y'))
			{
				cout << "O is won!" << endl;
				return 'O';
			}
		}
		turn++;
		if (turn == 9)
		{
			cout << "Draw!" << endl;
			return 'D';
		}
	}
	
	
}
//for 5x5
bool isWin(Table t) //таблица(аргумент)   
{
	for (auto it = t.data.begin(); it != t.data.end(); ++it) 
	{
		if (abs(*it) == 5) 
		{
			return false;
		}
	}
	return true;
}

void Game(Player &p1, Player &p2, Table &t) 
{
	int moves = 0;
	bool draw = false;
	while (isWin(t) && !draw)
	{
		++moves;
		if (moves == 25) 
		{
			cout << "DRAW" << endl;
			p1.changeStats(0);
			p2.changeStats(0);
			draw = true;
		}
		if (!draw) 
		{
			p1.moveaim(t, 'X', 1);
			if (!isWin(t)) 
			{
				cout << p1.getNicname() << "    IS   WINNER" << endl;
				p1.changeStats(1);
				p2.changeStats(-1);
				return;
			}
		}
		++moves;
		if (moves == 25) 
		{
			cout << "DRAW" << endl;
			p1.changeStats(0);
			p2.changeStats(0);
			draw = true;
		}
		if(!draw)
		{
			p2.moveaim(t, 'O', -1);
			if (!isWin(t)) 
			{
				cout << p2.getNicname() << "    IS   WINNER" << endl;
				p2.changeStats(1);
				p1.changeStats(-1);
				return;
			}
			
		}
	}
}

void Game(Player &p1, Table &t) 
{
	AI_Player dumb;
	int moves = 0;
	int q;
	cout << "Your team?(1-X)";
	cin >> q;
	bool draw = false;
	if (q == 1) 
	{
		dumb.team = -1;
		while (isWin(t) && !draw) 
		{
			++moves;
			if (moves >= 25) 
			{
				cout << "DRAW" << endl;
				p1.changeStats(0);
				draw = true;
			}
			if (!draw) 
			{
				p1.moveaim(t, 'X', 1);
				if (!isWin(t))
				{
					cout << p1.getNicname() << "    IS   WINNER" << endl;
					p1.changeStats(1);
					return;
				}
			}
			++moves;
			if (moves >= 25) 
			{
				cout << "DRAW" << endl;
				//p1.changeStats(0);
				draw = true;
			}
			if (!draw) 
			{
				dumb.nextMove(t);
				if (!isWin(t)) 
				{
					cout << "BOT  IS   WINNER" << endl;
					p1.changeStats(-1);
					return;
				}
			}
		}
	}
	else 
	{
		dumb.team = 1;
		while (isWin(t) && !draw) 
		{
			++moves;
			if (moves >= 25) 
			{
				cout << "DRAW" << endl;
				p1.changeStats(0);
				draw = true;
			}
			if (!draw) {
				dumb.nextMove(t);
				if (!isWin(t)) 
				{
					cout << "BOT  IS   WINNER" << endl;
					p1.changeStats(-1);
					return;
				}
			}
			++moves;
			if (moves >= 25) 
			{
				cout << "DRAW" << endl;
				p1.changeStats(0);
				draw = true;
			}
			if (!draw) 
			{
				p1.moveaim(t, 'O', -1);
				if (!isWin(t))
				{
					cout << p1.getNicname() << "    IS   WINNER" << endl;
					p1.changeStats(1);
					return;
				}
			}
		}
	}
}

int main()
{
	char enter;
	cout << "Hello! You can play X & O"<<endl<<"Press ENTER to continue";
	enter=cin.get();
	if (enter == '\n')
	{
		system("cls");
	}
	

	cout << "The rules: " << endl <<
		"Choose a board on which you want to play, 3x3 or 5x5." << endl <<
		"If you chose a 3x3 board, then you can only play against a friend, if 5x5, both against a friend and against a computer."<<endl<<
		"Press ENTER to continue";
	enter = cin.get();
	if (enter == '\n')
	{
		system("cls");
	}

	cout << "control (3x3): field number and enter" << endl <<
		"control (5x5): movement of arrows and enter"<<endl<<
		"Points: 0 - lose"<<endl<<
		"        5 - draw"<<endl<<
		"       10 - win"<<endl<<"Press ENTER to continue";
	enter = cin.get();
	if (enter == '\n')
	{
		system("cls");
	}

	cout << "3x3 or 5x5??(3 for 3x3 and 5 for 5x5): ";
	int check;
	cin >> check;
	
	if (check == 5)
	{
		//5x5
		vector<Player> players;
		Player dummy;
		string text;
		Table t;
		int i = 0;
		char responce;

		//add player
		cout << "enter nick :  " << endl;
		cin >> text;
		players.push_back(dummy);
		players[i].setNicname(text);
		++i;




		bool cont = true;
		int a1;
		int a2;

		while (cont)
		{
			t.gonew();  //новая доска(все пустое)
			cout << "Play a game?(1 - pvp; 2 - pve(bot); 0 - end Game)" << endl;
			cin >> a1;
			if (a1 == 1)
			{
				cout << "enter nick :  " << endl;
				cin >> text;
				players.push_back(dummy);
				players[i].setNicname(text);
				++i;

				cout << "Number of player to play as X  ";
				cin >> a1;
				cout << "Number of player to play as O  ";
				cin >> a2;
				--a1;
				--a2;
				if (a1 != a2 && a1 > -1 && a1 < i && a2 > -1 && a2 < i)    //номер игрока, проверка
				{
					Game(players[a1], players[a2], t);
				}
			}
			else
			{
				if (a1 == 2)
				{
					if (i > 1)
					{
						cout << "NUMBER OF PLAYER AGAINST BOT";
						cin >> a1;
						--a1;
						if (a1 > -1 && a1 < i)
						{
							Game(players[a1], t);
						}
					}
					else
					{
						Game(players[0], t);
					}
				}
				else
				{
					cont = false;
				}
			}
		}

		for (auto it = players.begin(); it != players.end(); ++it)
		{
			dummy = *it;
			cout << dummy.getNicname() << "    SCORE   " << dummy.getScore() << endl;
		}
	}
	
	if (check == 3)
	{
		clearBoard();
		char winner = playAndGetWinner(); 

		cout << "The final board:" << endl;
		printBoard("\t");
		
	}
}

