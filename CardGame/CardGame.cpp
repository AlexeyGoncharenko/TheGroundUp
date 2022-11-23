#include "CardGame.h"

int CardGame::m_totalParticipants = 0;

CardGame::CardGame(int players): m_players(players){
	m_totalParticipants += m_players;
	printf("Add %d new players\n", m_players);
	printf("Total  participants: %d\n", m_totalParticipants);
}

CardGame::~CardGame(){
	m_totalParticipants -= m_players;
	printf("Left the game %d players\n", m_players);
	printf("Total  participants: %d\n", m_totalParticipants);
}

int CardGame::getParticipants(){ return m_totalParticipants; }
