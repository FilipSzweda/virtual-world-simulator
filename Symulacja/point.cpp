#include "point.h"

Point::Point(int x, int y)
	: x(x), y(y) {
}

int Point::GetX() const {
	return x;
}

int Point::GetY() const {
	return y;
}

void Point::SetX(int x) {
	this->x = x;
}

void Point::SetY(int y) {
	this->y = y;
}

bool Point::operator==(const Point other) {
	if (this->GetX() == other.GetX() && this->GetY() == other.GetY()) {
		return true;
	}
	else {
		return false;
	}
}

Point::~Point() {
}