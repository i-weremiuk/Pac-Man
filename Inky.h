class Inky : public Ghost{
	protected:
		sf::Vector2i chooseTarget(const Map& map, const Player& p, const Blinky& b) override{
			//scatter - prawy dolny
			//chase - jest w necie na to sprytne wyrażenie
			//on bieże vector położenia blinkiego i playera i na ich podstawie
			//flankuje playera - to nie jest jakieś trudne a działa fajnie
			//flee - losowo
		}
}
