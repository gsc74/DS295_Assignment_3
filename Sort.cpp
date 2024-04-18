#include <iostream>
#include <stdlib.h>
#include <random>
#include <cmath>
#include <omp.h>
#include <vector>
#include <chrono>
#include <algorithm>
#include <execution>


int main(int argc, char* argv[])
{
    // Read input.bin first n and then each element
    auto start = std::chrono::high_resolution_clock::now();
    int64_t n;
    FILE* in = fopen("input.bin", "rb");
    fread(&n, sizeof(int64_t), 1, in);
    std::vector<int> rand_array(n);
    for (int64_t i = 0; i < n; i++)
    {
        fread(&rand_array[i], sizeof(int), 1, in);
    }
    fclose(in);
    
    std::sort(std::execution::par, rand_array.begin(), rand_array.end());

    // dump to output.bin
    FILE* out = fopen("output.bin", "wb");
    fwrite(&n, sizeof(int64_t), 1, out);
    for (int64_t i = 0; i < n; i++)
    {
        fwrite(&rand_array[i], sizeof(int), 1, out);
    }
    fclose(out);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time taken to sort input.bin: " << elapsed.count() << "s" << std::endl;

    return 0;
}