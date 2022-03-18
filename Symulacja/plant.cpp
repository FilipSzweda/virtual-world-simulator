#include "plant.h"
#include "world.h"

Plant::Plant(World* world, Point position, char symbol, int strength)
	: Organism(world, position, symbol, strength, PLANT_INITIATIVE) {
}

void Plant::Action() {
	int zasiew = rand() % (int)(1 / this->GetWorld()->GetSowingProbability());
	if (zasiew == 0) {
		std::vector <Point> positionsForPlant;
		for (int i = 0; i < this->FindNeighboringPositions().size(); i++) {
			if (this->GetWorld()->GetMap()[this->CalculateMapIndex(this->FindNeighboringPositions()[i])] == nullptr) {
				positionsForPlant.push_back(this->FindNeighboringPositions()[i]);
			}
		}
		if (positionsForPlant.size() > 0) {
			int randomizedPositionIndex = rand() % positionsForPlant.size();
			this->GetWorld()->AddOrganism(this->CreateCopy(positionsForPlant[randomizedPositionIndex]));
		}
	}
}

void Plant::Collision(Organism* collidingOrganism, Point previousPosition) {
	this->RemoveOrganismFromMap(previousPosition);
	this->SetAlive(false);
}

Plant::~Plant() {
}