#include "fight.h"
#include "Versus.h"

struct Player
{
    int B, R, F;
} Player1, Player2;

using namespace std;

int main( int argc, char ** argv )
{
	string line;
	ifstream in;
	ofstream out;
	in.open("hist.txt");
	out.open("result.txt");

	// Filling history
	vector<string> history;
	while (getline( in, line )) {
		history.push_back( line );
	}

	// Get fighters name
	string fight;

	for ( size_t i = 1; i < argc - 1; ++i ) {
		fight += argv[i];
		fight += " ";
	}

	fight += argv[argc - 1];

	Versus v("hist.txt", fight);
	v.print();
	v.dominant();	

/*
	// Filling fight_info
	vector<string> fight_info;

	fight_info.push_back(fight);

	for ( size_t i = 0; i < history.size(); i++ ) {
		history[i].resize( fight.size() );
		if ( history[i] == fight ) {
			fight_info.push_back(history[i + 2]);
		}
	}
	double sum = 0.0;
	
	for (size_t i = 1; i < fight_info.size(); i++) {
		int cnt_rounds = (fight_info[i][0] - '0' + fight_info[i][2] - '0');
		cout << cnt_rounds << " ";
		out << cnt_rounds << " ";
		sum += cnt_rounds;
	}

	double avg = sum / (fight_info.size() - 1);

	out << endl;
	out << "Average = " + to_string(avg) << endl;
	cout << endl;
	cout << "Average = " + to_string(avg) << endl;



	for (size_t i = 1; i < fight_info.size(); i++) {
		out << fight_info[i] << endl;
	}

	out.close();

	
	// Oleg code
	int m = 0, j = 0;
	for(size_t i = 1; i < fight_info.size(); ++i)
    {
        int sz = fight_info[i].size();
        if(sz > m)
        
{            m = sz;
            j = i;
        }
    }
    size_t last_pos = fight_info[j].find_last_of(':', fight_info[j].size() - 1);

    size_t pos = 2;

    int column = 1;

    while(pos <= last_pos)
    {
        for(size_t i = 2; i < fight_info.size(); ++i)
        {
            string s = fight_info[i];
            size_t lastPos = pos;
            pos = s.find(':', pos);
            if(pos == string::npos || pos == 0)
            {
                pos = lastPos;
                continue;
            }

            //cout << "Pos is " << pos << " S[pos + 3] = " << s[pos + 3] << endl;

            switch(s[pos + 3])
            {
                case 'F':
                {
                    Player1.F += s[pos - 1] - 48;
                    Player2.F += s[pos + 1] - 48;
                }
                break;
                case 'R':
                {
                    Player1.R += s[pos - 1] - 48;
                    Player2.R += s[pos + 1] - 48;
                }
                break;
                case 'B':
                {
                    Player1.B += s[pos - 1] - 48;
                    Player2.B += s[pos + 1] - 48;
                }
                break;
                default:
                    break;
            }

        }
        printf("Round %d\n", column);
       // printf("Player1 F %d, R %d, B %d\n", Player1.F, Player1.R, Player1.B);
      //  printf("Player2 F %d, R %d, B %d\n\n", Player2.F, Player2.R, Player2.B);
		
		double W1 = Player1.F + Player1.B + Player1.R;
		double W2 = Player2.F + Player2.B + Player2.R;
		double total = W1 + W2;
		double F  = Player1.F + Player2.F;
		double B  = Player1.B + Player2.B;
		double R  = Player1.R + Player2.R;

		/*
		cout << "W1 = ";
		cout.precision(3);
		cout << W1 << ", ";

		cout << "W2 = ";
		cout.precision(3);
		cout << W2 << ", ";

		cout << "F  = ";
		cout.precision(3);
		cout << F << ", ";      
		
		cout << "B  = ";
		cout.precision(3);
		cout << B << ", ";

		cout << "R  = ";
		cout.precision(3); 
		cout << R << ".";
		cout << endl;

		double w1_prob = (W1 / (W1 + W2)) * 100;
		double w2_prob = (W2 / (W1 + W2)) * 100;
		double fatality_prob = (F / (W1 + W2)) * 100;
		double brutality_prob = (B / (W1 + W2)) * 100;
		double dont_know_how_to_translate_prob = (R / (W1 + W2)) * 100;
		
		cout << "w1 prob = ";
		cout.precision(3);
		cout << w1_prob << "%,  ";

		cout << "w2 prob = ";
		cout.precision(3);
		cout << w2_prob << "%." << endl;

		cout << "F  prob = "; 
		cout.precision(3);
		cout << fatality_prob << "%,  ";

		cout << "B  prob = "; 
		cout.precision(3);
		cout << brutality_prob << "%,  ";

		cout << "R  prob = ";
		cout.precision(3);
		cout << dont_know_how_to_translate_prob << "%" << endl;
		cout << endl;

        Player1.B = Player1.F = Player1.R = Player2.B = Player2.F = Player2.R = 0;
        ++pos;
        ++column;
    }
*/



    return 0;
}
