//#define NDEBUG /* macros for disable all asserts in each file where it's */
#include "CardGame.h"
#include <cassert>

//prototypes
void endGame(CardGame* [], const size_t);
void startGame(const size_t maxNumbGames, const size_t maxNumbParticipants);

int main(){
	assert(CardGame::getParticipants() == 0);
	startGame(5, 10);
	return 0;
}

void startGame(const size_t maxNumbGames, const size_t maxNumbParticipants){
	srand(time(0)); // Initialize random number generator
	const size_t minNumbGames = 1;
	const size_t minNumbParticipants = 2;
	const int numbGames = (rand() % maxNumbGames) + minNumbGames;
	CardGame *playersArr[numbGames];
	
	/*for(CardGame *x : playersArr)
		x = new CardGame((rand() % maxNumbParticipants) + minNumbParticipants);*/
	for (int i(0); i < numbGames; i++)
		playersArr[i] = new CardGame((rand() % maxNumbParticipants) + minNumbParticipants);
	
	endGame(playersArr, numbGames);
}

void endGame(CardGame *arr[], const size_t size){
	for(int i = 0; i < size; i++) delete arr[i];
	printf("NUMBER PLAYED GAMES: %d\n", size);
}
