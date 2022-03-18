#pragma once
#include "organism.h"
#include "world.h"

class Animal : public Organism {
public:
	Animal(World* world, Point position, char symbol, int strength, int initiative);

	bool IsAnimal() override;
	void Action() override;
	void Collision(Organism* collidingOrganism, Point previousPosition) override;

	virtual ~Animal();
};
