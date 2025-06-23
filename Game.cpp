#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game(){
	if(!font.loadFromFile("OpenSans-Regular.ttf")){
		std::cout<<"błąd\n";
	}else{
		std::cout<<"git\n";
	}
	scoreButton = Button{scoreButtonPosition, "score : 0", font};
  
}

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

	scoreButton.draw(window);
}



void Game::update(sf::Time time){
	boostTimer += time.asSeconds();
	if(boostTimer >= boostResetTime){
		map.putBoost(map.generateRandomGridPosition());		
		boostTimer = 0.f;
	}
	sf::Vector2f playerPos = player.getPosition();
	if(!player.getIsOffMap()){
		if(map.gotCoin(player.getBounds(), playerPos)){
			player.setScore(player.getScore() +1);
			scoreButton.setText(std::string("score : ") + std::to_string(player.getScore()));
		}
		if(map.gotBoost(player.getBounds(), playerPos)){
			player.setGodMode(true);
			blinky.setMode(1);
			pinky.setMode(1);
			clyde.setMode(1);
			inky.setMode(1);
		}
		if(!player.getIsInvicible()){

		if(player.getBounds().intersects(blinky.getBounds())){
			if(player.getIsGod()){
				blinky.setIsDead(true);
			}else{
				player.setIsDead(true);
				player.setPosition(playerStartPosition);
			}
		}
		if(player.getBounds().intersects(clyde.getBounds())){
			if(player.getIsGod()){
				clyde.setIsDead(true);
			}else{
				player.setIsDead(true);
				player.setPosition(playerStartPosition);
			}
		}
		if(player.getBounds().intersects(inky.getBounds())){
			if(player.getIsGod()){
				inky.setIsDead(true);
			}else{
				player.setIsDead(true);
				player.setPosition(playerStartPosition);
			}
		}
		if(player.getBounds().intersects(pinky.getBounds())){
			if(player.getIsGod()){
				pinky.setIsDead(true);
			}else{
				player.setIsDead(true);
				player.setPosition(playerStartPosition);
			}
		}
		}
	}


	

	player.update(time, playerPos);
	map.update(time);
	blinky.update(time, playerPos);
	pinky.update(time, playerPos);
  inky.update(time, playerPos);
  clyde.update(time, playerPos);
}
