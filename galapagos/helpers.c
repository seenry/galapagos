#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "helpers.h"

void checkAlloc(int blame, void* ptr) {
	if (ptr == NULL) {
		printf("failed to alloc. blame: %d\n", blame);
		exit(-1);
	}
}

// random uniform
double rng() {
	return ((double) rand() / (double) RAND_MAX);
}

// random normal
double normal(double mean, double std, Storage* store) {
	if (store->hasStored) {
		store->hasStored = 0;
		return store->stored;
	} else {
		// Marsaglia Polar
		double x;
		double y;
		double s;

		do {
			x = rng() * 2 - 1;
			y = rng() * 2 - 1;
			s = x*x + y*y;
		} while (s == 0 || s >= 1);

		s = sqrt((-2 * log(s)) / s);

		store->hasStored = 1;
		store->stored = x * s;
		return y * s;
	}
}

Storage* initStore() {
	Storage* store = (Storage*) malloc(sizeof(Storage));
	checkAlloc(0, store);

	store->hasStored = 0;
	
	return store;
}

void destroyStore(Storage* store) {
	free(store);
}