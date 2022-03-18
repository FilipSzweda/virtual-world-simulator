#include "dandelion.h"

Dandelion::Dandelion(World* world, Point& position)
	: Plant(world, position, DANDELION_SYMBOL, DANDELION_STRENGTH) {
	printf("New Dandelion in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
}

void Dandelion::Action() {
	bool positionForPlantFound = false;
	for (int i = 0; i < DANDELION_SOWING_TRIES; i++) {
		int sowing = rand() % (int)(1 / this->GetWorld()->GetSowingProbability());
		if (sowing == 0) {
			std::vector <Point> positionsForPlant;
			for (int i = 0; i < this->FindNeighboringPositions().size(); i++) {
				if (this->GetWorld()->GetMap()[this->CalculateMapIndex(this->FindNeighboringPositions()[i])] == nullptr) {
					positionsForPlant.push_back(this->FindNeighboringPositions()[i]);
					positionForPlantFound = true;
				}
			}
			if (positionsForPlant.size() > 0) {
				int randomizedPositionIndex = rand() % positionsForPlant.size();
				this->GetWorld()->AddOrganism(this->CreateCopy(positionsForPlant[randomizedPositionIndex]));
			}
		}
		if (positionForPlantFound == true) {
			break;
		}
	}
}

void Dandelion::Draw() {
	printf("\033[93m%c\033[0m ", this->GetSymbol());
}

Organism* Dandelion::CreateCopy(Point position) {
	Organism* child = new Dandelion(this->GetWorld(), position);
	return child;
}

Dandelion::~Dandelion() {
	printf("Dandelion eaten in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
}