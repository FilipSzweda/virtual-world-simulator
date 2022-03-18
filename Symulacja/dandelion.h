#pragma once
#include "plant.h"

#define DANDELION_STRENGTH 0
#define DANDELION_SYMBOL '*'
#define DANDELION_SOWING_TRIES 3

class Dandelion : public Plant {
public:
	Dandelion(World* world, Point& position);

	void Action() override;
	void Draw() override;
	Organism* CreateCopy(Point position) override;

	~Dandelion();
};