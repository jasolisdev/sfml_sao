#include "../include/Fireball.h"

Fireball::Fireball(float x, float y)
{
	this->group_id = 2;
	this->Load("../data/images/fireball.png", sf::IntRect());
	this->setPosition(sf::Vector2f(x, y));
	this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
	//this->rotate(rand() % 360);
	//this->direction = rand() % 2;
	//this->setColor(sf::Color::Color(rand() % 255, rand() % 255, rand() % 255));
}

void Fireball::Update()
{
	if (this->active)
	{
		this->move(sf::Vector2f(2.0f, 0));
		//this->rotate((direction == 0) ? 1 : -1);

		if (this->getGlobalBounds().left > 800)
		{
			this->active = 0;
			bullets -= 1;
		}
	}
}
