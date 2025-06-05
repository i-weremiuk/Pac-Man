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
Tile Map::tiles[25][25];

void Map::loadMap(std::string layout[25]){
	char c;
	for(int i=0;i<25;i++){
		for(int j=0;j<25;j++){
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
	for(int i=0;i<25;i++){
		for(int j=0;j<25;j++){
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
sf::Vector2i castToBaseVector(sf::Vector2f vec){
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
sf::Vector2i Map::getCurrDirection(sf::Vector2f velocity){
	return castToBaseVector(velocity);
}

bool Map::isCentered(sf::Vector2f position){
	sf::Vector2i currTile = getCurrTile(position);	
	sf::Vector2f tileCenter((currTile.x + 0.5f) * tileSize, (currTile.y + 0.5f) * tileSize);
	float eps = 1.f;
	if(std::abs(position.x - tileCenter.x) < eps &&
			std::abs(position.y - tileCenter.y) < eps){
		return true;
	}else{
		return false;
	}
}
/*
	float eps = 0.1f;
	float dx = std::abs(position.x - start_position.x);
	float dy = std::abs(position.y - start_position.y);
	float mx = std::fmod(dx, tileSize);
	float my = std::fmod(dy, tileSize);
	if((mx < eps || std::abs(mx - tileSize) < eps) &&
		(my < eps || std::abs(my - tileSize) < eps)){
		return true;
	}
	return false;
}
*/

