class Map{
	public:
		void draw(sf::RenderWindow&);
		bool load(const std::string& filename);
		bool isWall(const sf::Vector2i& gridPosition) const;
		bool isIntersection(const sf::Vector2i& gridPosition) const;
		std::vector<sf::Vector2i> getPossibleDirections(const sf::Vector2i& gridPosition) const;

		int getCoinCount() const;
private:
		std::vector<std::string> layout;
		std::set<sf::Vector2i> walls;
		std::set<sf::Vector2i> coins;
		std::set<sf::Vector2i> boosts;
		sf::Texture wallTexture;
		sf::Texture coinTexture;
		sf::Texture boostTexture;
};
