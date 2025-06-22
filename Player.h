#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Player : public Entity{
	public:
		Player(sf::RectangleShape body, sf::Vector2f position);
		void update(sf::Time dt, sf::Vector2f playerPosition) override;
		void handleInput(sf::Keyboard::Key&);
		void setLives(int lives);
		void setScore(int score);
		bool getIsOffMap();
		sf::Vector2f getPosition();
		sf::FloatRect getBounds();
		int getScore();
		void die();
	
	private:
		void teleportIfReady();
		int lives;
		int score;
		bool isOffMap = false;
		bool hasTeleported = false;
};
