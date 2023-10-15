#include "time.h"  // NOLINT(modernize-deprecated-headers)
#include "sort.h"
#include <iostream>

std::chrono::duration<double, std::ratio<1, 1>> time(void (*f)(unitype&, const uint16_t& col, const bool&), unitype& a, const uint16_t& col, const bool& to_low)
{
    const auto start = std::chrono::system_clock::now();
    f(a, col, to_low); // NOLINT(bugprone-branch-clone)
    const auto end = std::chrono::system_clock::now();

    return std::chrono::duration<double, std::ratio<1, 1>>(end - start); // NOLINT(modernize-return-braced-init-list)
}

std::chrono::duration<double, std::ratio<1, 1>> test(void (*f)(unitype&, const uint16_t& col, const bool&), unitype& a, const uint16_t& n, const address& path ,const uint16_t& col, const bool& to_low)
{
    if (!path.try_open())
        return std::chrono::duration<double, std::ratio<1, 1>>(0);

    std::chrono::duration<double> t{};
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
    std::chrono::duration<double, std::ratio<1, 1>>
    time =test(bubble_sort, a, n, path, col, to_low);
    std::cout << "bubble_sort:\n" << time << std::endl << std::endl;
    time = test(selection_sort, a, n, path, col, to_low);
    std::cout << "selection_sort:\n" << time << std::endl << std::endl;
    time = test(insertion_sort, a, n, path, col, to_low);
    std::cout << "insertion_sort:\n" << time << std::endl << std::endl;
    time = test(q_sort, a, n, path, col, to_low);
    std::cout << "q_sort:\n" << time << std::endl << std::endl;
    time = test(merge_sort, a, n, path, col, to_low);
    std::cout << "merge_sort:\n" << time << std::endl << std::endl;
    time = test(shell_sort, a, n, path, col, to_low);
    std::cout << "shell_sort:\n" << time << std::endl << std::endl;
    time = test(heap_sort, a, n, path, col, to_low);
    std::cout << "heap_sort:\n" << time << std::endl << std::endl;
    time = test(literal_sort, a, n, path, col, to_low);
    std::cout << "literal_sort:\n" << time << std::endl << std::endl;
}