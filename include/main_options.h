#pragma once

#include "game_state.h"

class main_options : public tiny_state
{
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	sf::Text* titleTop;
	sf::Text* titleBottom;

	sf::Text* video;
	sf::Text* audio;
	sf::Text* resolution;
	sf::Text* menu;

	float grow, scaleSize;

	int selected;

	bool upKey, downKey;
};
