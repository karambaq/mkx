#include <string>
#include <vector>

class Round {
	int result; // 0:1 B
	char finish; // b / f / r

	Round(string round_info) {
		// parsing
	}
};

class Fight {
	string mFirstFighter, mSecFighter;
	string mTime;
	vector< Round > mRounds;

	Fight(string fighters) {
		// parsing
		// fill rounds
	}

	Fight(string fighters, string time) : Fight(fighters), mTime(time) 
	{};
};
