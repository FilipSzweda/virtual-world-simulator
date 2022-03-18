#pragma once

class Point {
private:
	int x;
	int y;
public:
	Point(int x, int y);

	int GetX() const;
	int GetY() const;

	void SetX(int x);
	void SetY(int y);

	bool operator==(const Point other);

	~Point();
};