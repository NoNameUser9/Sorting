#include "time.h"  // NOLINT(modernize-deprecated-headers)
#include "sort.h"
#include <iostream>

using namespace std;

chrono::duration<double, ratio<1, 1>> time(void (*f)(unitype&, const uint16_t& col, const bool&), unitype& a, const uint16_t& col, const bool& to_low)
{
    const auto start = chrono::system_clock::now();
    f(a, col, to_low); // NOLINT(bugprone-branch-clone)
    const auto end = chrono::system_clock::now();

    return chrono::duration<double, ratio<1, 1>>(end - start); // NOLINT(modernize-return-braced-init-list)
}

chrono::duration<double, ratio<1, 1>> test(void (*f)(unitype&, const uint16_t& col, const bool&), unitype& a, const uint16_t& n, const address& path ,const uint16_t& col, const bool& to_low)
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

void full_test(unitype& a, const uint16_t& n, const address& path, const uint16_t& col, const bool& to_low)
{
    if (!path.try_open())
        return;
    chrono::duration<double, ratio<1, 1>>
    time =test(bubble_sort, a, n, path, col, to_low);
    cout << "bubble_sort:\n" << time << endl << endl;
    time = test(selection_sort, a, n, path, col, to_low);
    cout << "selection_sort:\n" << time << endl << endl;
    time = test(insertion_sort, a, n, path, col, to_low);
    cout << "insertion_sort:\n" << time << endl << endl;
    time = test(q_sort, a, n, path, col, to_low);
    cout << "q_sort:\n" << time << endl << endl;
    time = test(merge_sort, a, n, path, col, to_low);
    cout << "merge_sort:\n" << time << endl << endl;
    time = test(shell_sort, a, n, path, col, to_low);
    cout << "shell_sort:\n" << time << endl << endl;
    time = test(heap_sort, a, n, path, col, to_low);
    cout << "heap_sort:\n" << time << endl << endl;
    time = test(literal_sort, a, n, path, col, to_low);
    cout << "literal_sort:\n" << time << endl << endl;
}
