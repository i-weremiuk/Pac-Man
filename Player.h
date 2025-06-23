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
		void setGodMode(bool state);
		void setIsDead(bool state);
		void setPosition(sf::Vector2f position);
		bool getIsGod();
		bool getIsDead();
		bool getIsInvicible();
		void draw(sf::RenderWindow& window);
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
		bool isGod = false;
		bool isDead = false;
		bool isInvicible = true;
		float invicibleTimer = 0.f;
		float deathTimer = 0.f;
		float deathTimeLimit = 10.f;
		float godTimer = 0.f;
		float godTimeLimit = 10.0f;
		
};
