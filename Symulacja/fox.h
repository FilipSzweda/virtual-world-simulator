#pragma once
#include "animal.h"

#define FOX_STRENGTH 3
#define FOX_INITIATIVE 7
#define FOX_SYMBOL 'F'

class Fox : public Animal {
public:
	Fox(World* world, Point& position);
	Fox(World* world, Point& position, int strength);

	void Action() override;
	void Draw() override;
	Organism* CreateCopy(Point position) override;

	~Fox();
};