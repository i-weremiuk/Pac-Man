#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Player.h"
#include "Ghost.h"
#include "Blinky.h"
#include <vector>

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
		sf::Vector2f playerStartPosition = sf::Vector2f(20.f + 12*40.0f, 20.f + 10*40.0f);
		sf::Vector2f blinkyStartPosition = sf::Vector2f(20.f + 10*40.0f, 20.f + 13*40.0f);
		Player player{sf::RectangleShape(sf::Vector2f(25.0f, 25.0f)), playerStartPosition};
		Blinky blinky{sf::RectangleShape(sf::Vector2f(25.0f, 25.0f)), blinkyStartPosition};
		
		GameState state;
		sf::Clock clock;
};

