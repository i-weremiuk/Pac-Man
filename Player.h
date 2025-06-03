class Player : public Entity{
	public:
		void update(sf::Time dt) override;
		void handleInput(const sf::Keyboard::Key&);
		int getLives() const;
		int getScore() const;
		void setLives();
		void setScore();
		void die();
	
	private:
		int lives;
		int score;
}
