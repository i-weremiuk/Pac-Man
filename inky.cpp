#include "Inky.h"
#include "Map.h"
#include "Ghost.h"
#include <vector>
#include <iostream>
#include <cstdlib>

constexpr int GRID_SIZE = 24;
constexpr int MAX_INDEX = GRID_SIZE - 1;

Inky::Inky(sf::RectangleShape body, sf::Vector2f position)
    : Ghost(body, position) {
    this->body.setFillColor(sf::Color::Cyan);
    this->body.setOrigin(body.getSize().x / 2.f, body.getSize().y / 2.f);
    speed *= 0.85f;
}
void Inky::teleportIfReady(){
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
sf::Vector2i Inky::chooseTargetGridPosition(sf::Vector2f playerPosition) {
    // Załóżmy, że kierunek Pac-Mana to ostatni kierunek ruchu (np. w prawo: (1,0))
    // Tutaj przykładowo kierunek domyślny: w prawo
    sf::Vector2i pacmanDir(1, 0); // Możesz podmienić na aktualny kierunek Pac-Mana

    sf::Vector2i pacGrid = Map::getGridPosition(playerPosition);

    // Punkt 2 pola przed Pac-Manem w jego kierunku
    sf::Vector2i przedGrid = pacGrid + pacmanDir * 2;

    // Blinky jest zawsze 5 jednostek niżej niż Pac-Man
    sf::Vector2i blinkyGrid = pacGrid + sf::Vector2i(0, 3);

    // Wektor od Blinky'ego do punktu przed Pac-Manem
    sf::Vector2i delta = przedGrid - blinkyGrid;

    // Cel: blinky + 2 * delta
    sf::Vector2i target = blinkyGrid + delta * 2;

    // Ograniczenie do rozmiaru mapy (zakładamy 25x25)
    target.x = std::clamp(target.x, 0, 24);
    target.y = std::clamp(target.y, 0, 24);

    return target;
}