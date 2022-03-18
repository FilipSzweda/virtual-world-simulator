#pragma once
#include "animal.h"

#define WOLF_STRENGTH 9
#define WOLF_INITIATIVE 5
#define WOLF_SYMBOL 'W'

class Wolf : public Animal {
public:
	Wolf(World* world, Point& position);
	Wolf(World* world, Point& position, int strength);

	void Draw() override;
	Organism* CreateCopy(Point position) override;

	~Wolf();
};