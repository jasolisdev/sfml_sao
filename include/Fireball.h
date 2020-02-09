#pragma once

#include "Entity.h"

extern int bullets;

class Fireball : public Entity
{
public:
	Fireball(float x, float y);
	void Update();
private:
	float direction = 0;
};
