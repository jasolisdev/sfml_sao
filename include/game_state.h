#pragma once

#include <SFML/Graphics.hpp>
#include "EntityManager.h"

class tiny_state
{
public:
	EntityManager manager;
	virtual void Initialize(sf::RenderWindow* Window)
	{
	}
	virtual void Update(sf::RenderWindow* Window)
	{
	}
	virtual void Render(sf::RenderWindow* Window)
	{
	}
	virtual void Destroy(sf::RenderWindow* Window)
	{
	}
private:
};

class game_state
{
public:
	game_state(sf::RenderWindow* Window)
	{
		this->Window = Window;
	}

	void SetState(tiny_state* nextState)
	{
		if (this->state != NULL)
		{
			// this->state->Destroy(this->Window);
		}
		this->state = nextState;
		if (this->state != NULL)
		{
			this->state->Initialize(this->Window);
			
		}
	}

	void Update()
	{
		if (this->state != NULL)
		{
			this->state->Update(this->Window);
			this->state->Render(this->Window);
		}
	}

	~game_state()
	{
		if (this->state != NULL)
		{
			this->state->Destroy(this->Window);
		}
	}
	tiny_state* state;
private:
	sf::RenderWindow* Window;
};

extern game_state* coreState;
extern bool exitGame;
