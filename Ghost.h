class Ghost : public Entity{
	public:
		enum Mode {Scatter, Chase, Debuff};
		//Scatter - uciekają każdy do swojego rogu
		//Chase  - gonią pacmana każdy własną logike do tego ma
		//flee - jak pacman zje buffa to one się robią wolniejsze, losowo biegają i można je zjeść
		Ghost(const sf::Vector2i& startPosition);
		void update(sf::Time dt) override;
		void setMode(Mode m);
		Mode getMode() const;

	protected:
		Mode mode;
		virtual sf::Vector2i chooseTraget(const Map& map, const Player& p) = 0;
		void moveOnGrid(const Map& map);
};
