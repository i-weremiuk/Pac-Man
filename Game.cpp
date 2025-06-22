#include "Game.h"
#include <SFML/Graphics.hpp>


void Game::run(){
	while(window.isOpen()){
		
		sf::Event event;
		while(window.pollEvent(event)){
				handleEvents(event);
		}

		sf::Time dt = clock.restart();

		update(dt);
		render();
		window.display();

	}
}

void Game::handleEvents(sf::Event event){
	if(event.type == sf::Event::Closed){
		window.close();
	}else if(event.type == sf::Event::KeyPressed){
		sf::Keyboard::Key& k = event.key.code;
		if(k == sf::Keyboard::Escape){
			window.close();
			//w przyszłości menu coś tam jakieś
		}else if(k == sf::Keyboard::Left || k == sf::Keyboard::Right ||
				k == sf::Keyboard::Up || k == sf::Keyboard::Down){
			player.handleInput(k);
		}
	}
}

void Game::render(){
	map.draw(window);
	player.draw(window);
	blinky.draw(window);
	pinky.draw(window);
    inky.draw(window);
    clyde.draw(window);
}

void Game::update(sf::Time time){
	sf::Vector2f playerPos = player.getPosition();
	player.update(time, playerPos);
	blinky.update(time, playerPos);
	pinky.update(time, playerPos);
    inky.update(time, playerPos);
    clyde.update(time, playerPos);
}

