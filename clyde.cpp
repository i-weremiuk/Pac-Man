#include "Clyde.h"
#include <vector>
#include <iostream>
#include "Map.h"
#include "Ghost.h"
#include <cmath>
#include <cstdlib>

// Wielkość siatki 25x25 (0..24)
constexpr int GRID_SIZE = 25;
constexpr int MAX_INDEX = GRID_SIZE - 1;

Clyde::Clyde(sf::RectangleShape body, sf::Vector2f position)
    : Ghost(body, position) {
    this->body.setFillColor(sf::Color(255, 165, 0));
    this->body.setOrigin(body.getSize().x / 2.f, body.getSize().y / 2.f);
    speed *= 0.8f;
}
void Clyde::teleportIfReady(){
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
sf::Vector2i Clyde::chooseTargetGridPosition(sf::Vector2f playerPosition) {
  	return Map::getGridPosition(playerPosition);

    // sf::Vector2i pacGrid = Map::getGridPosition(playerPosition);
   /* if (mode == Scatter) {
        // lewy dolny róg
        return sf::Vector2i(0, MAX_INDEX);
    } else if (mode == Chase) {
        sf::Vector2i selfGrid = Map::getGridPosition(body.getPosition());
        float dx = float(selfGrid.x - pacGrid.x);
        float dy = float(selfGrid.y - pacGrid.y);
        float dist = std::sqrt(dx*dx + dy*dy);
        // goni gdy daleko, w przeciwnym razie wraca do rogu
        return (dist > 8.0f) ? pacGrid : sf::Vector2i(0, MAX_INDEX);
    } else {
        // Debuff: losowo
        return sf::Vector2i(std::rand() % GRID_SIZE, std::rand() % GRID_SIZE);
    }*/
}