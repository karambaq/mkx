 #include "fight.h"

	// Round 
	Round::Round(string round_info)
	{
		if(round_info.empty())
			perror("Round info is empty");

		m_winner = round_info[0] ? round_info[0] : round_info[2] ;
		m_winner -= 47;
		m_finish = round_info[4];
	}
	
	void Round::print() 
	{
		cout << "Winner is " << m_winner << " player, Finish is " << m_finish << endl;
	}

	// Fight

	Fight::Fight(string fighters) {
		// 
	}

	Fight::Fight(string fighters, string all_rounds) : m_fighters(fighters)
	{
		m_winner = all_rounds[2] == '5' ? 1 : 2;
		size_t position = all_rounds.find(':', 2);
		while( position != string::npos ) {
			position = all_rounds.find(':', position + 1);
			if (position > all_rounds.length())
                break;
			string round_str = all_rounds.substr(position - 1, 5);
			m_rounds.push_back(Round(round_str));
		}
	}

	Fight::Fight(string fighters, string all_rounds, string time) : m_time(time) {
		Fight(fighters, all_rounds); 
	}

	void Fight::print()
	{
		// cout << "Hey here" << endl;
		// cout << m_rounds.size() << endl;
		for ( size_t i = 0; i < m_rounds.size(); ++i )
			m_rounds[i].print();
	}

	int Fight::get_winner()
	{
		return m_winner;
	}

