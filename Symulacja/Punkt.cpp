#include "Punkt.h"

Punkt::Punkt(int x, int y)
	: x(x), y(y) {
}

int Punkt::GetX() const {
	return x;
}

int Punkt::GetY() const {
	return y;
}

void Punkt::SetX(int x) {
	this->x = x;
}

void Punkt::SetY(int y) {
	this->y = y;
}

bool Punkt::operator==(const Punkt other) {
	if (this->GetX() == other.GetX() && this->GetY() == other.GetY()) {
		return true;
	}
	else {
		return false;
	}
}

Punkt::~Punkt() {
}