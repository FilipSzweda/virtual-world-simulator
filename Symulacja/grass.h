#pragma once
#include "plant.h"

#define GRASS_STRENGTH 0
#define GRASS_SYMBOL '#'

class Grass : public Plant {
public:
	Grass(World* world, Point& position);

	void Draw() override;
	Organism* CreateCopy(Point position) override;

	~Grass();
};