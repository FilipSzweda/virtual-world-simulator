#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <tchar.h>
#include "windows.h"
#include "simulation_manager.h"
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

int main() {
    SetConsoleTitle(_T("Virtual World Simulator"));
    printf("n - New Simulation\n");
    printf("l - Load Simulation\n");
    printf("m - Markings\n");
    bool waitingForInput = true;
    char input;
    while (waitingForInput) {
        scanf("%c", &input);
        if (input == 'n') {
            int width, height;
            double sowingProbability;
            do {
                printf("World width:\n");
                scanf("%i", &width);
            } while (width < 1);
            do {
                printf("World height:\n");
                scanf("%i", &height);
            } while (height < 1);
            do {
                printf("Sowing probability:\n");
                scanf("%lf", &sowingProbability);
            } while (sowingProbability < 0);
            World world(width, height, sowingProbability);
            SimulationManager simulationManager(&world);
            simulationManager.NewSimulation();
        }
        else if (input == 'l') {
            std::ifstream we("save.txt");
            int width, height, turn, abilityUseTurn, x, y, strength;
            double sowingProbability;
            char symbol;
            we >> width;
            we >> height;
            we >> sowingProbability;
            we >> turn;
            we >> abilityUseTurn;
            World world(width, height, sowingProbability);
            world.SetAbilityUseTurn(turn);
            world.SetAbilityUseTurn(abilityUseTurn);
            SimulationManager simulationManager(&world);
            simulationManager.LoadSimulation();
        }
        else if (input == 'm') {
            printf("A - Antelope\n");
            printf("H - Human\n");
            printf("F - Fox\n");
            printf("S - Sheep\n");
            printf("W - Wolf\n");
            printf("T - Tortoise\n");
            printf("\033[31mx\033[0m - Sosnowskys Hogweed\n");
            printf("\033[94m$\033[0m - Guarana\n");
            printf("\033[93m*\033[0m - Dandelion\n");
            printf("\033[92m#\033[0m - Grass\n");
            printf("\033[91m+\033[0m - Deadly Nightshade\n");
        }
    }
    return 0;
}