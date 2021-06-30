#pragma once

class Punkt {
private:
	int x;
	int y;
public:
	Punkt(int x, int y);

	int GetX() const;
	int GetY() const;

	void SetX(int x);
	void SetY(int y);

	bool operator==(const Punkt other);

	~Punkt();
};