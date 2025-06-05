#include <SFML/Graphics.hpp>
class Entity{
	public:
		Entity(sf::RectangleShape body, sf::Vector2f position);
		virtual void update(sf::Time dt) = 0;
		void draw(sf::RenderWindow& window);
		sf::Vector2f getPosition() const;
		
	protected:
		sf::RectangleShape body;
		sf::Vector2f velocity;
		sf::Vector2f position;
		sf::Vector2f startPosition;
		sf::Vector2f nextTurn;
		bool turnQueued;
		float speed = 70.0f;
};
