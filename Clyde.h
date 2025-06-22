#pragma once
#include "Ghost.h"
#include "Map.h"

class Clyde : public Ghost {
public:
    Clyde(sf::RectangleShape body, sf::Vector2f position);

protected:
    // Scatter: dolny lewy róg
    // Chase: goni Pac-Mana gdy jest daleko (>8 kratek), w przeciwnym razie wraca do scatter
    // Debuff: losowo biega
    sf::Vector2i chooseTargetGridPosition(sf::Vector2f playerPosition) override;
			void teleportIfReady();
			bool hasTeleported = false;

};