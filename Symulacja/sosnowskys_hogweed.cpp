#include "sosnowskys_hogweed.h"

SosnowskysHogweed::SosnowskysHogweed(World* world, Point& position)
	: Plant(world, position, SOSNOWSKYS_HOGWEED_SYMBOL, SOSNOWSKYS_HOGWEED_STRENGTH) {
	printf("New Sosnowskys Hogweed in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
}

void SosnowskysHogweed::Action() {
	std::vector <Organism*> poisonedAnimals;
	for (int i = 0; i < this->FindNeighboringPositions().size(); i++) {
		if (this->GetWorld()->GetMap()[this->CalculateMapIndex(this->FindNeighboringPositions()[i])] != nullptr) {
			if (this->GetWorld()->GetMap()[this->CalculateMapIndex(this->FindNeighboringPositions()[i])]->IsAnimal() == true) {
				poisonedAnimals.push_back(this->GetWorld()->GetMap()[this->CalculateMapIndex(this->FindNeighboringPositions()[i])]);
			}
		}
	}
	for (int i = 0; i < poisonedAnimals.size(); i++) {
		poisonedAnimals[i]->RemoveOrganismFromMap(poisonedAnimals[i]->GetPosition());
		poisonedAnimals[i]->SetAlive(false);	
	}
	this->Plant::Action();
}

void SosnowskysHogweed::Draw() {
	printf("\033[31m%c\033[0m ", this->GetSymbol());
}

bool SosnowskysHogweed::IsPoisonous() {
	return true;
}

Organism* SosnowskysHogweed::CreateCopy(Point position) {
	Organism* child = new SosnowskysHogweed(this->GetWorld(), position);
	return child;
}

SosnowskysHogweed::~SosnowskysHogweed() {
	printf("Sosnowskys Hogweed eaten in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
}