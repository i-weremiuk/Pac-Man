class Game{
	public:
		void run();
	private:
		void getInput();
		void update(sf::Time dt);
		void render();

		sf::RenderWindow window;
		Map map;
		Player player;
		std::vector<Ghost> ghosts;
		GameState state;
};

