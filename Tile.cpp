#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Tile.h"
Tile::Tile(): body(sf::Vector2f(0,0)), type(tileType::Path){
}

Tile::Tile(sf::RectangleShape body, tileType type, bool hasCoin): body(body), type(type), hasCoin(hasCoin){
	coinBody.setPosition(body.getPosition().x + (tileSize /2.f), body.getPosition().y + (tileSize / 2.f) );
	coinBody.setFillColor(sf::Color::Yellow);
	coinBody.setRadius(6.f);
	coinBody.setOrigin(coinBody.getRadius(), coinBody.getRadius());

	boostBody.setPosition(body.getPosition().x + (tileSize /2.f), body.getPosition().y + (tileSize / 2.f) );
	boostBody.setFillColor(sf::Color::Magenta);
	boostBody.setRadius(9.f);
  boostBody.setOrigin(boostBody.getRadius(), boostBody.getRadius());

}

float Tile::coinResetTime = 10.f;

sf::FloatRect Tile::getCoinBounds(){
	return coinBody.getGlobalBounds();
}

sf::FloatRect Tile::getBoostBounds(){
	return boostBody.getGlobalBounds();
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

void Tile::updateBoost(bool boostStatus){
	hasBoost = boostStatus;
}

tileType Tile::getType(){
	return type;
}

void Tile::draw(sf::RenderWindow& window){
	window.draw(body);
	if(hasCoin){
		window.draw(coinBody);
	}
	if(hasBoost){
		window.draw(boostBody);
	}
}

bool Tile::doesHaveCoin(){
	return hasCoin;
}

bool Tile::doesHaveBoost(){
	return hasBoost;
}
