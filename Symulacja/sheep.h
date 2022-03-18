#pragma once
#include "animal.h"

#define SHEEP_STRENGTH 4
#define SHEEP_INITIATIVE 4
#define SHEEP_SYMBOL 'S'

class Sheep : public Animal {
public:
	Sheep(World* world, Point& position);
	Sheep(World* world, Point& position, int strength);

	void Draw() override;
	Organism* CreateCopy(Point position) override;

	~Sheep();
};