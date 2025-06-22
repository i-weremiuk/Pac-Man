#pragma once
#include "Ghost.h"

class Blinky; // forward

class Inky : public Ghost {
public:
    Inky(sf::RectangleShape body, sf::Vector2f position);

protected:
    // Scatter: prawy dolny róg
    // Chase: wykorzystuje wektor miedzy Blinky a 2 kratek przed Pac-Manem
    // Debuff: losowo
    sf::Vector2i chooseTargetGridPosition(sf::Vector2f playerPosition) override;
	void teleportIfReady();
			bool hasTeleported = false;
};
