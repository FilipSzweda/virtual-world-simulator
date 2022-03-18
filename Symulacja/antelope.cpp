#include "antelope.h"

Antelope::Antelope(World* world, Point& position)
	: Animal(world, position, ANTELOPE_SYMBOL, ANTELOPE_STRENGTH, ANTELOPE_INITIATIVE) {
	printf("New Antelope in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
}

Antelope::Antelope(World* world, Point& position, int strength)
	: Animal(world, position, ANTELOPE_SYMBOL, strength, ANTELOPE_INITIATIVE) {
	printf("New Antelope in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
}

void Antelope::Action() {
	std::vector <Point> directions, positions;
	Point up(this->GetPosition().GetX(), this->GetPosition().GetY() - 2), right(this->GetPosition().GetX() + 2, this->GetPosition().GetY()), down(this->GetPosition().GetX(), this->GetPosition().GetY() + 2), left(this->GetPosition().GetX() - 2, this->GetPosition().GetY());
	directions.push_back(up);
	directions.push_back(right);
	directions.push_back(down);
	directions.push_back(left);
	for (int i = 0; i < directions.size(); i++) {
		if (directions[i].GetX() < this->GetWorld()->GetWidth() && directions[i].GetY() < this->GetWorld()->GetHeight() && directions[i].GetX() >= 0 && directions[i].GetY() >= 0) {
			positions.push_back(directions[i]);
		}
	}
	if (positions.size() > 0) {
		int randomizedPositionIndex = rand() % positions.size();
		this->SetPosition(positions[randomizedPositionIndex]);
	}
	else {
		this->Animal::Action();
	}
}

void Antelope::Draw() {
	printf("%c ", this->GetSymbol());
}

bool Antelope::EscapedFight() {
	int escapeChance = rand() % 2;
	if (escapeChance == 0) {
		for (int i = 0; i < this->FindNeighboringPositions().size(); i++) {
			int index = this->FindNeighboringPositions()[i].GetX() + this->GetWorld()->GetWidth() * this->FindNeighboringPositions()[i].GetY();
			if (this->GetWorld()->GetMap()[index] == nullptr) {
				return true;
			}
		}
		return false;
	}
	else {
		return false;
	}
}

Organism* Antelope::CreateCopy(Point position) {
	Organism* dziecko = new Antelope(this->GetWorld(), position);
	return dziecko;
}

Antelope::~Antelope() {
	printf("Antelope death in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
}