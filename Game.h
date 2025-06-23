#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Player.h"
#include "Ghost.h"
#include "Blinky.h"
#include "Clyde.h"
#include "Inky.h"
#include "Pinky.h"
#include "Button.h"
#include <vector>

class Game{
	public:
		Game();
		enum GameState {Gameplay, Menu, Pause, Gameover};
		void run();
		void pause();
		void restart();
	private:
		void handleEvents(sf::Event event);
		void update(sf::Time dt);
		void render();
		sf::Font font;

		sf::VideoMode videoMode{1000, 1000};
		sf::RenderWindow window{videoMode, "Pac-Man", sf::Style::Titlebar | sf::Style::Close};
		Map map;
		sf::Vector2f playerStartPosition = sf::Vector2f(20.f + 12*40.0f, 20.f + 10*40.0f);
		sf::Vector2f blinkyStartPosition = sf::Vector2f(20.f + 10*40.0f, 20.f + 13*40.0f);
		sf::Vector2f pinkyStartPosition{20.f + 11*40.f, 20.f + 13*40.f};
    sf::Vector2f inkyStartPosition  {20.f + 12*40.f, 20.f + 13*40.f};
    sf::Vector2f clydeStartPosition {20.f + 13*40.f, 20.f + 13*40.f};

		Player player{sf::RectangleShape(sf::Vector2f(25.0f, 25.0f)), playerStartPosition};
		Blinky blinky{sf::RectangleShape(sf::Vector2f(25.0f, 25.0f)), blinkyStartPosition};
		Pinky pinky{sf::RectangleShape(sf::Vector2f(25.f,25.f)), pinkyStartPosition};
    Inky   inky  {sf::RectangleShape(sf::Vector2f(25.f,25.f)), inkyStartPosition};
    Clyde  clyde {sf::RectangleShape(sf::Vector2f(25.f,25.f)), clydeStartPosition};
		
		sf::Vector2f scoreButtonPosition = sf::Vector2f(20*40.f,0);
		Button scoreButton;

		GameState state;
		sf::Clock clock;

		float boostResetTime = 15.0f;
		float boostTimer = 0.f;

};

