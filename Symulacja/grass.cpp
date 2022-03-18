#include "grass.h"

Grass::Grass(World* world, Point& position)
	: Plant(world, position, GRASS_SYMBOL, GRASS_STRENGTH) {
	printf("New Grass in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
}

void Grass::Draw() {
	printf("\033[92m%c\033[0m ", this->GetSymbol());
}

Organism* Grass::CreateCopy(Point position) {
	Organism* child = new Grass(this->GetWorld(), position);
	return child;
}

Grass::~Grass() {
	printf("Grass eaten in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
}