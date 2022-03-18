#pragma once
#include "plant.h"

#define DEADLY_NIGHTSHADE_STRENGTH 99
#define DEADLY_NIGHTSHADE_SYMBOL '+'

class DeadlyNightshade : public Plant {
public:
	DeadlyNightshade(World* world, Point& position);

	void Draw() override;
	bool IsPoisonous() override;
	Organism* CreateCopy(Point position) override;

	~DeadlyNightshade();
};