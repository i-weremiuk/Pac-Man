#pragma once
#include "Ghost.h"

class Pinky : public Ghost {
public:
    Pinky(sf::RectangleShape body, sf::Vector2f position);

protected:
    // Scatter: lewy górny róg
    // Chase: 4 pola przed Pac-Manem
    // Debuff: losowo
    sf::Vector2i chooseTargetGridPosition(sf::Vector2f playerPosition) override;
	void teleportIfReady();
			bool hasTeleported = false;
};