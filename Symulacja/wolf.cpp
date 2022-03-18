#include "wolf.h"

Wolf::Wolf(World* world, Point& position)
	: Animal(world, position, WOLF_SYMBOL, WOLF_STRENGTH, WOLF_INITIATIVE) {
	printf("New Wolf in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
}

Wolf::Wolf(World* world, Point& position, int strength)
	: Animal(world, position, WOLF_SYMBOL, strength, WOLF_INITIATIVE) {
	printf("New Wolf in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
}

void Wolf::Draw() {
	printf("%c ", this->GetSymbol());
}

Organism* Wolf::CreateCopy(Point position) {
	Organism* child = new Wolf(this->GetWorld(), position);
	return child;
}

Wolf::~Wolf() {
	printf("Wolf death in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
}