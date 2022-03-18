#include "animal.h"

Animal::Animal(World* world, Point position, char symbol, int strength, int initiative)
	: Organism(world, position, symbol, strength, initiative) {
}

bool Animal::IsAnimal() {
	return true;
}

void Animal::Action() {
	if (this->FindNeighboringPositions().size() > 0) {
		int randomizedPositionIndex = rand() % this->FindNeighboringPositions().size();
		this->SetPosition(this->FindNeighboringPositions()[randomizedPositionIndex]);
	}
}

void Animal::Collision(Organism* collidingOrganism, Point previousPosition) {
	if (this->GetSymbol() == collidingOrganism->GetSymbol()) {
		this->Breeding(collidingOrganism, previousPosition);
	}
	else {
		this->Fight(collidingOrganism, previousPosition);
	}
}

Animal::~Animal() {
}