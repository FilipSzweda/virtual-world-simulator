#include "simulation_manager.h"

SimulationManager::SimulationManager(World* world) : world(world){
}

void SimulationManager::NewSimulation() {
    int x = 0, y = 0;
    Point humanPosition(x, y);
    this->world->AddOrganism(new Human(world, humanPosition));
    for (int i = 1; i < this->world->GetWidth(); i++) {
        int randomizedOrganism = rand() % 10;
        Point position(i, 0);
        switch (randomizedOrganism) {
        case 0:
            world->AddOrganism(new SosnowskysHogweed(world, position));
            break;
        case 1:
            world->AddOrganism(new Guarana(world, position));
            break;
        case 2:
            world->AddOrganism(new Dandelion(world, position));
            break;
        case 3:
            world->AddOrganism(new Grass(world, position));
            break;
        case 4:
            world->AddOrganism(new DeadlyNightshade(world, position));
            break;
        case 5:
            world->AddOrganism(new Antelope(world, position));
            break;
        case 6:
            world->AddOrganism(new Fox(world, position));
            break;
        case 7:
            world->AddOrganism(new Sheep(world, position));
            break;
        case 8:
            world->AddOrganism(new Wolf(world, position));
            break;
        case 9:
            world->AddOrganism(new Tortoise(world, position));
            break;
        }
    }
    for (int i = 1; i < this->world->GetHeight(); i++) {
        for (int j = 0; j < this->world->GetWidth(); j++) {
            int randomizedOrganism = rand() % 10;
            Point position(j, i);
            switch (randomizedOrganism) {
            case 0:
                world->AddOrganism(new SosnowskysHogweed(world, position));
                break;
            case 1:
                world->AddOrganism(new Guarana(world, position));
                break;
            case 2:
                world->AddOrganism(new Dandelion(world, position));
                break;
            case 3:
                world->AddOrganism(new Grass(world, position));
                break;
            case 4:
                world->AddOrganism(new DeadlyNightshade(world, position));
                break;
            case 5:
                world->AddOrganism(new Antelope(world, position));
                break;
            case 6:
                world->AddOrganism(new Fox(world, position));
                break;
            case 7:
                world->AddOrganism(new Sheep(world, position));
                break;
            case 8:
                world->AddOrganism(new Wolf(world, position));
                break;
            case 9:
                world->AddOrganism(new Tortoise(world, position));
                break;
            }
        }
    }
    this->Simulate();
}

void SimulationManager::LoadSimulation() {
    std::ifstream in("save.txt");
    int width, height, turn, abilityUseTurn, x, y, strength;
    double sowingProbability;
    char symbol;
    in >> width;
    in >> height;
    in >> sowingProbability;
    in >> turn;
    in >> abilityUseTurn;
    while (!in.eof()) {
        in >> symbol;
        in >> x;
        in >> y;
        in >> strength;
        Point position(x, y);
        switch (symbol) {
        case 'x':
            world->AddOrganism(new SosnowskysHogweed(world, position));
            break;
        case '$':
            world->AddOrganism(new Guarana(world, position));
            break;
        case '*':
            world->AddOrganism(new Dandelion(world, position));
            break;
        case '#':
            world->AddOrganism(new Grass(world, position));
            break;
        case '+':
            world->AddOrganism(new DeadlyNightshade(world, position));
            break;
        case 'A':
            world->AddOrganism(new Antelope(world, position, strength));
            break;
        case 'H':
            world->AddOrganism(new Human(world, position, strength));
            break;
        case 'F':
            world->AddOrganism(new Fox(world, position, strength));
            break;
        case 'S':
            world->AddOrganism(new Sheep(world, position, strength));
            break;
        case 'W':
            world->AddOrganism(new Wolf(world, position, strength));
            break;
        case 'T':
            world->AddOrganism(new Tortoise(world, position, strength));
            break;
        }
    }
    this->Simulate();
}

void SimulationManager::Simulate() {
    while (true) {
        world->DrawWorld();
        world->TakeInput();
        system("CLS");
        world->TakeTurn();
    }
}

SimulationManager::~SimulationManager() {
}