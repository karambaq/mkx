#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main( int argc, char ** argv ) 
{
	string line;
	ifstream in;
	ofstream out;
	in.open("hist.txt");
	out.open("result.txt");

	vector< string > history;
	while (getline( in, line )) {
		history.push_back( line );
	}
	

	// Trying to remove empty strings from the vector to improve speed
/*	
	for ( auto it = history.begin(); it != history.end(); ++it ) {
		if ( it->length() == 0 ) {
			history.erase(it);
		}
 	}
*/

	string fight;
	
	for ( size_t i = 1; i < argc - 1; ++i ) {
		fight += argv[i];
		fight += " ";
	}

	fight += argv[argc - 1];

	vector<string> fight_info;

	bool first = true;
	for ( size_t i = 0; i < history.size(); i++ ) {
		history[i].resize( fight.size() );
		if ( history[i] == fight ) {
			if ( first ) {
				fight_info.push_back(history[i]);
				first = false;	
			}
			fight_info.push_back(history[i + 2]);
		}
	}

	double sum = 0.0;
	//vector<int> cnt_of_rounds;
	vector < pair < pair<int, int> , char> > p;
	p.reserve(fight_info.size() * sizeof( pair< pair<int, int> , char >));
	for (size_t i = 0; i < p.size(); i++) {
		p.push_back(make_pair(make_pair(0, 0), 'A'));
	}

	for (size_t i = 1; i < fight_info.size(); i++) {
		
	}

	for (size_t i = 1; i < fight_info.size(); i++) {
		int cnt_rounds = (fight_info[i][0] - '0' + fight_info[i][2] - '0');
		
		if ( fight_info[i][0] - '0' == 5 ) {
			p[i].first.first += 1;
		} else 
			p[i].first.second += 1;

		//cnt_of_rounds[i] = cnt_rounds;
		out << cnt_rounds << " ";
		sum += cnt_rounds;
	}

	double avg = sum / (fight_info.size() - 1);

	out << endl;
	out << "Average = " + to_string(avg) << endl;


	for (size_t i = 1; i < fight_info.size(); i++) {
		out << fight_info[i] << endl;
	}

	vector< pair <int, int> > stats;
	// 1st round
	for (size_t i = 1; i < fight_info.size(); i++){
		size_t j = 5;
		size_t c = 0;
		
		while (i < fight_info[i].size()) {

			if (fight_info[i][j] = '1') {
				stats[i].first += 1; 
			}
			else
			{
				stats[i].second	+= 1;
			}
		}
	}	
	

	out.close();

	return 0;
}