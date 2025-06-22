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
		sf::FloatRect getCoinBounds();
		void draw(sf::RenderWindow& window);
		bool doesHaveCoin();
	private:
			sf::RectangleShape body;
			sf::CircleShape coinBody;
			tileType type;
			float tileSize = 40.f;
			bool hasCoin;
			float coinTimer = 0;
			static float coinResetTime;
};
			

