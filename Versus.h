#ifndef VERSUS_H
#define VERSUS_H

#include "fight.h"

class Versus 
{
	vector< Fight > m_fights;
	string m_fighters;

	public:
		Versus(string filename, string fighters) : m_fighters(fighters) 
		{ 
			fill_versus(filename);
		}

		void fill_versus(string filename) 
		{
			string line;
			ifstream in;
			ofstream out;
			in.open(filename);
			out.open("result.txt");

			// Filling history
			vector<string> history;
			while (getline( in, line )) {
				history.push_back( line );
			}
			in.close();

			for ( size_t i = 0; i < history.size(); i++ ) {
				history[i].resize( m_fighters.size() );
				if ( history[i] == m_fighters ) {
					m_fights.push_back(Fight(m_fighters, history[i + 2]));
					out << history[i + 2] << endl;
				}
			}
			out.close();
		}	

		void print() 
		{
			for (auto f: m_fights) {
				f.print();
			}
		}	

		void dominant()
		{
			double x = 0.0;
			for (auto f: m_fights) {
				if (f.get_winner() == 1) {
					++x;
				}
			}
			x /= m_fights.size();
			cout << m_fighters << " : " << to_string(x * 100) << 
						" - " << to_string(100 - (x * 100)) << endl;

		}

};

#endif 