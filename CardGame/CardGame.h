#pragma once
#include <cstdlib>
#include <cstdio>
#include <cstddef>
#include <ctime>

class CardGame{
	private:
		int m_players;
		static int m_totalParticipants;
	public:
		CardGame(int players);
		~CardGame();
		static int getParticipants();
};
