#include "world.h"

World::World(int width, int height, double sowingProbability)
	: width(width), height(height), sowingProbability(sowingProbability) {
	for (int i = 0; i < this->width * this->height; i++) {
		this->map[i] = nullptr;
	}
	this->turn = 0;
	this->input = 0;
	this->humanAlive = false;
	this->abilityUseTurn = -1;
	srand(time(NULL) + rand());
}

int World::GetInput() const {
	return this->input;
}

int World::GetTurn() const {
	return this->turn;
}

int World::GetAbilityUseTurn() const {
	return this->abilityUseTurn;
}

int World::GetWidth() const {
	return this->width;
}

int World::GetHeight() const {
	return this->height;
}

bool World::GetHumanAlive() const {
	return this->humanAlive;
}

Organism** World::GetMap() const {
	return map;
}

std::vector <Organism*> World::GetOrganisms() const {
	return this->organisms;
}

std::vector <Organism*> World::GetActiveOrganisms() const {
	return this->activeOrganisms;
}

double World::GetSowingProbability() const {
	return this->sowingProbability;
}

void World::SetSowingProbability(double sowingProbability) {
	this->sowingProbability = sowingProbability;
}

void World::SetTurn(int turn) {
	this->turn = turn;
}

void World::SetAbilityUseTurn(int abilityUseTurn) {
	this->abilityUseTurn = abilityUseTurn;
}

void World::SetHumanAlive(bool humanAlive) {
	this->humanAlive = humanAlive;
}

void World::UpdateActiveOrganisms() {
	this->activeOrganisms.clear();
	for (int i = 0; i < this->organisms.size(); i++) {
		this->activeOrganisms.push_back(this->organisms[i]);
	}
}

void World::AddOrganism(Organism* newOrganism) {
	bool organismAdded = false;
	for (int i = 0; i < this->organisms.size(); i++) {
		if (newOrganism->GetInitiative() > this->organisms[i]->GetInitiative()) {
			this->organisms.insert(this->organisms.begin() + i, newOrganism);
			organismAdded = true;
			break;
		}
	}
	if (organismAdded == false) {
		this->organisms.push_back(newOrganism);
	}
}

void World::RemoveOrganism(Organism* removedOrganism) {
	this->organisms.erase(std::find(this->organisms.begin(), this->organisms.end() - 1, removedOrganism));
	delete(removedOrganism);
}

void World::DrawWorld() {
	this->DrawSimulationWindow();
	this->DrawInterface();
}

void World::DrawSimulationWindow() {
	printf("%c", (char)201);
	for (int i = 0; i < 2 * this->width; i++) {
		printf("%c", (char)205);
	}
	printf("%c", (char)187);
	printf("\n");
	for (int i = 0; i < this->width * this->height; i++) {
		if (i % this->width == 0) {
			printf("%c", (char)186);
		}
		if (this->map[i] != nullptr) {
			map[i]->Draw();
		}
		else {
			printf("  ");
		}
		if ((i + 1) % this->width == 0) {
			printf("%c\n", (char)186);
		}
	}
	printf("%c", (char)200);
	for (int i = 0; i < 2 * this->width; i++) {
		printf("%c", (char)205);
	}
	printf("%c", (char)188);
	printf("\n");
}

void World::DrawInterface() {
	printf("Keyboard arrows - movement\n");
	printf("Space - Azlurs Shield ability\n");
	printf("Enter - skip turn\n");
	printf("Escape - save simulation\n");
	printf("Turn: %i\n", this->GetTurn());
	if (this->GetAbilityUseTurn() > 0 && 6 - (this->GetTurn() - this->GetAbilityUseTurn()) > 0) {
		printf("Ability turn: %i\n", 6 - (this->GetTurn() - this->GetAbilityUseTurn()));
	}
	else {
		printf("Left ability turns: 0\n");
	}
}

void World::TakeTurn() {
	this->UpdateActiveOrganisms();
	for (int i = 0; i < this->activeOrganisms.size(); i++) {
		if (this->activeOrganisms[i]->GetAlive() == true && this->GetMap()[this->activeOrganisms[i]->CalculateMapIndex(this->activeOrganisms[i]->GetPosition())] != nullptr) {
			Point previousPosition = this->activeOrganisms[i]->GetPosition();
			this->activeOrganisms[i]->Action();
			if (this->activeOrganisms[i]->IsAnimal() == true) {
				bool collisionHappened = false;
				for (int j = 0; j < this->organisms.size(); j++) {
					if (organisms[j]->GetAlive() == true && activeOrganisms[i] != organisms[j] && this->activeOrganisms[i]->CheckForCollision(this->organisms[j])) {
						this->activeOrganisms[i]->Collision(this->organisms[j], previousPosition);
						collisionHappened = true;
						break;
					}
				}
				if (!collisionHappened) {
					this->activeOrganisms[i]->RemoveOrganismFromMap(previousPosition);
					this->activeOrganisms[i]->AddOrganismToMap(this->activeOrganisms[i]->GetPosition());
				}
			}
		}
	}
	for (int i = 0; i < organisms.size(); i++) {
		if (this->organisms[i]->GetAlive() == false) {
			this->RemoveOrganism(this->organisms[i]);
		}
	}
	this->turn++;
}

void World::TakeInput() {
	bool waitingForInput = true;
	while (waitingForInput) {
		switch ((this->input = _getch())) {
		case ARROW_UP:
			waitingForInput = false;
			break;
		case ARROW_RIGHT:
			waitingForInput = false;
			break;
		case ARROW_DOWN:
			waitingForInput = false;
			break;
		case ARROW_LEFT:
			waitingForInput = false;
			break;
		case SPACE:
			if ((this->GetAbilityUseTurn() < 0 || this->GetTurn() - this->GetAbilityUseTurn() > 10) && this->humanAlive == true) {
				this->SetAbilityUseTurn(this->GetTurn());
				printf("Activated Alzurs Shield Ability!\n");
			}
			else {
				printf("You can't activate Alzurs Shield Ability!\n");
			}
			break;
		case ENTER:
			waitingForInput = false;
			break;
		case ESCAPE:
			this->SaveSimulation();
			printf("Simulation has been saved!\n");
			break;
		}
	}
}

void World::SaveSimulation() {
	std::ofstream out;
	out.open("save.txt");
	out << this->width << " " << this->height << " " << this->sowingProbability << " " << this->turn << " " << this->abilityUseTurn << "\n";
	for (int i = 0; i < organisms.size(); i++) {
		out << organisms[i]->GetSymbol() << " " << organisms[i]->GetPosition().GetX() << " " << organisms[i]->GetPosition().GetY() << " " << organisms[i]->GetStrength() << "\n";
	}
	out.close();
}

World::~World(){
	for (int i = 0; i < this->organisms.size(); i++) {
		delete(this->organisms[i]);
	}
	for (int i = 0; i < this->activeOrganisms.size(); i++) {
		delete(this->activeOrganisms[i]);
	}
	organisms.clear();
	activeOrganisms.clear();
}