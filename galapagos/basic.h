#pragma once

typedef struct Basic {
	int* nodesPerLayer;
	double* weights;
	double fitness;
	int numLayers;
} Basic;

Basic* initBasic(int* nodesPerLayer, int numLayers);
void destroyBasic(Basic* poorSoul);