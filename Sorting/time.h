#pragma once
#include <chrono>
#include "struct.h"
#include "io.h"
using namespace std;  // NOLINT(clang-diagnostic-header-hygiene)

/**
 * \brief this function testing time for function complete
 * \param f pointer to function
 * \param a array in function
 * \param num number of array elements
 * \return time in seconds
 */
std::chrono::duration<double, std::ratio<1, 1>> time(void (*f)(const my_struct&, int), my_struct& a, int num);
/**
 * \brief this function testing time for function complete in [n] iterations
 * \param f pointer to function
 * \param a array in function
 * \param num number of array elements
 * \param n number of iterations
 * \param path path to file with data
 * \return time in seconds
 */
std::chrono::duration<double, std::ratio<1, 1>> test(void (*f)(const my_struct&, int), const my_struct& a, int num, int n, const address& path);
void full_test(const my_struct& a, const int& num, const int& n, const address& path);