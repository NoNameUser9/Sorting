#include "time.h"  // NOLINT(modernize-deprecated-headers)
#include "sort.h"
#include <iostream>

using namespace std;

std::chrono::duration<double, std::ratio<1, 1>> time(void (*f)(int*, int), int* a, const int num)
{
    const auto start = chrono::system_clock::now();
    f(a, num);
    const auto end = chrono::system_clock::now();
    
    return std::chrono::duration<double, std::ratio<1, 1>>(end - start);  // NOLINT(modernize-return-braced-init-list)
}

std::chrono::duration<double, std::ratio<1, 1>> test(void (*f)(int*, int), int* a, const int num, const int n, const address& path)
{
    if(!path.try_open())
        return std::chrono::duration<double, std::ratio<1, 1>>(0);

    chrono::duration<double> t{};
    
    for(int i = 0; i < n; ++i)
    {
        read(a, path.get_address());
        t += time(f, a, num);
    }
    
    return t /= n;
}

void full_test(int* a, const int& num, const int& n, const address& path)
{
    if(!path.try_open())
        return;
    
    auto *ptr = bubble_sort;
    auto *ptr2 = selection_sort;
    auto *ptr3 = insertion_sort;
    auto *ptr4 = q_sort;
    // auto *ptr5 = merge_sort;
    auto *ptr6 = shell_sort;
    auto *ptr7 = heap_sort;

    cout << "bubble_sort:\n" << test(ptr, a, num, n, path) << endl << endl;
    cout << "selection_sort:\n" << test(ptr2, a, num, n, path) << endl << endl;
    cout << "insertion_sort:\n" << test(ptr3, a, num, n, path) << endl << endl;
    cout << "q_sort:\n" << test(ptr4, a, num, n, path) << endl << endl;
    cout << "shell_sort:\n" << test(ptr6, a, num, n, path) << endl << endl;
    cout << "heap_sort:\n" << test(ptr7, a, num, n, path) << endl << endl;
}