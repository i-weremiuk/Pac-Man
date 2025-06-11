#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Player.h"
class Game{
	public:
		enum GameState {Gameplay, Menu, Pause, Gameover};
		void run();
		void pause();
		void restart();
	private:
		void handleEvents(sf::Event event);
		void update(sf::Time dt);
		void render();

		sf::VideoMode videoMode{1000, 1000};
		sf::RenderWindow window{videoMode, "Pac-Man", sf::Style::Titlebar | sf::Style::Close};
		Map map;
		sf::Vector2f player_start_position = sf::Vector2f(20.f + 12*40.0f, 20.f + 10*40.0f);
		Player player{sf::RectangleShape(sf::Vector2f(25.0f, 25.0f)), player_start_position};
	//	std::vector<Ghost> ghosts;
		
		GameState state;
		sf::Clock clock;
};

