#include "deadly_nightshade.h"

DeadlyNightshade::DeadlyNightshade(World* world, Point& position)
	: Plant(world, position, DEADLY_NIGHTSHADE_SYMBOL, DEADLY_NIGHTSHADE_STRENGTH) {
	printf("New Deadly Nightshade in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
}

void DeadlyNightshade::Draw() {
	printf("\033[91m%c\033[0m ", this->GetSymbol());
}

bool DeadlyNightshade::IsPoisonous() {
	return true;
}

Organism* DeadlyNightshade::CreateCopy(Point position) {
	Organism* child = new DeadlyNightshade(this->GetWorld(), position);
	return child;
}

DeadlyNightshade::~DeadlyNightshade() {
	printf("Deadly Nightshade eaten in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
}