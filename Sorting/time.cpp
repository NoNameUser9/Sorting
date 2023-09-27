#include "time.h"  // NOLINT(modernize-deprecated-headers)
#include "sort.h"
#include <iostream>

using namespace std;

chrono::duration<double, ratio<1, 1>> time(void (*f)(const my_struct&, int), const my_struct& a, const int num)
{
    const auto start = chrono::system_clock::now();
    if(a.type == _Int)
        f(a, num);  // NOLINT(bugprone-branch-clone)
    else if(a.type == _Str)
        f(a, num);
        
    const auto end = chrono::system_clock::now();
    
    return chrono::duration<double, ratio<1, 1>>(end - start);  // NOLINT(modernize-return-braced-init-list)
}

chrono::duration<double, ratio<1, 1>> test(void (*f)(const my_struct&, int), const my_struct& a, const int num, const int n, const address& path)
{
    if(!path.try_open())
        return chrono::duration<double, ratio<1, 1>>(0);

    chrono::duration<double> t{};
    
    for(int i = 0; i < n; ++i)
    {
        read(a, path);
        t += time(f, a, num);
    }
    
    return t /= n;
}

void full_test(const my_struct& a, const int& num, const int& n, const address& path)
{
    if(!path.try_open())
        return;

    cout << "bubble_sort:\n" << test(bubble_sort, a, num, n, path) << endl << endl;
    cout << "selection_sort:\n" << test(selection_sort, a, num, n, path) << endl << endl;
    cout << "insertion_sort:\n" << test(insertion_sort, a, num, n, path) << endl << endl;
    cout << "q_sort:\n" << test(q_sort, a, num, n, path) << endl << endl;
    // ReSharper disable CommentTypo
    // cout << "merge_sort:\n" << test(merge_sort, a, num, n, path, type) << endl << endl;
    // ReSharper restore CommentTypo
    cout << "shell_sort:\n" << test(shell_sort, a, num, n, path) << endl << endl;
    cout << "heap_sort:\n" << test(heap_sort, a, num, n, path) << endl << endl;
    cout << "literal_sort:\n << " << test(literal_sort, a, num, n, path) << endl << endl;
}
