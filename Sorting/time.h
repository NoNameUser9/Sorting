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
 * \param type type of data
 * \return time in seconds
 */
std::chrono::duration<double, std::ratio<1, 1>> time(void (*f)(int*, int), const my_struct& a, int num, std::underlying_type_t<std::byte> type);
/**
 * \brief this function testing time for function complete in [n] iterations
 * \param f pointer to function
 * \param a array in function
 * \param num number of array elements
 * \param n number of iterations
 * \param path path to file with data
 * \param type type of data
 * \return time in seconds
 */
std::chrono::duration<double, std::ratio<1, 1>> test(void (*f)(int*, int), const my_struct& a, int num, int n, const address& path, std::underlying_type_t<std::byte> type);
void full_test(const my_struct& a, const int& num, const int& n, const address& path, std::underlying_type_t<std::byte> type);