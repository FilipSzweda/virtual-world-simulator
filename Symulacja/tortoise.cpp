#include "tortoise.h"

Tortoise::Tortoise(World* world, Point& position)
	: Animal(world, position, TORTOISE_SYMBOL, TORTOISE_STRENGTH, TORTOISE_INITIATIVE) {
	printf("New Tortoise in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
}

Tortoise::Tortoise(World* world, Point& position, int strength)
	: Animal(world, position, TORTOISE_SYMBOL, strength, TORTOISE_INITIATIVE) {
	printf("New Tortoise in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
}

void Tortoise::Action() {
	int movementChance = rand() % 4;
	if (movementChance == 0) {
		if (this->FindNeighboringPositions().size() > 0) {
			int randomizedPositionIndex = rand() % this->FindNeighboringPositions().size();
			this->SetPosition(this->FindNeighboringPositions()[randomizedPositionIndex]);
		}
	}
}

void Tortoise::Draw() {
	printf("%c ", this->GetSymbol());
}

bool Tortoise::DeflectedAttack(Organism* attackingOrganism) {
	if (attackingOrganism->GetStrength() < 5) {
		return true;
	}
	else {
		return false;
	}
}

Organism* Tortoise::CreateCopy(Point position) {
	Organism* child = new Tortoise(this->GetWorld(), position);
	return child;
}

Tortoise::~Tortoise() {
	printf("Tortoise death in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
}