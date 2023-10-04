#include "time.h"  // NOLINT(modernize-deprecated-headers)
#include "sort.h"
#include <iostream>

using namespace std;

chrono::duration<double, ratio<1, 1>> time(void (*f)(const dualtype&, const bool&), const dualtype& a, const bool& to_low)
{
    const auto start = chrono::system_clock::now();
    f(a, to_low); // NOLINT(bugprone-branch-clone)

    const auto end = chrono::system_clock::now();

    return chrono::duration<double, ratio<1, 1>>(end - start); // NOLINT(modernize-return-braced-init-list)
}

chrono::duration<double, ratio<1, 1>> test(void (*f)(const dualtype&, const bool&), const dualtype& a, const int& n, const address& path, const bool& to_low)
{
    if (!path.try_open())
        return chrono::duration<double, ratio<1, 1>>(0);

    chrono::duration<double> t{};
    vector<vector<string>> vec;
    for (int i = 0; i < n; ++i)
    {
        read_vec(vec, path);
        for(int j = 0; j < vec.size(); ++j)
        {
            a.Str.resize(j+1);
            a.Str[j] = vec[j][0];
        }
        t += time(f, a, to_low);
    }

    return t /= n;
}

void full_test(const dualtype& a, const int& n, const address& path, const bool& to_low)
{
    if (!path.try_open())
        return;

    cout << "bubble_sort:\n" << test(bubble_sort, a, n, path, to_low) << endl << endl;
    cout << "selection_sort:\n" << test(selection_sort, a, n, path, to_low) << endl << endl;
    cout << "insertion_sort:\n" << test(insertion_sort, a, n, path, to_low) << endl << endl;
    cout << "q_sort:\n" << test(q_sort, a, n, path, to_low) << endl << endl;
    // ReSharper disable CommentTypo
    cout << "merge_sort:\n" << test(merge_sort, a, n, path, to_low) << endl << endl;
    cout << "shell_sort:\n" << test(shell_sort, a, n, path, to_low) << endl << endl;
    cout << "heap_sort:\n" << test(heap_sort, a, n, path, to_low) << endl << endl;
    a.is_Str_read = true;
    cout << "literal_sort:\n" << test(literal_sort, a, n, path, to_low) << endl << endl;
    a.is_Str_read = false;
    // ReSharper restore CommentTypo
}
