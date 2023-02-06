class CardGame{
	private:
		int m_players;
		static int m_totalParticipants;
	public:
		CardGame(int players);
		~CardGame();
		static int getParticipants();
};
