class Blinky : public Ghost{
	protected:
		sf::Vector2i chooseTarget(const Map& map, const Player& p) override{
			// scatter - prawy górny róg
			// chase - celuje w pacmana
			// flee - losowo
		}
}
