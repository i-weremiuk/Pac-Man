#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Map.h"

Player::Player(sf::RectangleShape body, sf::Vector2f position)
			: Entity(body, position){
				this->body.setFillColor(sf::Color::Red);
				this->body.setOrigin(body.getSize().x / 2.f, body.getSize().y / 2.f);

			}

void Player::update(sf::Time dt){
	if(Map::isCentered(startPosition, position)){
			if(turnQueued){
			velocity = nextTurn;
			turnQueued = false;
			}
		
	}
	position += dt.asSeconds() * velocity;
	body.setPosition(position);
}

void Player::handleInput(sf::Keyboard::Key& key){
	turnQueued = true;
	if(key == sf::Keyboard::Left){
//		position = Map::centerVertically(position);
		nextTurn = sf::Vector2f(-speed, 0.f);
	}else if(key == sf::Keyboard::Right){
//	position = Map::centerVertically(position);
		nextTurn = sf::Vector2f(speed, 0.f);
	}else if(key == sf::Keyboard::Up){
//	position = Map::centerHorizontally(position);
		nextTurn = sf::Vector2f(0.f, -speed);
	}else if(key == sf::Keyboard::Down){
//	position = Map::centerHorizontally(position);
		nextTurn = sf::Vector2f(0.f, speed);
	}
}

