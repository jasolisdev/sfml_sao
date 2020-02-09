#include "../include/game_over.h"
#include "../include/main_menu.h"

void game_over::Initialize(sf::RenderWindow* window)
{
	enterKey = false;
	sf::Font* font = new sf::Font();
	font->loadFromFile("../data/fonts/sao.ttf");

	this->gameOverText = new sf::Text("You are dead", *font, 100U);
	this->gameOverText->setFillColor(sf::Color::Red);
	this->gameOverText->setOrigin(sf::Vector2f(this->gameOverText->getGlobalBounds().width / 2, this->gameOverText->getGlobalBounds().height / 2));
	this->gameOverText->setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2));
}
void game_over::Update(sf::RenderWindow* window)
{
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && enterKey)
	{
		coreState->SetState(new main_menu());
	}
	enterKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return);
}
void game_over::Render(sf::RenderWindow* window)
{
	window->draw(*this->gameOverText);
}
void game_over::Destroy(sf::RenderWindow* window)
{
}
