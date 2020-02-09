#include "../include/Enemy.h"
#include "../include/main_game.h"

Enemy::Enemy()
{
	enemyCount += 1;
	this->group_id = 3;
	this->Load("../data/images/salamander.png", sf::IntRect(32, 32, 32, 32));
	this->setPosition(sf::Vector2f(rand() % 400 + 940, rand() % 600));
}

void Enemy::Update()
{
	if (this->active)
	{
		this->move(sf::Vector2f(-0.75f, 0));

		if (this->getGlobalBounds().left + this->getGlobalBounds().width < 0)
		{
			enemyCount -= 1;
			this->active = 0;
		}
	}
}
