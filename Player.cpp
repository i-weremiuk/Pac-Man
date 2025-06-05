#include <SFML/Graphics.hpp>
#include "Player.h"
#include <vector>
#include <iostream>
#include "Map.h"

Player::Player(sf::RectangleShape body, sf::Vector2f position)
			: Entity(body, position){
				this->body.setFillColor(sf::Color::Red);
				this->body.setOrigin(body.getSize().x / 2.f, body.getSize().y / 2.f);

			}

void Player::update(sf::Time dt){
	if(Map::isCentered(position)){
			bool isPathClear;
			if(turnQueued){					
				isPathClear = Map::checkPath(position, nextTurn);
				if(isPathClear){
					velocity = {nextTurn.x * speed, nextTurn.y * speed};
					turnQueued = false;
				}
			}
			sf::Vector2i currDirection = Map::getCurrDirection(velocity); 
			isPathClear = Map::checkPath(position, currDirection);
			if(!isPathClear){
				std::vector<sf::Vector2i> freePaths = Map::getFreePaths(position);
				std::cerr<<"kilkawolne\n";
				for(sf::Vector2i path : freePaths){
						nextTurn = path;
				}
							std::cerr<<currDirection.x<<" "<<currDirection.y<<"\n";
							std::cerr<<nextTurn.x<<" "<<nextTurn.y<<"\n\n";
				velocity = {nextTurn.x * speed, nextTurn.y * speed};
			}
	}

	position += dt.asSeconds() * velocity;
	body.setPosition(position);
}

void Player::handleInput(sf::Keyboard::Key& key){
	turnQueued = true;
	if(key == sf::Keyboard::Left){
		nextTurn = sf::Vector2i(-1, 0);
	}else if(key == sf::Keyboard::Right){
		nextTurn = sf::Vector2i(1, 0);
	}else if(key == sf::Keyboard::Up){
		nextTurn = sf::Vector2i(0, -1);
	}else if(key == sf::Keyboard::Down){
		nextTurn = sf::Vector2i(0, 1);
	}
}

