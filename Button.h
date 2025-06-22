#include <SFML/Graphics.hpp>
class Button{
	public:
		Button();
		Button(const sf::Vector2f& position, const std::string& text, const sf::Font& font);
		void draw(sf::RenderWindow& window);
		bool isHovered(sf::Vector2f& mousePosition);
		void setText(const std::string& text);
	private:
		sf::RectangleShape body;
		sf::Text label;
		float margin = 10.f;

};
		


