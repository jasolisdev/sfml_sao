#include "../include/game_state.h"
#include "../include/main_menu.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>

using namespace std;

game_state* coreState;
bool exitGame = false;

int main()
{
	// srand(NULL);

	sf::Vector2i screenDimensions(800, 800);
	sf::RenderWindow window;
	window.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Sword Art Online: Attack on Salamander");

	//window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(120);
	
	sf::SoundBuffer soundBuffer;
	sf::Sound sound;
	sf::Music music;

	if (!soundBuffer.loadFromFile("../data/sounds/fireball.wav"))
		std::cout << "Can't find fireball.wav" << std::endl;

	sound.setBuffer(soundBuffer);

	if (music.openFromFile("../data/sounds/sao_everyday.ogg"));

	sound.setVolume(5);
	music.setVolume(50);

	sf::Texture bTexutre;
	sf::Sprite bImage;

	if (!bTexutre.loadFromFile("../data/images/background.png"))
		std::cout << "Could not find background.png" << std::endl;
	bImage.setTexture(bTexutre);
	bImage.setScale(1.0f, (float)screenDimensions.y / bTexutre.getSize().y);
	
	sf::Clock clock;

	music.play();

	// Create Main Menu Window
	coreState = new game_state(&window);
	coreState->SetState(new main_menu());

	// Main Loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Space)
					sound.play();
				break;
			}
		}
		

		// FrameRate Clock
		sf::Time time = clock.getElapsedTime();
		std::cout << 1.0f / time.asSeconds() << std::endl;
		clock.restart().asSeconds();

		window.clear(sf::Color::Black);

		if (exitGame)
		{
			window.close();
		}

		window.draw(bImage);
		
		coreState->Update();

		window.display();
	}

	return 0;
}
