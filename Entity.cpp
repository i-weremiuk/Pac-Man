#include <SFML/Graphics.hpp>
#include "Entity.h"
Entity::Entity(sf::RectangleShape body, sf::Vector2f position)
			: body(body), startPosition(position), position(position){
				body.setPosition(position);
				velocity = sf::Vector2f(0.f, -speed);
			}

void Entity::turn(sf::Vector2i turnVector){
	velocity = {turnVector.x * speed, turnVector.y * speed};
	turnQueued = false;
}

void Entity::draw(sf::RenderWindow& window){
	window.draw(body);
}
