#pragma once
#include <string>
using namespace std;  // NOLINT(clang-diagnostic-header-hygiene)

/**
 * \brief this function testing time for function complete
 * \param f pointer to function
 * \param a array in function
 * \param num number of array elements
 * \return time in seconds
 */
auto time(void (*f)(int*, int), int* a, int num);
/**
 * \brief this function testing time for function complete in [n] iterations
 * \param f pointer to function
 * \param a array in function
 * \param num number of array elements
 * \param n number of iterations
 * \param path path to file with data
 * \return time in seconds
 */
auto test(void (*f)(int*, int), int* a, int num, int n, const string& path);