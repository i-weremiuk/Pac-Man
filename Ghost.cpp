#include <SFML/Graphics.hpp>
#include "Ghost.h"
#include "Entity.h"
#include <vector>
#include <iostream>
#include "Map.h"

Ghost::Ghost(sf::RectangleShape body, sf::Vector2f position)
	: Entity(body, position){
	}

sf::Vector2i Ghost::getNextTurn (sf::Vector2i targetGridPosition){

	sf::Vector2i currGridPosition = Map::getGridPosition(position);

	sf::Vector2i horizontal = 
		Map::castToBaseVector(sf::Vector2f(targetGridPosition.x - currGridPosition.x, 0.f));

	sf::Vector2i vertical = 
		Map::castToBaseVector(sf::Vector2f(0.f, targetGridPosition.y - currGridPosition.y));

	std::vector<sf::Vector2i> freePaths = Map::getFreePaths(position);

	for(auto v : freePaths){
		if(v == horizontal){
			return v;
		}
		if(v == vertical){
			return v;
		}
	}

	return freePaths[0];
}

void Ghost::update(sf::Time dt, sf::Vector2f playerPosition){

	sf::Vector2i targetTile = chooseTargetGridPosition(playerPosition);
	nextTurn = getNextTurn(targetTile);
	if(Map::isParalell(Map::getCurrDirection(velocity), nextTurn)){
		turn(nextTurn);
	}else if(Map::isCentered(position) && Map::checkPath(position, nextTurn)){
		turn(nextTurn);
	}

	
	position += dt.asSeconds() * velocity;
	body.setPosition(position);
}
