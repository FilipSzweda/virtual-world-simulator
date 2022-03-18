#pragma once
#include "animal.h"

#define TORTOISE_STRENGTH 2
#define TORTOISE_INITIATIVE 1
#define TORTOISE_SYMBOL 'T'

class Tortoise : public Animal {
public:
	Tortoise(World* world, Point& position);
	Tortoise(World* world, Point& position, int strength);

	void Action() override;
	void Draw() override;
	bool DeflectedAttack(Organism* attackingOrganism) override;
	Organism* CreateCopy(Point position) override;

	~Tortoise();
};