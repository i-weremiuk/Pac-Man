#pragma once
#include <SFML/Graphics.hpp>
#include "TileType.h"
class Tile{
	public:
		Tile();
		Tile(sf::RectangleShape body, tileType type, bool hasCoin);
		tileType getType();
		void update(sf::Time dt);
		void updateCoin(bool hasCoin);
		void updateBoost(bool hasBoost);
		sf::FloatRect getCoinBounds();
		sf::FloatRect getBoostBounds();
		void draw(sf::RenderWindow& window);
		bool doesHaveCoin();
		bool doesHaveBoost();
	private:
		sf::RectangleShape body;
		sf::CircleShape coinBody;
		sf::CircleShape boostBody;
		tileType type;
		float tileSize = 40.f;

		bool hasCoin;
		float coinTimer = 0;
		static float coinResetTime;

		bool hasBoost;
};
			

