#pragma once
#include <string>
using namespace std;  // NOLINT(clang-diagnostic-header-hygiene)

/**
 * \brief read data from file
 * \param a a[] array
 * \param path path to file with data
 */
void read(int* a, const string& path);
/**
 * \brief write data to file
 * \param a a[] array
 * \param path path to file with data
 * \param num size of array
 */
void write(const int* a, const string& path, int num);
void print(auto* arr, int num);