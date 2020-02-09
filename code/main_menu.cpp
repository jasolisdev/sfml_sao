#include <stdio.h>
#include "../include/main_menu.h"
#include "../include/main_game.h"
#include "../include/main_options.h"

void main_menu::Initialize(sf::RenderWindow* window)
{
	sf::Font* font = new sf::Font();
	font->loadFromFile("../data/fonts/sao.ttf");

	this->titleTop = new sf::Text("Sword Art Online", *font, 100U);
	this->titleBottom = new sf::Text("Attack on Salamander", *font, 50U);

	this->titleTop->setPosition(sf::Vector2f(window->getSize().y / 5, this->titleTop->getCharacterSize() * 0.1f));

	this->titleBottom->setOrigin(sf::Vector2f(this->titleBottom->getCharacterSize() / 2, this->titleBottom->getCharacterSize() / 2));
	this->titleBottom->setPosition(sf::Vector2f(window->getSize().y / 2, this->titleTop->getCharacterSize() * 1.5f));

	this->play = new sf::Text("New Game", *font, 70U);
	this->options = new sf::Text("Settings N/A", *font, 70U);
	this->quit = new sf::Text("Exit Game", *font, 70U);

	this->play->setPosition(sf::Vector2f(window->getSize().y / 10 + this->play->getGlobalBounds().width / 2, this->titleTop->getCharacterSize() * 3.5f));
	this->options->setPosition(sf::Vector2f(window->getSize().y / 10 + this->options->getGlobalBounds().width / 2, this->titleTop->getCharacterSize() * 4.0f));
	this->quit->setPosition(sf::Vector2f(window->getSize().y / 10 + this->quit->getGlobalBounds().width / 2, this->titleTop->getCharacterSize() * 4.5f));
	//this->quit->setPosition(sf::Vector2f(window->getSize().y / 10 + this->quit->getGlobalBounds().width / 2, this->titleTop->getCharacterSize() * 3.5f + this->quit->getCharacterSize() * 1.0f));

	//this->play->setOrigin(sf::Vector2f(this->titleBottom->getCharacterSize() / 2, this->titleBottom->getCharacterSize() / 2));
	//this->options->setOrigin(sf::Vector2f(this->titleBottom->getCharacterSize() / 4, this->titleBottom->getCharacterSize() / 4));
	//this->quit->setOrigin(sf::Vector2f(this->titleBottom->getCharacterSize() / 4, this->titleBottom->getCharacterSize() / 4));

	this->grow = 0.0025f;
	this->scaleSize = 1.0f;

	this->selected = 0;
}
void main_menu::Update(sf::RenderWindow* window)
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
			coreState->SetState(new main_game());
			break;
		case 1:
			//coreState->SetState(new main_options());
			break;
		case 2:
			exitGame = true;
			break;
		}
	}

	this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
}

void main_menu::Render(sf::RenderWindow* window)
{
	this->play->setScale(sf::Vector2f(1, 1));
	this->options->setScale(sf::Vector2f(1, 1));
	this->quit->setScale(sf::Vector2f(1, 1));

	switch (this->selected)
	{
	case 0:
		this->play->setScale(sf::Vector2f(scaleSize, scaleSize));
		break;
	case 1: 
		this->options->setScale(sf::Vector2f(scaleSize, scaleSize));
		break;
	case 2:
		this->quit->setScale(sf::Vector2f(scaleSize, scaleSize));
		break;
	}

	window->draw(*this->titleTop);
	window->draw(*this->titleBottom);

	window->draw(*this->play);
	window->draw(*this->options);
	window->draw(*this->quit);
}

void main_menu::Destroy(sf::RenderWindow* window)
{
}
