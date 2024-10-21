// Benchmark.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <inttypes.h>
#include <intrin.h>

#pragma intrinsic(__rdtsc)
#define NTEST 100000

void measured_function(volatile int* var) {
    (*var) = 1;
}

int main()
{
    int variable = 0;
    uint64_t start, end;

    std::cout << "Calentamiento...\n";
    for (int i = 0; i < NTEST; i++)
        measured_function(&variable);

    std::cout << "Medición...\n";
    start = __rdtsc();
    measured_function(&variable);
    end   = __rdtsc();

    std::cout << "Total = " << (end - start) / NTEST << "CPU Cycles" << std::endl;
}
