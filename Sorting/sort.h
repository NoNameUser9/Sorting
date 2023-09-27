#pragma once

#include "struct.h"

void swap(auto& a, auto& b) noexcept
{
 const auto temp = b;
 b = a;
 a = temp;
}

/**
 * \brief bubble-like sorting algorithm
 * \param a a[num] array
 * \param num number of array elements
 */
void bubble_sort(const my_struct& a, int num);
/**
 * \brief selects the smallest element and swap it with a[i]
 * \param a a[num] array
 * \param num number of array elements
 */
void selection_sort(const my_struct& a, int num);
/**
 * \brief go at the end of array and pulls small element to initial element of iteration
 * \param a a[num] array
 * \param num number of array elements
 */
void insertion_sort(const my_struct& a, int num);
/**
 * \brief it's a quick sort - recursive sorting algorithm
 * \param a a[num] array
 * \param num number of array elements
 */
void q_sort(const my_struct& a, int num);
/**
 * \brief Don't realized now!
 * \param a array
 * \param num nums of array elements
 */
void merge_sort(const my_struct& a, int num);
/**
 * \brief it's a Shell sort, quick and simple sorting algorithm
 * \param a array a[num]
 * \param num number of elements of array
 */
void shell_sort(const my_struct& a, int num);
/**
 * \brief heap sort(binary tree sort or pyramid sort)
 * \param a a[num] array
 * \param num number of array elements
 */
void heap_sort(const my_struct& a, int num);
void literal_sort(const my_struct& a, int num);