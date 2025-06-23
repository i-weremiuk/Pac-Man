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


void Player::teleportIfReady(){
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

bool Player::getIsOffMap(){
	return isOffMap;
}

sf::FloatRect Player::getBounds(){
	return body.getGlobalBounds();
}

void Player::update(sf::Time dt, sf::Vector2f playerPos){
	if(isDead){
		deathTimer += dt.asSeconds();
		if(deathTimer >= deathTimeLimit){
			deathTimer = 0.f;
			isDead = false;
		}
		return;
	}
	if(Map::isLeavingMap(position)){
		isOffMap = true;
	}else{
		hasTeleported = false;
		isOffMap = false;
	}

	if(isGod){
		godTimer += dt.asSeconds();
		if(godTimer >= godTimeLimit){
			isGod = false;
			godTimer = 0.f;
		}
	}

	if(isOffMap){ 
		if(!hasTeleported){
			teleportIfReady();
		}
	}else{
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
	}


	position += dt.asSeconds() * velocity;
	body.setPosition(position);

}

void Player::setScore(int scoreState){
	score = scoreState;
}

int Player::getScore(){
	return score;
}

sf::Vector2f Player::getPosition(){
	return body.getPosition();
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

void Player::setGodMode(bool state){
	isGod = state;
}

void Player::setIsDead(bool state){
	isDead = state;
}

bool Player::getIsGod(){
	return isGod;
}

bool Player::getIsDead(){
	return isDead;
}
void Player::draw(sf::RenderWindow& window){
	if(!isDead){
		window.draw(body);
	}
}

void Player::setPosition(sf::Vector2f position){
	body.setPosition(position);
}
