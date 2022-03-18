#include "sheep.h"

Sheep::Sheep(World* world, Point& position)
	: Animal(world, position, SHEEP_SYMBOL, SHEEP_STRENGTH, SHEEP_INITIATIVE) {
	printf("New Sheep in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
}

Sheep::Sheep(World* world, Point& position, int strength)
	: Animal(world, position, SHEEP_SYMBOL, strength, SHEEP_INITIATIVE) {
	printf("New Sheep in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
}

void Sheep::Draw() {
	printf("%c ", this->GetSymbol());
}

Organism* Sheep::CreateCopy(Point position) {
	Organism* child = new Sheep(this->GetWorld(), position);
	return child;
}

Sheep::~Sheep() {
	printf("Sheep death in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
}