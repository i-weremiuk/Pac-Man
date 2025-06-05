#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Tile.h"
Tile::Tile(): body(sf::Vector2f(0,0)), type(tileType::Path){
}

Tile::Tile(sf::RectangleShape body, tileType type): body(body), type(type){
}

tileType Tile::getType(){
	return type;
}

void Tile::draw(sf::RenderWindow& window){
	window.draw(body);
}
