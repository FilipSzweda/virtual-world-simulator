#pragma once
#include "animal.h"

#define ANTELOPE_STRENGTH 4
#define ANTELOPE_INITIATIVE 4
#define ANTELOPE_SYMBOL 'A'

class Antelope : public Animal {
public:
	Antelope(World* world, Point& position);
	Antelope(World* world, Point& position, int strength);

	void Action() override;
	void Draw() override;
	bool EscapedFight() override;
	Organism* CreateCopy(Point position) override;

	~Antelope();
};