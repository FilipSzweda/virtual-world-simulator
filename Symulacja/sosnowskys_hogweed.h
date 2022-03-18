#pragma once
#include "plant.h"

#define SOSNOWSKYS_HOGWEED_STRENGTH 10
#define SOSNOWSKYS_HOGWEED_SYMBOL 'x'

class SosnowskysHogweed : public Plant {
public:
	SosnowskysHogweed(World* world, Point& position);

	void Action() override;
	void Draw() override;
	bool IsPoisonous() override;
	Organism* CreateCopy(Point position) override;

	~SosnowskysHogweed();
};