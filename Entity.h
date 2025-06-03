class Entity{
	public:
		virtual void update(sf::Time dt) = 0;
		virtual void draw(sf::RenderWindow& window);
		sf::Vector2f getPosition() const;
		void setPosition(const sf::Vector2f&);
		
	protected:
		sf::Sprite sprite;
		sf::Vector2f velocity;
		sf::Vector2f position;
		float speed;
};
