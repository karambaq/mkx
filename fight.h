#ifndef FIGHT_H
#define FIGHT_H

#include <iomanip>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Round {
	int m_winner; // 0:1 B
	char m_finish; // b / f / r

	public:
	Round(string round_info);
	void print();	
};

class Fight {
	int m_winner;
	string m_fighters;
	string m_time;
	vector< Round > m_rounds;

	public:
	Fight(string fighters);
	Fight(string fighters, string all_rounds);
	Fight(string fighters, string all_rounds, string time);
	void print();
	int get_winner();
};

#endif 