#pragma once
#include "Ghost.h"
class Blinky : public Ghost{
	public:
		Blinky(sf::RectangleShape body, sf::Vector2f position);
		sf::Vector2i chooseTargetTile(sf::Vector2f playerPosition) override;
};
