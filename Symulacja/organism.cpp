#include "organism.h"
#include "world.h"
#include "animal.h"

Organism::Organism(World* world, Point position, char symbol, int strength, int initiative)
	: world(world), position(position), symbol(symbol), strength(strength), initiative(initiative) {
	this->AddOrganismToMap(this->GetPosition());
	this->alive = true;
}

bool Organism::DeflectedAttack(Organism* attackingOrganism) {
	return false;
}

bool Organism::EscapedFight() {
	return false;
}

bool Organism::GivesStrengthBonus() {
	return false;
}

bool Organism::IsPoisonous() {
	return false;
}

bool Organism::IsAnimal() {
	return false;
}

bool Organism::ActivatedAlzursShield() {
	return false;
}

void Organism::AddOrganismToMap(Point position) {
	this->GetWorld()->GetMap()[this->CalculateMapIndex(position)] = this;
}

void Organism::RemoveOrganismFromMap(Point position) {
	this->GetWorld()->GetMap()[this->CalculateMapIndex(position)] = nullptr;
}

bool Organism::CheckForCollision(Organism* organism) {
	return this->GetPosition() == organism->GetPosition();
}

void Organism::Breeding(Organism* collidingOrganism, Point previousPosition) {
	this->SetPosition(previousPosition);
	std::vector <Point> positionsForChild;
	for (int i = 0; i < collidingOrganism->FindNeighboringPositions().size(); i++) {
		if (collidingOrganism->GetWorld()->GetMap()[collidingOrganism->CalculateMapIndex(collidingOrganism->FindNeighboringPositions()[i])] == nullptr) {
			positionsForChild.push_back(collidingOrganism->FindNeighboringPositions()[i]);
		}
	}
	if (positionsForChild.size() > 0) {
		int randomizedPositionIndex = rand() % positionsForChild.size();
		collidingOrganism->GetWorld()->AddOrganism(collidingOrganism->CreateCopy(positionsForChild[randomizedPositionIndex]));
	}
}

void Organism::Fight(Organism* collidingOrganism, Point previousPosition) {
	if (collidingOrganism->IsPoisonous() == true) {
		this->RemoveOrganismFromMap(previousPosition);
		this->RemoveOrganismFromMap(this->GetPosition());
		collidingOrganism->SetAlive(false);
		this->SetAlive(false);
	}
	else {
		if (collidingOrganism->ActivatedAlzursShield() == true) {
			this->AlzursShield(previousPosition);
		}
		else {
			if (this->GetStrength() >= collidingOrganism->GetStrength()) {
				if (collidingOrganism->DeflectedAttack(this) == true) {
					this->Deflection(previousPosition);
				}
				else {
					this->RemoveOrganismFromMap(previousPosition);
					this->AddOrganismToMap(this->GetPosition());
					if (collidingOrganism->EscapedFight() == true) {
						collidingOrganism->Escape(this);
					}
					else {
						if (collidingOrganism->GivesStrengthBonus() == true) {
							this->SetStrength(this->GetStrength() + 3);
						}
						collidingOrganism->SetAlive(false);
					}
				}
			}
			else {
				if (this->EscapedFight() == true) {
					this->RemoveOrganismFromMap(previousPosition);
					this->Escape(collidingOrganism);
				}
				else {
					this->RemoveOrganismFromMap(previousPosition);
					this->SetAlive(false);
				}
			}
		}
	}
}

void Organism::Deflection(Point previousPosition) {
	this->SetPosition(previousPosition);
}

void Organism::AlzursShield(Point previousPosition) {
	Point positionOnAlzursShield = this->GetPosition();
	if (this->FindNeighboringPositions().size() > 0) {
		int randomizedPositionIndex = rand() % this->FindNeighboringPositions().size();
		this->SetPosition(this->FindNeighboringPositions()[randomizedPositionIndex]);
	}
	if (this->GetPosition() == positionOnAlzursShield) {
		this->RemoveOrganismFromMap(previousPosition);
		this->SetAlive(false);
	}
	else {
		bool collisionHappened = false;
		for (int i = 0; i < this->GetWorld()->GetOrganisms().size(); i++) {
			if (this != this->GetWorld()->GetOrganisms()[i] && this->CheckForCollision(this->GetWorld()->GetOrganisms()[i])) {
				this->Collision(this->GetWorld()->GetOrganisms()[i], previousPosition);
				collisionHappened = true;
				break;
			}
		}
		if (!collisionHappened) {
			this->RemoveOrganismFromMap(previousPosition);
			this->AddOrganismToMap(this->GetPosition());
		}
	}
}

void Organism::Escape(Organism* organizmAtakujacy) {
	std::vector <Point> positionsForEscape;
	for (int i = 0; i < this->FindNeighboringPositions().size(); i++) {
		if (this->GetWorld()->GetMap()[this->CalculateMapIndex(this->FindNeighboringPositions()[i])] == nullptr) {
			positionsForEscape.push_back(this->FindNeighboringPositions()[i]);
		}
	}
	int randomizedPositionIndex = rand() % positionsForEscape.size();
	this->SetPosition(positionsForEscape[randomizedPositionIndex]);
	this->AddOrganismToMap(this->GetPosition());
}

World* Organism::GetWorld() const {
	return this->world;
}

Point Organism::GetPosition() const {
	return this->position;
}

char Organism::GetSymbol() const {
	return this->symbol;
}

int Organism::GetStrength() const {
	return this->strength;
}

int Organism::GetInitiative() const {
	return this->initiative;
}

bool Organism::GetAlive() const {
	return this->alive;
}

void Organism::SetWorld(World* world) {
	this->world = world;
}

void Organism::SetPosition(Point position) {
	this->position.SetX(position.GetX());
	this->position.SetY(position.GetY());
}

void Organism::SetPositionX(int x) {
	this->position.SetX(x);
}

void Organism::SetPositionY(int y) {
	this->position.SetY(y);
}

void Organism::SetSymbol(char symbol) {
	this->symbol = symbol;
}

void Organism::SetStrength(int strength) {
	this->strength = strength;
}

void Organism::SetAlive(bool alive) {
	this->alive = alive;
}

std::vector <Point> Organism::FindNeighboringPositions() {
	std::vector <Point> directions, positions;
	Point up(this->GetPosition().GetX(), this->GetPosition().GetY() - 1), right(this->GetPosition().GetX() + 1, this->GetPosition().GetY()), down(this->GetPosition().GetX(), this->GetPosition().GetY() + 1), left(this->GetPosition().GetX() - 1, this->GetPosition().GetY());
	directions.push_back(up);
	directions.push_back(right);
	directions.push_back(down);
	directions.push_back(left);
	for (int i = 0; i < directions.size(); i++) {
		if (directions[i].GetX() < this->GetWorld()->GetWidth() && directions[i].GetY() < this->GetWorld()->GetHeight() && directions[i].GetX() >= 0 && directions[i].GetY() >= 0) {
			positions.push_back(directions[i]);
		}
	}
	return positions;
}

int Organism::CalculateMapIndex(Point polozenieDoIndexu) {
	int mapIndex = polozenieDoIndexu.GetX() + this->GetWorld()->GetWidth() * polozenieDoIndexu.GetY();
	return mapIndex;
}

Organism::~Organism() {
}