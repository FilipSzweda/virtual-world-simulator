#pragma once
#include "animal.h"

#define HUMAN_STRENGTH 5
#define HUMAN_INITIATIVE 4
#define HUMAN_SYMBOL 'H'

#define ARROW_UP 72
#define ARROW_RIGHT 77
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define SPACE 32
#define ENTER 13

class Human : public Animal {
public:
	Human(World* world, Point& position);
	Human(World* world, Point& position, int strength);

	void Action() override;
	bool ActivatedAlzursShield() override;
	void Draw() override;
	Organism* CreateCopy(Point position) override;

	~Human();
};