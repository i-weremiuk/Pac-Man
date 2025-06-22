#include <SFML/Graphics.hpp>
#include "Button.h"
Button::Button(){
}
Button::Button(const sf::Vector2f& position, const std::string& text, const sf::Font& font) :
label(text, font, 24){
	label.setFillColor(sf::Color::Black);
	label.setPosition(position);

	sf::FloatRect labelBounds = label.getGlobalBounds();
	body.setPosition(position);
	body.setSize({labelBounds.width + 3*margin, labelBounds.height + margin});
	body.setFillColor(sf::Color::Green);
}

void Button::draw(sf::RenderWindow& window){
	window.draw(body);
	window.draw(label);
}

void Button::setText(const std::string& text){
	label.setString(text);
}


