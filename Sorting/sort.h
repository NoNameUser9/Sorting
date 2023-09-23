#pragma once
#include <string>

void swap(int& a, int& b) noexcept;

/**
 * \brief bubble-like sorting algorithm
 * \param a a[num] array
 * \param num number of array elements
 */
void bubble_sort(int* a, int num);
/**
 * \brief selects the smallest element and swap it with a[i]
 * \param a a[num] array
 * \param num number of array elements
 */
void selection_sort(int* a, int num);
/**
 * \brief go at the end of array and pulls small element to initial element of iteration
 * \param a a[num] array
 * \param num number of array elements
 */
void insertion_sort(int* a, int num);
/**
 * \brief it's a quick sort - recursive sorting algorithm
 * \param a a[num] array
 * \param num number of array elements
 */
void q_sort(int* a, int num);
/**
 * \brief Don't realized now!
 * \param a array
 * \param num nums of array elements
 */
void merge_sort(int* a, int num);
/**
 * \brief it's a Shell sort, quick and simple sorting algorithm
 * \param a array a[num]
 * \param num number of elements of array
 */
void shell_sort(int* a, int num);
/**
 * \brief heap sort(binary tree sort or pyramid sort)
 * \param a a[num] array
 * \param num number of array elements
 */
void heap_sort(int* a, int num);
void literal_sort(std::string* a, int num);