#include <stdlib.h>

#include "basic.h"
#include "helpers.h"

Basic* initBasic(int* nodesPerLayer, int numLayers) {
	Basic* b = (Basic*) malloc(sizeof(Basic));
	checkAlloc(1, b);

	int genomeSize = 0;
	for (int i = 1; i < numLayers; i++) {
		genomeSize += nodesPerLayer[i - 1] * nodesPerLayer[i];
	}
	double* weights = (double*) malloc(genomeSize * sizeof(double));

	b->nodesPerLayer = nodesPerLayer;
	b->weights = weights;
	b->fitness = 0;
	b->numLayers = numLayers;

	return b;
};

void destroyBasic(Basic* poorSoul) {
	free(poorSoul->nodesPerLayer);
	free(poorSoul->weights);
	free(poorSoul);
}