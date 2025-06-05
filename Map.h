#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
class Map{
	public:
		Map();
		void draw(sf::RenderWindow&);
		bool isWall(const sf::Vector2i& gridPosition) const;
		bool isIntersection(const sf::Vector2i& gridPosition) const;
		std::vector<sf::Vector2i> getPossibleDirections(const sf::Vector2i& gridPosition) const;
		static bool isCentered(sf::Vector2f start_posiiton, sf::Vector2f position);
		static sf::Vector2f centerVertically(sf::Vector2f position);
		static sf::Vector2f centerHorizontally(sf::Vector2f position);

		int getCoinCount() const;
	protected:
		void loadMap(std::string layout[25]);
		static sf::Vector2f tileSize;
		std::string layout[25] =
	 {"############O############",
		"#OOOOOOOOOO#O#OOOOOOOOOO#",
		"#O###O####O#O#O####O###O#",
		"#O###O####O#O#O####O###O#",
		"#OOOOOOOOOOOOOOOOOOOOOOO#",
		"#O####O#O#######O#O####O#",
		"#OOOOOO#OOOO#OOOO#OOOOOO#",
		"#O####O####O#O####O####O#",
		"#O####O#OOOOOOOOO#O####O#",
		"#OOOOOO#O#O#O#O#O#OOOOOO#",
		"######O#OOO#O#OOO#O######",
		"######OOO###O###OOO######",
		"OOOOOOO#O##OOO##O#OOOOOOO",
		"######O#O#######O#O######",
		"######O#OOOOOOOOO#O######",
		"#OOOOOOOO###O###OOOOOOOO#",
		"#O####O#O###O###O#O####O#",
		"#OOOO#O#OOOOOOOOO#O#OOOO#",
		"####O#O#####O#####O#O####",
		"#OOOO#OOOOOOOOOOOOO#OOOO#",
		"#O##O#O##O##O##O##O#O##O#",
		"#OOOOOOO#OOOOOOO#OOOOOOO#",
		"#O#####O####O####O#####O#",
		"#OOOOOOOOOOOOOOOOOOOOOOO#",
		"############O############",
		};
		Tile tiles[25][25];
		std::vector<sf::Vector2f> coins;
		std::vector<sf::Vector2f> boosts;
		sf::Texture wallTexture;
		sf::Texture coinTexture;
		sf::Texture boostTexture;
};
