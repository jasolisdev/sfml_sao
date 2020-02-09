#include <stdio.h>
#include "../include/main_menu.h"
#include "../include/main_game.h"
#include "../include/main_options.h"

void main_options::Initialize(sf::RenderWindow* window)
{
	sf::Font* font = new sf::Font();
	font->loadFromFile("../data/fonts/sao.ttf");

	this->titleTop = new sf::Text("Game Settings", *font, 100U);
	this->titleBottom = new sf::Text("", *font, 50U);

	this->titleTop->setPosition(sf::Vector2f(window->getSize().y / 5, this->titleTop->getCharacterSize() * 0.1f));

	this->titleBottom->setOrigin(sf::Vector2f(this->titleBottom->getCharacterSize() / 2, this->titleBottom->getCharacterSize() / 2));
	this->titleBottom->setPosition(sf::Vector2f(window->getSize().y / 2, this->titleTop->getCharacterSize() * 1.5f));

	this->video = new sf::Text("Video Settings", *font, 70U);
	this->audio = new sf::Text("Audio Settings", *font, 70U);
	this->menu = new sf::Text("Main Menu", *font, 70U);

	this->video->setPosition(sf::Vector2f(window->getSize().y / 10 + this->video->getGlobalBounds().width / 2, this->titleTop->getCharacterSize() * 3.5f));
	this->audio->setPosition(sf::Vector2f(window->getSize().y / 10 + this->audio->getGlobalBounds().width / 2, this->titleTop->getCharacterSize() * 4.0f));
	this->menu->setPosition(sf::Vector2f(window->getSize().y / 10 + this->menu->getGlobalBounds().width / 2, this->titleTop->getCharacterSize() * 4.5f));

	//this->video->setOrigin(sf::Vector2f(this->titleBottom->getCharacterSize() / 2, this->titleBottom->getCharacterSize() / 2));
	//this->audio->setOrigin(sf::Vector2f(this->titleBottom->getCharacterSize() / 1, this->titleBottom->getCharacterSize() / 1));
	//this->menu->setOrigin(sf::Vector2f(this->titleBottom->getCharacterSize() / 4, this->titleBottom->getCharacterSize() / 4));

	this->grow = 0.0025f;
	this->scaleSize = 1.0f;

	this->selected = 0;

}
void main_options::Update(sf::RenderWindow* window)
{
	this->scaleSize += this->grow;
	if (this->scaleSize > 1.0f || this->scaleSize < 0.9)
	{
		this->grow *= -1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !downKey)
	{
		this->selected += 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && selected > 2)
	{
		this->selected -= 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !upKey)
	{
		this->selected -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && selected < 0)
	{
		this->selected += 3;
	}
	/*
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && selected < 0)
	{
	this->selected += 2;
	}

	if (this->selected > 1)
	{
	this->selected = 0;
	}
	if (this->selected > 0)
	{
	this->selected = 2;
	}
	if (this->selected < 0)
	{
	this->selected = 1;
	}
	*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
	{
		switch (this->selected)
		{
		case 0:
		//	coreState->SetState(new main_game());
			break;
		case 1:
		//	coreState->SetState(new main_options());
			break;
		case 2:
			coreState->SetState(new main_menu());
			break;
		}
	}
this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
}

void main_options::Render(sf::RenderWindow* window)
{
	this->video->setScale(sf::Vector2f(1, 1));
	this->audio->setScale(sf::Vector2f(1, 1));
	this->menu->setScale(sf::Vector2f(1, 1));

	switch (this->selected)
	{
	case 0:
		this->video->setScale(sf::Vector2f(scaleSize, scaleSize));
		break;
	case 1:
		this->audio->setScale(sf::Vector2f(scaleSize, scaleSize));
		break;
	case 2:
		this->menu->setScale(sf::Vector2f(scaleSize, scaleSize));
		break;
	}

	window->draw(*this->titleTop);
	window->draw(*this->titleBottom);

	window->draw(*this->video);
	window->draw(*this->audio);
	window->draw(*this->menu);
}

void main_options::Destroy(sf::RenderWindow* window)
{
}
