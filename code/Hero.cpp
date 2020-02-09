#include "../include/Hero.h"
#include "../include/game_state.h"
#include "../include/Fireball.h"
#include "../include/Fireball.h"

#define AMMO_COUNT 10

int bullets = 0;

Hero::Hero()
{
	this->group_id = 1;
	this->Load("../data/images/kirito.png", sf::IntRect(32, 0, 32, 32));
	this->setPosition(400, 300);
}

void Hero::Update()
{
	this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
	this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S);
	this->leftKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A);
	this->rightKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);

	if (this->upKey)
	{
		this->move(sf::Vector2f(0, -1));
		this->Load("../data/images/kirito.png", sf::IntRect(32, 96, 32, 32));
	}
	if (this->downKey)
	{
		this->move(sf::Vector2f(0, 1));
		this->Load("../data/images/kirito.png", sf::IntRect(32, 0, 32, 32));
	}
	if (this->leftKey)
	{
		this->move(sf::Vector2f(-1, 0));
		this->Load("../data/images/kirito.png", sf::IntRect(32, 32, 32, 32));
	}
	if (this->rightKey)
	{
		this->move(sf::Vector2f(1, 0));
		this->Load("../data/images/kirito.png", sf::IntRect(32, 64, 32, 32));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !this->spaceKey && bullets < AMMO_COUNT)
	{
		coreState->state->manager.AddEntity("fireball", new Fireball(this->getPosition().x, this->getPosition().y));
		bullets += 1;
	}
	this->spaceKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
}
