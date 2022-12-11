#include <celero/Celero.h>

#include <random>
#include <iostream>

#include "myproject.h"

CELERO_MAIN


BASELINE(Multiplication, Original, 30, 1)
{
    celero::DoNotOptimizeAway(myproject::my_mul(1000, 1000));
}


BENCHMARK(Multiplication, Optimized, 30, 1)
{
    celero::DoNotOptimizeAway(myproject::my_mul_optimized(1000, 1000));
}