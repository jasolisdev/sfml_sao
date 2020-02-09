#pragma once

#include "Entity.h"

extern int bullets;

class Hero : public Entity
{
public:
	Hero();
	void Update();
private:
	bool upKey, downKey, leftKey, rightKey, spaceKey;
};
