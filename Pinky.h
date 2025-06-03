class Pinky : public Ghost{
	protected:
		sf::Vector2i chooseTarget(const Map& map, const Player& p) override{
			//scatter - lewy górny róg
			//chase - celuje w 4 pola gridu przed pacmanem
			//flee - losowo
		}
}
