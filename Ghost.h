#include "Entity.h"
#pragma once
class Ghost : public Entity{
	public:
		enum Mode {Scatter, Chase, Debuff};
		Ghost(sf::RectangleShape body, sf::Vector2f startPosition);
		void update(sf::Time dt, sf::Vector2f playerPosition) override;
		void setMode(int state);
		Mode getMode() const;
		void setIsDead(bool state);
		void draw(sf::RenderWindow& window);
		sf::FloatRect getBounds();

	protected:
		Mode mode;
		virtual sf::Vector2i chooseTargetGridPosition(sf::Vector2f playerPosition) = 0;
		sf::Vector2i getNextTurn(sf::Vector2i targetTile);
	
	private: 
		bool isDead = false;
		bool deathTimer = 0.f;
		float deathTimeLimit = 20.f;

};
