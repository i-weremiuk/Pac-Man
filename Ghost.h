#include "Entity.h"
#pragma once
class Ghost : public Entity{
	public:
		enum Mode {Scatter, Chase, Debuff};
		Ghost(sf::RectangleShape body, sf::Vector2f startPosition);
		void update(sf::Time dt, sf::Vector2f playerPosition) override;
		//Scatter - uciekają każdy do swojego rogu
		//Chase  - gonią pacmana każdy własną logike do tego ma
		//flee - jak pacman zje buffa to one się robią wolniejsze, losowo biegają i można je zjeść
		void setMode(Mode m);
		Mode getMode() const;

	protected:
		Mode mode;
		virtual sf::Vector2i chooseTargetTile(sf::Vector2f playerPosition) = 0;
		sf::Vector2i getNextTurn(sf::Vector2i targetTile);
};
