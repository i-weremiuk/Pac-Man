#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Tile.h"
Tile::Tile(): body(sf::Vector2f(0,0)), type(tileType::Path){
}

Tile::Tile(sf::RectangleShape body, tileType type, bool hasCoin): body(body), type(type), hasCoin(hasCoin){
	coinBody.setPosition(body.getPosition().x + (tileSize /2.f), body.getPosition().y + (tileSize / 2.f) );
	coinBody.setFillColor(sf::Color::Yellow);
	coinBody.setRadius(7.f);
	coinBody.setOrigin(coinBody.getRadius(), coinBody.getRadius());
}

float Tile::coinResetTime = 10.f;

sf::FloatRect Tile::getCoinBounds(){
	return coinBody.getGlobalBounds();
}

void Tile::update(sf::Time dt){
	if(type == Wall){
		return;
	}

	if(!hasCoin){
		coinTimer += dt.asSeconds();
	}
	if(coinTimer >= coinResetTime){
		coinTimer = 0.f;
		hasCoin = true;
	}
}

void Tile::updateCoin(bool coinStatus){
	hasCoin = coinStatus;
}

tileType Tile::getType(){
	return type;
}

void Tile::draw(sf::RenderWindow& window){
	window.draw(body);
	if(hasCoin){
		window.draw(coinBody);
	}
}

bool Tile::doesHaveCoin(){
	return hasCoin;
}
