#include <SFML/Graphics.hpp>
#include "Map.h"
#include "cmath"
#include <iostream>
#include "Tile.h"

Map::Map(){
	loadMap(layout);
}
sf::Vector2f Map::tileSize = sf::Vector2f(40.0f, 40.0f);
void Map::loadMap(std::string layout[25]){
	char c;
	for(int i=0;i<25;i++){
		for(int j=0;j<25;j++){
			char c = layout[i][j];
			sf::RectangleShape body(tileSize);
			body.setPosition(j*tileSize.x,i*tileSize.x);
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

bool Map::isCentered(sf::Vector2f start_position, sf::Vector2f position){
	
	float eps = 0.1f;
	float dx = std::abs(position.x - start_position.x);
	float dy = std::abs(position.y - start_position.y);
	float mx = std::fmod(dx, tileSize.x);
	float my = std::fmod(dy, tileSize.x);
	if((mx < eps || std::abs(mx - tileSize.x) < eps) &&
		(my < eps || std::abs(my - tileSize.x) < eps)){
		return true;
	}
	return false;
}

sf::Vector2f Map::centerVertically(sf::Vector2f position){
	position.y = std::round(position.y /tileSize.x/2.f) * tileSize.x/2.f;
	return position;
}
sf::Vector2f Map::centerHorizontally(sf::Vector2f position){
	position.x = std::round(position.x / tileSize.x/2.f) * tileSize.x/2.f;
	return position;
}
	


