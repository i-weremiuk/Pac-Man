class Game{
	public:
		enum Gamestate {Gameplay, Menu, Pause, Gameover}
		void run();
	private:
		void handleEvents();
		void update(sf::Time dt);
		void render();

		sf::RenderWindow window;
		Map map;
		Player player;
		std::vector<Ghost> ghosts;
		GameState state;
};

