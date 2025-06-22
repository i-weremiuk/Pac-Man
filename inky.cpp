#include "Inky.h"
#include "Map.h"
#include <cstdlib>

constexpr int GRID_SIZE = 25;
constexpr int MAX_INDEX = GRID_SIZE - 1;

Inky::Inky(sf::RectangleShape body, sf::Vector2f position)
    : Ghost(body, position) {
    this->body.setFillColor(sf::Color::Cyan);
    this->body.setOrigin(body.getSize().x / 2.f, body.getSize().y / 2.f);
    speed *= 0.85f;
}
void Inky::teleportIfReady(){
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
sf::Vector2i Inky::chooseTargetGridPosition(sf::Vector2f playerPosition) {
    sf::Vector2i pacGrid = Map::getGridPosition(playerPosition);
    if (mode == Scatter) {
        // prawy dolny róg
        return sf::Vector2i(MAX_INDEX, MAX_INDEX);
    } else if (mode == Chase) {
        // 2 pola przed Pac-Manem w prawo (przykładowo)
        sf::Vector2i ahead = pacGrid + sf::Vector2i(2, 0);
        ahead.x = std::clamp(ahead.x, 0, MAX_INDEX);
        ahead.y = std::clamp(ahead.y, 0, MAX_INDEX);
        return ahead;
    } else {
        // Debuff: losowo
        return sf::Vector2i(std::rand() % GRID_SIZE, std::rand() % GRID_SIZE);
    }
}
