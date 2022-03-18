#include "guarana.h"

Guarana::Guarana(World* world, Point& position)
	: Plant(world, position, GUARANA_SYMBOL, GUARANA_STRENGTH) {
	printf("New Guarana in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
}

void Guarana::Draw() {
	printf("\033[94m%c\033[0m ", this->GetSymbol());
}

bool Guarana::GivesStrengthBonus() {
	return true;
}

Organism* Guarana::CreateCopy(Point position) {
	Organism* child = new Guarana(this->GetWorld(), position);
	return child;
}

Guarana::~Guarana() {
	printf("Guarana eaten in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
}