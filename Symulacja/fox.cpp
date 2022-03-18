#include "fox.h"

Fox::Fox(World* world, Point& position)
	: Animal(world, position, FOX_SYMBOL, FOX_STRENGTH, FOX_INITIATIVE) {
	printf("New Fox in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
}

Fox::Fox(World* world, Point& position, int strength)
	: Animal(world, position, FOX_SYMBOL, strength, FOX_INITIATIVE) {
	printf("New Fox in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
}

void Fox::Action() {
	std::vector <Point> notStrongerPositions;
	for (int i = 0; i < this->FindNeighboringPositions().size(); i++) {
		if (this->GetWorld()->GetMap()[this->CalculateMapIndex(this->FindNeighboringPositions()[i])] != nullptr) {
			if (this->GetWorld()->GetMap()[this->CalculateMapIndex(this->FindNeighboringPositions()[i])]->GetStrength() <= this->GetStrength()) {
				notStrongerPositions.push_back(this->FindNeighboringPositions()[i]);
			}
		}
		else {
			notStrongerPositions.push_back(this->FindNeighboringPositions()[i]);
		}
	}
	if (notStrongerPositions.size() > 0) {
		int randomizedPositionIndex = rand() % notStrongerPositions.size();
		this->SetPosition(notStrongerPositions[randomizedPositionIndex]);
	}
}


void Fox::Draw() {
	printf("%c ", this->GetSymbol());
}

Organism* Fox::CreateCopy(Point position) {
	Organism* dziecko = new Fox(this->GetWorld(), position);
	return dziecko;
}

Fox::~Fox() {
	printf("Fox death in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
}