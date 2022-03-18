#pragma once
#include "organism.h"
#include "world.h"

#define PLANT_INITIATIVE 0

class Plant : public Organism {
public:
	Plant(World* world, Point position, char symbol, int strength);

	void Action() override;
	void Collision(Organism* collidingOrganism, Point previousPosition) override;

	virtual ~Plant();
};