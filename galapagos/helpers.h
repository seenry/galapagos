#pragma once

typedef struct Storage {
	double stored;
	char hasStored;
} Storage;

// ctrl+f "checkAlloc(#"
void checkAlloc(int blame, void* ptr);

double rng();
double normal(double mean, double std, Storage* store);

Storage* initStore();
void destroyStore(Storage* s);