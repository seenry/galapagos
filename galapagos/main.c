#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "helpers.h"

int main()
{
    Storage* store = initStore();
    double n = 0;
    srand(time(NULL));

    n = rng();
    printf("%f\n", n);
    n = rng();
    printf("%f\n", n);
    n = normal(0, 1, store);
    printf("%f\n", n);
    n = normal(0, 1, store);
    printf("%f\n", n);

    destroyStore(store);

    return 0;
}