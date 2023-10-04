﻿#pragma once
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
 * \param to_low true if sort from high to low
 */
void bubble_sort(const dualtype& a, const bool& to_low);
/**
 * \brief selects the smallest element and swap it with a[i]
 * \param a a[num] array
 * \param to_low true if sort from high to low
 */
void selection_sort(const dualtype& a, const bool& to_low);
/**
 * \brief go at the end of array and pulls small element to initial element of iteration
 * \param a a[num] array
 * \param to_low true if sort from high to low
 */
void insertion_sort(const dualtype& a, const bool& to_low);
/**
 * \brief it's a quick sort - recursive sorting algorithm
 * \param a a[num] array
 * \param to_low true if sort from high to low
 */
void q_sort(const dualtype& a, const bool& to_low);
/**
 * \brief Don't realized now!
 * \param a array
 * \param to_low true if sort from high to low
 */
void merge_sort(const dualtype& a, const bool& to_low);
/**
 * \brief it's a Shell sort, quick and simple sorting algorithm
 * \param a array a[num]
 * \param to_low true if sort from high to low
 */
void shell_sort(const dualtype& a, const bool& to_low);
/**
 * \brief heap sort(binary tree sort or pyramid sort)
 * \param a a[num] array
 * \param to_low true if sort from high to low
 */
void heap_sort(const dualtype& a, const bool& to_low);
/**
 * \brief sorting by name
 * \param a a[num] array
 * \param to_low true if sort from high to low
 */
void literal_sort(const dualtype& a, const bool& to_low);