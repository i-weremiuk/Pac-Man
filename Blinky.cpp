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
	}

sf::Vector2i Blinky::chooseTargetTile(sf::Vector2f playerPosition){
	return Map::getCurrTile(playerPosition);
}	






