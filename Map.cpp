#include <SFML/Graphics.hpp>
#include "Map.h"
#include "cmath"
#include <iostream>
#include "Tile.h"
#include <vector>

Map::Map(){
	loadMap(layout);
}
float Map::tileSize = 40.0f;
int Map::mapSize = 25;
float Map::tileCenterOffset = 20.0f;
Tile Map::tiles[25][25];

void Map::loadMap(std::string layout[25]){
	for(int i=0;i<mapSize;i++){
		for(int j=0;j<mapSize;j++){
			char c = layout[i][j];
			sf::RectangleShape body(sf::Vector2f(tileSize, tileSize));
			body.setPosition(j*tileSize,i*tileSize);
			sf::Color color;
			tileType type;
			if(c == '#'){
				color = sf::Color::Blue;
				type = Wall;
			}else{
				color = sf::Color::White;
				type = Path;
			}
			body.setFillColor(color);
			tiles[i][j] = Tile(body,type);
		}
	}
}

void Map::draw(sf::RenderWindow& window){
	for(int i=0;i<mapSize;i++){
		for(int j=0;j<mapSize;j++){
			tiles[i][j].draw(window);
		}
	}
}

sf::Vector2i Map::getCurrTile(sf::Vector2f position){
	int x = (int)(std::floor(position.x / tileSize));
	int y = (int)(std::floor(position.y / tileSize));
	return sf::Vector2i(x,y);
}

Tile Map::getTile(sf::Vector2i position){
	return tiles[position.y][position.x];
}

bool Map::isLeavingMap(sf::Vector2f position){
	if(
			position.x <= tileCenterOffset + 5.f || 
			position.x >= mapSize*tileSize - (tileCenterOffset + 5.f) ||
			position.y <= tileCenterOffset + 5.f ||
			position.y >= mapSize*tileSize - (tileCenterOffset + 5.f)
		){
		return true;
	}
	return false;

}




bool Map::checkPath(sf::Vector2f position, sf::Vector2i turn){

	sf::Vector2i currTile = getCurrTile(position);
	currTile += turn;

	if(getTile(currTile).getType() == Wall){
		return false;
	}else if(getTile(currTile).getType() == Path){
		return true;
	}
	return false;
}
bool Map::isParalell(sf::Vector2i v1, sf::Vector2i v2){
	if(v1 == v2 || v1 == v2*-1){
		return true;
	}
	return false;
}
		
std::vector<sf::Vector2i> Map::getFreePaths(sf::Vector2f position){
	sf::Vector2i currTile = getCurrTile(position);
	std::vector<sf::Vector2i> freePaths;

	if(getTile(currTile + sf::Vector2i(0, -1)).getType() == Path){
		freePaths.push_back(sf::Vector2i(0, -1));
	}
	if(getTile(currTile + sf::Vector2i(0, 1)).getType() == Path){
		freePaths.push_back(sf::Vector2i(0, 1));
	}
	if(getTile(currTile + sf::Vector2i(1, 0)).getType() == Path){
		freePaths.push_back(sf::Vector2i(1,0));
	}
	if(getTile(currTile + sf::Vector2i(-1, 0)).getType() == Path){
		freePaths.push_back(sf::Vector2i(-1,0));
	}
	return freePaths;
}
sf::Vector2i Map::castToBaseVector(sf::Vector2f vec){
	int x_i = 0;
	int y_i = 0;
	if(vec.x > 0){
		x_i = 1;
	}
	if(vec.x < 0){
		x_i = -1;
	}
	if(vec.y > 0){
		y_i = 1;
	}
	if(vec.y <0){
		y_i = -1;
	}
	return sf::Vector2i(x_i,y_i);
}

sf::Vector2f Map::castToPosition(sf::Vector2i tilePosition){
	return sf::Vector2f(tilePosition.x * tileSize + tileCenterOffset, tilePosition.y * tileSize + tileCenterOffset);
}
sf::Vector2i Map::getCurrDirection(sf::Vector2f velocity){
	return castToBaseVector(velocity);
}

bool Map::isCentered(sf::Vector2f position){
	sf::Vector2i currTile = getCurrTile(position);	
	sf::Vector2f tileCenter((currTile.x + 0.5f) * tileSize, (currTile.y + 0.5f) * tileSize);
	float eps = 1.f;
	if(std::abs(position.x - tileCenter.x) < eps && std::abs(position.y - tileCenter.y) < eps){
		return true;
	}
	return false;
}

