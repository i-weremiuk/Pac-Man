#pragma once
#include <SFML/Graphics.hpp>
#include "TileType.h"
class Tile{
	public:
		Tile();
		Tile(sf::RectangleShape body, tileType type);
		tileType getType();
		void draw(sf::RenderWindow& window);
	private:
			sf::RectangleShape body;
			tileType type;
};
			

