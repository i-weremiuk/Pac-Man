#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Player : public Entity{
	public:
		Player(sf::RectangleShape body, sf::Vector2f position);
		void update(sf::Time dt, sf::Vector2f playerPosition) override;
		void handleInput(sf::Keyboard::Key&);
		int getLives() const;
		int getScore() const;
		void setLives();
		void setScore();
		void die();
	
	private:
		void teleportIfReady();
		int lives;
		int score;
		bool isOffMap = false;
		bool hasTeleported = false;
};
