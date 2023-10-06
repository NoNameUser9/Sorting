﻿#include "time.h"  // NOLINT(modernize-deprecated-headers)
#include "sort.h"
#include <iostream>

using namespace std;

chrono::duration<double, ratio<1, 1>> time(void (*f)(dualtype&, const uint64_t& col, const bool&), dualtype& a, const uint64_t& col, const bool& to_low)
{
    const auto start = chrono::system_clock::now();
    f(a, col, to_low); // NOLINT(bugprone-branch-clone)
    const auto end = chrono::system_clock::now();

    return chrono::duration<double, ratio<1, 1>>(end - start); // NOLINT(modernize-return-braced-init-list)
}

chrono::duration<double, ratio<1, 1>> test(void (*f)(dualtype&, const uint64_t& col, const bool&), dualtype& a, const uint16_t& n, const address& path ,const uint64_t& col, const bool& to_low)
{
    if (!path.try_open())
        return chrono::duration<double, ratio<1, 1>>(0);

    chrono::duration<double> t{};
    for (int i = 0; i < n; ++i)
    {
        read_vec(a, path);
        t += time(f, a, col, to_low);
    }

    return t /= n;
}

void full_test(dualtype& a, const uint16_t& n, const address& path, const uint64_t& col, const bool& to_low)
{
    if (!path.try_open())
        return;

    cout << "bubble_sort:\n" << test(bubble_sort, a, n, path, col, to_low) << endl << endl;
    cout << "selection_sort:\n" << test(selection_sort, a, n, path, col, to_low) << endl << endl;
    cout << "insertion_sort:\n" << test(insertion_sort, a, n, path, col, to_low) << endl << endl;
    cout << "q_sort:\n" << test(q_sort, a, n, path, col, to_low) << endl << endl;
    cout << "merge_sort:\n" << test(merge_sort, a, n, path, col, to_low) << endl << endl;
    cout << "shell_sort:\n" << test(shell_sort, a, n, path, col, to_low) << endl << endl;
    cout << "heap_sort:\n" << test(heap_sort, a, n, path, col, to_low) << endl << endl;
    cout << "literal_sort:\n" << test(literal_sort, a, n, path, col, to_low) << endl << endl;
}
