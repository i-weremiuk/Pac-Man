#include <SFML/Graphics.hpp>
#include "Ghost.h"
#include "Map.h"
#include "Entity.h"
#include <vector>
#include <iostream>

Ghost::Ghost(sf::RectangleShape body, sf::Vector2f position)
	: Entity(body, position){
	}

sf::Vector2i Ghost::getNextTurn(sf::Vector2i targetTile) {
    sf::Vector2i selfGrid = Map::getGridPosition(body.getPosition());
    sf::Vector2i currDir = Map::getCurrDirection(velocity);

    // Możliwe kierunki ruchu
    std::vector<sf::Vector2i> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    // Sprawdź dostępne ścieżki (nie ściany)
    std::vector<sf::Vector2i> validDirs;
    for (const auto& dir : directions) {
        // Nie zawracaj, chyba że to jedyna opcja (ślepa uliczka)
        if (dir == -currDir) continue;
        sf::Vector2i next = selfGrid + dir;
        if (next.x >= 0 && next.x < 24 &&
            next.y >= 0 && next.y < 24) {
            // Map::getTile wymaga referencji
            sf::Vector2i nextCopy = next;
            if (Map::getTile(nextCopy).getType() == Path) {
                validDirs.push_back(dir);
            }
        }
    }

    // Jeśli nie ma innych opcji niż zawrócenie (ślepa uliczka), pozwól na zawrócenie
    if (validDirs.empty()) {
        sf::Vector2i back = -currDir;
        sf::Vector2i next = selfGrid + back;
        if (next.x >= 0 && next.x < 24 &&
            next.y >= 0 && next.y < 24) {
            sf::Vector2i nextCopy = next;
            if (Map::getTile(nextCopy).getType() == Path) {
                return back;
            }
        }
        // Jeśli nawet nie można zawrócić, zostań w miejscu
        return {0, 0};
    }

    // Wybierz kierunek, który minimalizuje odległość do celu
    sf::Vector2i bestDir = validDirs[0];
    int minDist = std::abs((selfGrid + bestDir).x - targetTile.x) + std::abs((selfGrid + bestDir).y - targetTile.y);
    for (const auto& dir : validDirs) {
        sf::Vector2i next = selfGrid + dir;
        int dist = std::abs(next.x - targetTile.x) + std::abs(next.y - targetTile.y);
        if (dist < minDist) {
            minDist = dist;
            bestDir = dir;
        }
    }
    return bestDir;
}

void Ghost::update(sf::Time dt, sf::Vector2f playerPosition){
	if(isDead){
		deathTimer += dt.asSeconds();
		if(deathTimer >= deathTimeLimit){
			deathTimer = 0.f;
			isDead = false;
		}
		return;
	}

		sf::Vector2i targetTile = chooseTargetGridPosition(playerPosition);
		nextTurn = getNextTurn(targetTile);
		if(Map::isParalell(Map::getCurrDirection(velocity), nextTurn)){
			turn(nextTurn);
		}else if(Map::isCentered(position) && Map::checkPath(position, nextTurn)){
			turn(nextTurn);
		}

	
		position += dt.asSeconds() * velocity;
		body.setPosition(position);
}

void Ghost::draw(sf::RenderWindow& window){
	if(!isDead){
		window.draw(body);
	}
}


void Ghost::setIsDead(bool state){
	isDead = state;
	deathTimer = 0.f;
}

void Ghost::setMode(int state){
	if(state == 1){
		mode = Scatter;
	}
}

sf::FloatRect Ghost::getBounds(){
	return body.getGlobalBounds();
}

void Ghost::setIsWaiting (bool state){
	isWaiting = state;
}
void Ghost::setPosition(sf::Vector2f position){
	body.setPosition(position);
}




