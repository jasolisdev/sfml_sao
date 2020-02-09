#pragma once

#include "game_state.h"

class main_menu : public tiny_state
{
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	sf::Text* titleTop;
	sf::Text* titleBottom;

	sf::Text* play;
	sf::Text* options;
	sf::Text* quit;

	float grow, scaleSize;

	int selected;

	bool upKey, downKey;
};
