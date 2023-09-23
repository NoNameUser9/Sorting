#include "time.h"  // NOLINT(modernize-deprecated-headers)
#include "io.h"
#include <chrono>

auto time(void (*f)(int*, int), int* a, const int num)
{
    const auto start = chrono::system_clock::now();
    f(a, num);
    const auto end = chrono::system_clock::now();
    
    return chrono::duration<double>(end - start);
}

auto test(void (*f)(int*, int), int* a, const int num, const int n, const string& path)
{
    chrono::duration<double> t{};
    for(int i = 0; i < n; ++i)
    {
        read(a, path);
        t += time(f, a, num);
    }
    
    return t /= n;
}