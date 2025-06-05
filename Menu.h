#include <SFML/Graphics.hpp>
#include "Button.h"

class Menu{
	public:
		Menu();
		void draw(sf::RenderWindow& window);
		void update(sf::Event event, sf::Vector2f mousePosition);
	private:
		std::vector<Button> buttons;
		sf::RectangleShape body;
};
