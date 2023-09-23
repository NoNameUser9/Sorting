// ReSharper disable CommentTypo
// ReSharper disable CppClangTidyModernizeRawStringLiteral
// ReSharper disable StringLiteralTypo
#include <iostream>
#include "io.h"
#include "sort.h"
#include "time.h"  // NOLINT(modernize-deprecated-headers)
using namespace std;

const string path = "C:\\Users\\User\\Documents\\data.csv";
const string path_out = "C:\\Users\\User\\Documents\\dataout.csv";

int main(int argc, char* argv[])
{
    // ReSharper disable once CppDeclaratorNeverUsed
    constexpr int num = 5000, n = 100;
    
    int a[num] = {};
    
    // auto *ptr = bubble_sort;
    // auto *ptr2 = selection_sort;
    // auto *ptr3 = insertion_sort;
    // auto *ptr4 = q_sort;
    // // auto *ptr5 = merge_sort;
    // auto *ptr6 = shell_sort;
    // auto *ptr7 = heap_sort;
    
    // cout << "bubble_sort:\n" << test(ptr, a, num, n, path) << endl << endl;
    // cout << "selection_sort:\n" << test(ptr2, a, num, n, path) << endl << endl;
    // cout << "insertion_sort:\n" << test(ptr3, a, num, n, path) << endl << endl;
    // cout << "q_sort:\n" << test(ptr4, a, num, n, path) << endl << endl;
    // cout << "shell_sort:\n" << test(ptr6, a, num, n, path) << endl << endl;
    // cout << "heap_sort:\n" << test(ptr7, a, num, n, path) << endl << endl;
    
    read(a, path);
    shell_sort(a, num);
    print(a, num);

    write(a, path_out, num);
    
    return 0;
}