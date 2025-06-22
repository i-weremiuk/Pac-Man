#include "Clyde.h"
#include <vector>
#include <iostream>
#include "Map.h"
#include "Ghost.h"
#include <cmath>
#include <cstdlib>

// Wielkość siatki 25x25 (0..24)
constexpr int GRID_SIZE = 24;
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
    sf::Vector2i pacGrid = Map::getGridPosition(playerPosition);
    sf::Vector2i selfGrid = Map::getGridPosition(body.getPosition());

    // Manhattan distance
    int dist = std::abs(selfGrid.x - pacGrid.x) + std::abs(selfGrid.y - pacGrid.y);

    sf::Vector2i scatterCorner(0, 0); // lewy górny róg

    if (mode == Scatter) {
        return scatterCorner;
    } else if (mode == Chase) {
        if (selfGrid == scatterCorner) {
            // Jeśli Clyde jest w lewym górnym rogu, goni Pac-Mana
            return pacGrid;
        }
        if (dist > 8) {
            // Goni Pac-Mana
            return pacGrid;
        } else {
            // Wycofuje się do scatter-corner
            return scatterCorner;
        }
    } else {
        // Debuff: losowo
        return sf::Vector2i(std::rand() % GRID_SIZE, std::rand() % GRID_SIZE);
    }
}