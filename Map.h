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
		static bool isCentered(sf::Vector2f position);
		static bool checkPath(sf::Vector2f position, sf::Vector2i turn);
		static bool isParalell(sf::Vector2i v1, sf::Vector2i v2);
		static std::vector<sf::Vector2i> getFreePaths(sf::Vector2f position);
		static sf::Vector2i getCurrDirection(sf::Vector2f velocity);
		static sf::Vector2i getCurrTile(sf::Vector2f position);
		static Tile getTile(sf::Vector2i position);

		int getCoinCount() const;
	protected:
		void loadMap(std::string layout[25]);
		static float tileSize;
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
		"OOOOOOO#O#OOOOO#O#OOOOOOO",
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
		static Tile tiles[25][25];
		std::vector<sf::Vector2f> coins;
		std::vector<sf::Vector2f> boosts;
		sf::Texture wallTexture;
		sf::Texture coinTexture;
		sf::Texture boostTexture;
};
