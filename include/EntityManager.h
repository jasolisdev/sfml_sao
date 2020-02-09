#pragma once

#include <unordered_map>
#include <vector>
#include "Entity.h"

extern int score;
extern int lives;
extern int enemyCount;
extern int bullets;

class EntityManager
{
public:
	EntityManager()
	{
	}

	void AddEntity(std::string name, Entity* entity)
	{
		std::unordered_map<std::string, Entity*>::const_iterator found = this->entities.find(name);
		while (found != this->entities.end())
		{
			name += "0";
			found = this->entities.find(name);
		}
		this->entities.insert(std::make_pair(name, entity));
	}

	void Update()
	{
		for (auto& iterator : this->entities)
		{
			if (iterator.second->Active())
			{
				if (iterator.second->Group() == 3)
				{
					for (auto& iterator2 : this->entities)
					{
						if (iterator2.second->Active())
						{
							if (iterator2.second->Group() == 2)
							{
								if (iterator.second->collision(iterator2.second))
								{
									toRemove.push_back(iterator.first);
									toRemove.push_back(iterator2.first);
									enemyCount -= 1;
									bullets -= 1;
									score += 1;
								}
							}
							if (iterator2.second->Group() == 1)
							{
								if (iterator.second->collision(iterator2.second))
								{
									Entity* hero = iterator2.second;
									hero->setPosition(400, 300);
									this->Reset();
									this->AddEntity("Hero", hero);
									bullets = 0;
									enemyCount = 0;
									lives -= 1;
									return;
								}
							}
						}
					}
				}
				iterator.second->Update();
			}
			else
			{
				toRemove.push_back(iterator.first);
			}
		}

		while (toRemove.size() > 0)
		{
			this->entities.erase(toRemove[toRemove.size() - 1]);
			toRemove.pop_back();
		}
		toRemove.clear();
	}

	void Reset()
	{
		this->entities.clear();
		this->toRemove.clear();
	}

	void Render(sf::RenderWindow* window)
	{
		for (auto& iterator : this->entities)
		{
			if (iterator.second->Active())
			{
				iterator.second->Render(window);
			}
		}
	}

	~EntityManager()
	{
	}
private:
	std::unordered_map<std::string, Entity*> entities;
	std::vector<std::string> toRemove;
};
