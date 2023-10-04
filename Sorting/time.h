#pragma once
#include <chrono>
#include "struct.h"
#include "io.h"

// using namespace std;  // NOLINT(clang-diagnostic-header-hygiene)

/**
 * \brief this function testing time for function complete
 * \param f pointer to function
 * \param a array in function
 * \param to_low true if sort from high to low
 * \return time in seconds
 */
std::chrono::duration<double, std::ratio<1, 1>> time(void (*f)(const dualtype&, const bool&), const dualtype& a, const bool& to_low);
/**
 * \brief this function testing time for function complete in [n] iterations
 * \param f pointer to function
 * \param a array in function
 * \param n number of iterations
 * \param path path to file with data
 * \param to_low true if sort from high to low
 * \return time in seconds
 */
std::chrono::duration<double, std::ratio<1, 1>> test(void (*f)(const dualtype&, const bool&), const dualtype& a, const int& n, const address& path,const bool& to_low);
void full_test(const dualtype& a, const int& n, const address& path, const bool& to_low);