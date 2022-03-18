#pragma once
#include <vector>
#include "point.h"
class World;

class Organism {
private:
	World* world;
	Point position;
	char symbol;
	int strength;
	int initiative;
	bool alive;
public:
	Organism(World* world, Point position, char symbol, int strength, int initiative);

	virtual void Action() = 0;
	virtual void Collision(Organism* collidingOrganism, Point previousPosition) = 0;
	virtual void Breeding(Organism* collidingOrganism, Point previousPosition);
	virtual void Fight(Organism* collidingOrganism, Point previousPosition);
	virtual void Deflection(Point previousPosition);
	virtual void AlzursShield(Point previousPosition);
	virtual void Escape(Organism* attackingOrganism);
	virtual void Draw() = 0;
	virtual Organism* CreateCopy(Point position) = 0;

	virtual void AddOrganismToMap(Point position);
	virtual void RemoveOrganismFromMap(Point position);
	virtual bool DeflectedAttack(Organism* attackingOrganism);
	virtual bool EscapedFight();
	virtual bool GivesStrengthBonus();
	virtual bool IsPoisonous();
	virtual bool IsAnimal();
	virtual bool ActivatedAlzursShield();
	virtual bool CheckForCollision(Organism* organizm);

	std::vector <Point> FindNeighboringPositions();
	int CalculateMapIndex(Point polozenieDoIndexu);

	World *GetWorld() const;
	Point GetPosition() const;
	char GetSymbol() const;
	int GetStrength() const;
	int GetInitiative() const;
	bool GetAlive() const;

	void SetWorld(World* world);
	void SetPosition(Point position);
	void SetPositionX(int x);
	void SetPositionY(int y);
	void SetSymbol(char symbol);
	void SetStrength(int strength);
	void SetAlive(bool alive);

	virtual ~Organism();
};
