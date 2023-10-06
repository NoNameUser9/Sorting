#pragma once
#include <chrono>
#include "struct.h"
#include "io.h"

// using namespace std;  // NOLINT(clang-diagnostic-header-hygiene)

/**
 * \brief this function testing time for function complete
 * \param f pointer to function
 * \param a array in function
 * \param col is column of sort
 * \param to_low true if sort from high to low
 * \return time in seconds
 */
std::chrono::duration<double, std::ratio<1, 1>> time(void (*f)(dualtype&, const uint64_t& col, const bool&), dualtype& a, const uint64_t& col, const bool& to_low);
/**
 * \brief this function testing time for function complete in [n] iterations
 * \param f pointer to function
 * \param a array in function
 * \param n number of iterations
 * \param path path to file with data
 * \param col is column of sort
 * \param to_low true if sort from high to low
 * \return time in seconds
 */
std::chrono::duration<double, std::ratio<1, 1>> test(void (*f)(dualtype&, const uint64_t& col, const bool&), dualtype& a, const uint16_t& n, const address& path, const uint64_t& col, const bool& to_low);
void full_test(dualtype& a, const uint16_t& n, const address& path, const uint64_t& col, const bool& to_low);