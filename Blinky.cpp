#include <SFML/Graphics.hpp>
#include "Blinky.h"
#include "Ghost.h"
#include <vector>
#include <iostream>
#include "Map.h"

Blinky::Blinky(sf::RectangleShape body, sf::Vector2f position)
	: Ghost(body, position){
		this->body.setFillColor(sf::Color::Blue);
		this->body.setOrigin(body.getSize().x / 2.f, body.getSize().y / 2.f);
		speed *= 0.9;
	}
void Blinky::teleportIfReady(){
	sf::Vector2i currTile = Map::getGridPosition(position);
	if(Map::isCentered(position)){
		if(currTile == sf::Vector2i{-1,12}){
			position = Map::castToPosition(sf::Vector2i{25, 12});
			hasTeleported = true;
		}
		if(currTile == sf::Vector2i{25, 12}){
			position = Map::castToPosition(sf::Vector2i{-1,12});
			hasTeleported = true;
		}
		if(currTile == sf::Vector2i{12,-1}){
			position = Map::castToPosition(sf::Vector2i{12,25});
			hasTeleported = true;
		}
		if(currTile == sf::Vector2i{12,25}){
			position = Map::castToPosition(sf::Vector2i{12, -1});
			hasTeleported = true;
		}
	}
}
sf::Vector2i Blinky::chooseTargetGridPosition(sf::Vector2f playerPosition){
	return Map::getGridPosition(playerPosition);
}	






