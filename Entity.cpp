#include <SFML/Graphics.hpp>
#include "Entity.h"
Entity::Entity(sf::RectangleShape body, sf::Vector2f position)
			: body(body), startPosition(position), position(position){
				body.setPosition(position);
				velocity = sf::Vector2f(speed, 0.0f);
			}

void Entity::draw(sf::RenderWindow& window){
	window.draw(body);
}
