#include <iostream>
#include <stdlib.h>
#include <random>
#include <cmath>
#include <vector>
#include <chrono>

int main(int argc, char* argv[])
{
    int64_t n = 25 * 1024 * 1024 * 1024 / sizeof(int); // 24GB

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> rand_array(n);

    for (int64_t i = 0; i < n; i++)
    {
        rand_array[i] = rand()%INT32_MAX;
    }

    // dump to input.bin
    FILE* out = fopen("input.bin", "wb");
    fwrite(&n, sizeof(int64_t), 1, out);
    for (int64_t i = 0; i < n; i++)
    {
        fwrite(&rand_array[i], sizeof(int), 1, out);
    }
    fclose(out);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time taken to generate input.bin: " << elapsed.count() << "s" << std::endl;

    return 0;
}
