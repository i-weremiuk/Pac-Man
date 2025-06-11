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
	if(turnQueued){
		if(Map::isParalell(Map::getCurrDirection(velocity), nextTurn)){
			turn(nextTurn);
		}else if(Map::isCentered(position) && Map::checkPath(position, nextTurn)){
			turn(nextTurn);
		}
	}

	if(Map::isCentered(position)){
		if(!Map::checkPath(position, Map::getCurrDirection(velocity))){
			std::vector<sf::Vector2i> freePaths = Map::getFreePaths(position);
			nextTurn = freePaths[0];
			turn(nextTurn);
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

