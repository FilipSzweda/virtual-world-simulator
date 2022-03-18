#include "human.h"

Human::Human(World* world, Point& position)
	: Animal(world, position, HUMAN_SYMBOL, HUMAN_STRENGTH, HUMAN_INITIATIVE) {
    printf("New Human in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
    this->GetWorld()->SetHumanAlive(true);
}

Human::Human(World* world, Point& position, int strength)
    : Animal(world, position, HUMAN_SYMBOL, strength, HUMAN_INITIATIVE) {
    printf("New Human in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
    this->GetWorld()->SetHumanAlive(true);
}

void Human::Action() {
    switch (this->GetWorld()->GetInput()) {
    case ARROW_UP:
        if (this->GetPosition().GetY() - 1 >= 0) {
            this->SetPositionY(this->GetPosition().GetY() - 1);
        }
        break;
    case ARROW_RIGHT:
        if (this->GetPosition().GetX() + 1 < this->GetWorld()->GetWidth()) {
            this->SetPositionX(this->GetPosition().GetX() + 1);
        }
        break;
    case ARROW_DOWN:
        if (this->GetPosition().GetY() + 1 < this->GetWorld()->GetHeight()) {
            this->SetPositionY(this->GetPosition().GetY() + 1);
        }
        break;
    case ARROW_LEFT:
        if (this->GetPosition().GetX() - 1 >= 0) {
            this->SetPositionX(this->GetPosition().GetX() - 1);
        }
        break;
    case SPACE:
        if (this->GetWorld()->GetAbilityUseTurn() < 0 || this->GetWorld()->GetTurn() - this->GetWorld()->GetAbilityUseTurn() > 10) {
            this->GetWorld()->SetAbilityUseTurn(this->GetWorld()->GetTurn());
            printf("Activated ability Alzurs Shield!\n");
        }
        else {
            printf("You can't activate ability Alzurs Shield!\n");
        }     
        break;
    case ENTER:
        break;
    }
}

bool Human::ActivatedAlzursShield() {
    if (this->GetWorld()->GetTurn() - this->GetWorld()->GetAbilityUseTurn() <= 5 && this->GetWorld()->GetAbilityUseTurn() >= 0) {
        return true;
    }
    else {
        return false;
    }
}

void Human::Draw() {
	printf("%c ", this->GetSymbol());
}

Organism* Human::CreateCopy(Point position) {
    Organism* child = new Human(this->GetWorld(), position);
    return child;
}

Human::~Human() {
    printf("Human death in position (%i, %i)\n", this->GetPosition().GetX(), this->GetPosition().GetY());
    this->GetWorld()->SetHumanAlive(false);
}