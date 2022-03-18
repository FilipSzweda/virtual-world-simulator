#pragma once
#include "plant.h"

#define GUARANA_STRENGTH 0
#define GUARANA_SYMBOL '$'

class Guarana : public Plant {
public:
	Guarana(World* world, Point& position);

	void Draw() override;
	bool GivesStrengthBonus() override;
	Organism* CreateCopy(Point position) override;

	~Guarana();
};