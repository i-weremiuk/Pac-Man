#include "Pinky.h"
#include "Ghost.h"
#include <vector>
#include <iostream>
#include "Map.h"
#include <cstdlib>

constexpr int GRID_SIZE = 25;
constexpr int MAX_INDEX = GRID_SIZE - 1;

Pinky::Pinky(sf::RectangleShape body, sf::Vector2f position)
    : Ghost(body, position) {
    this->body.setFillColor(sf::Color(255, 192, 203));
    this->body.setOrigin(body.getSize().x / 2.f, body.getSize().y / 2.f);
    speed *= 0.9f;
}

void Pinky::teleportIfReady(){
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

sf::Vector2i Pinky::chooseTargetGridPosition(sf::Vector2f playerPosition) {
    sf::Vector2i pacGrid = Map::getGridPosition(playerPosition);

    // Pinky zawsze celuje 4 pola nad Pac-Manem
    sf::Vector2i target = pacGrid + sf::Vector2i(0, -4);
    target.x = std::clamp(target.x, 0, MAX_INDEX);
    target.y = std::clamp(target.y, 0, MAX_INDEX);
    return target;
}
     




