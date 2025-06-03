class Inky : public Ghost{
	protected:
		sf::Vector2i chooseTarget(const Map& map, const Player& p) override{
			//scatter - lewy dolny 
			//chase - jak blisko pacmana to ucieka, jak daleko to go goni,
			//jakąś granicę trzeba wybrać
			//flee - losowo
		}
}
