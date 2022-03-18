#pragma once
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include "organism.h"
#include "animal.h"

#define ARROW_UP 72
#define ARROW_RIGHT 77
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define SPACE 32
#define ENTER 13
#define ESCAPE 27

class World {
private:
	int width;
	int height;
	int turn;
	int abilityUseTurn;
	int input;
	bool humanAlive;
	double sowingProbability;
	std::vector <Organism*> organisms;
	std::vector <Organism*> activeOrganisms;
	Organism** map = new Organism*[width * height];
public:
	World(int width, int height, double sowingProbability);

	void SetSowingProbability(double sowingProbability);
	void SetTurn(int turn);
	void SetAbilityUseTurn(int abilityUseTurn);
	void SetHumanAlive(bool humanAlive);

	int GetInput() const;
	int GetTurn() const;
	int GetAbilityUseTurn() const;
	int GetWidth() const;
	int GetHeight() const;
	bool GetHumanAlive() const;
	Organism** GetMap() const;
	std::vector <Organism*> GetOrganisms() const;
	std::vector <Organism*> GetActiveOrganisms() const;
	double GetSowingProbability() const;

	void SaveSimulation();
	void DrawWorld();
	void DrawInterface();
	void DrawSimulationWindow();
	void TakeInput();
	void TakeTurn();
	void UpdateActiveOrganisms();
	void AddOrganism(Organism* newOrganism);
	void RemoveOrganism(Organism* removedOrganism);

	~World();
};