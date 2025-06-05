#include <SFML/Graphics.hpp>
class Button{
	public:
		Button(sf::RectangleShape body, sf::Vector2f& position, std::string& text sf::Color& color);
		void draw(sf::RenderWindow& window);
		bool isHovered(sf::Vector2f& mousePosition);
	private
		sf::RectangleShape body;
		sf::Text label;
};
		


