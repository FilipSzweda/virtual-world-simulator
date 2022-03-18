#pragma once
#include "world.h"
#include "organism.h"
#include "animal.h"
#include "antelope.h"
#include "fox.h"
#include "sheep.h"
#include "wolf.h"
#include "tortoise.h"
#include "human.h"
#include "plant.h"
#include "sosnowskys_hogweed.h"
#include "guarana.h"
#include "dandelion.h"
#include "grass.h"
#include "deadly_nightshade.h"

class SimulationManager {
private:
	World* world;
public:
	SimulationManager(World* world);

	void NewSimulation();
	void LoadSimulation();
	void Simulate();

	~SimulationManager();
};
