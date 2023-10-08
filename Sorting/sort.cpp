#include "sort.h"
#include <iostream>

// ReSharper disable once IdentifierTypo
void tolow(dualtype& a, const uint64_t& num)
{
    auto* temp = new std::vector<std::string>[num];
    for(uint64_t i = 0; i < num; ++i)
        temp[num - i-1] = a.Table[i];
    for(uint64_t i = 1; i < num; ++i)
        a.Table[i] = temp[i-1];
}

void bubble_sort(dualtype& a, const uint16_t& col, const bool& to_low)
{
    bool swapped = false;
    auto num_t = a.Table.size();
    
    while (true)
    {
        for(uint64_t i = 1; i < num_t - 1; ++i)
        {
            if(a.str_or_int == true)
            {
                if(a.Table[i][col] > a.Table[i+1][col])
                {
                    swap(a.Table[i], a.Table[i+1]);
                    swapped = true;
                }
            }
            else
            {
                if(stod(a.Table[i][col]) > stod(a.Table[i+1][col]))
                {
                    swap(a.Table[i], a.Table[i+1]);
                    swapped = true;
                }
            }
        }
        if(!swapped)
            break;
        --num_t;
        swapped = false;
    }
    
    if(to_low == true)
        tolow(a, a.Table.size());
}

void selection_sort(dualtype& a, const uint16_t& col, const bool& to_low)
{
    uint64_t index = 1;
    for(uint64_t i = 1; i < a.Table.size()-1; ++i)
    {
        for(uint64_t i1 = i+1; i1 < a.Table.size(); ++i1)
        {
            if(a.str_or_int == true)
            {
                if(a.Table[i1][col] < a.Table[index][col])
                    index = i1;
            }
            else
                if(stod(a.Table[i1][col]) < stod(a.Table[index][col]))
                    index = i1;
        }
        swap(a.Table[i], a.Table[index]);
    }
    
    if(to_low == true)
        tolow(a, a.Table.size());
}

void insertion_sort(dualtype& a, const uint16_t& col, const bool& to_low)
{
    for(uint64_t i = 1; i < a.Table.size(); ++i)
    {
        for(uint64_t i1 = i; i1 > 1; --i1)
        {
            if(a.str_or_int == true)
            {
                if(a.Table[i1][col] < a.Table[i1-1][col])
                    swap(a.Table[i1], a.Table[i1-1]);
            }
            else if(stod(a.Table[i1][col]) < stod(a.Table[i1-1][col]))
                swap(a.Table[i1], a.Table[i1-1]);
        }
    }
    
    if(to_low == true)
        tolow(a, a.Table.size());
}

/**
 * \brief find a pivot point in a[] array on interval from a[start] to a[pivot]
 * \param a a[] array
 * \param start begins from a[start]
 * \param pivot a[pivot] is a pivot of a[] array
 * \param col is column of a.Table
 * \return pivot point sorted piece of a[] array
 */
uint64_t partition(dualtype& a, const uint64_t& start, uint64_t pivot, const uint16_t& col)
{
    uint64_t i = start;
    while(i < pivot)
    {
        if(a.str_or_int == true)
        {
            if(a.Table[i][col] > a.Table[pivot][col] && i == pivot-1)
            {
                swap(a.Table[i], a.Table[pivot]);
                pivot--;
            }
            else if(a.Table[i][col] > a.Table[pivot][col])
            {
                swap(a.Table[pivot - 1], a.Table[pivot]);
                swap(a.Table[i], a.Table[pivot]);
                pivot--;
            }
		
            else i++;
        }
        else
        {
            if(stod(a.Table[i][col]) > stod(a.Table[pivot][col]) && i == pivot-1)
            {
                swap(a.Table[i], a.Table[pivot]);
                pivot--;
            }
		    
            else if(stod(a.Table[i][col]) > stod(a.Table[pivot][col]))
            {
                swap(a.Table[pivot - 1], a.Table[pivot]);
                swap(a.Table[i], a.Table[pivot]);
                pivot--;
            }
		    
            else i++;
        }
    }
    return pivot;
}

void q_sort_r(dualtype& a, const uint64_t& start, const uint64_t end, const uint16_t& col)
{
    if(start < end)
    {
        const uint64_t pivot = partition(a, start, end, col);
		
        q_sort_r(a, start, pivot - 1, col);
        q_sort_r(a, pivot + 1, end, col);
    }
}

void q_sort(dualtype& a, const uint16_t& col, const bool& to_low)
{
    q_sort_r(a, 1, a.Table.size()-1, col);
    
    if(to_low == true)
        tolow(a, a.Table.size());
}

void merge_sort_r(dualtype& a, const uint16_t fst, const uint16_t lst, const uint16_t& col) {
    const uint16_t mid = (fst + lst) / 2;
    uint16_t start = fst;
    uint16_t fin = mid + 1;
    auto* buf = new std::vector<std::string>[lst + 1];

    for (uint16_t i = fst; i <= lst; i++) {
        if (start <= mid && (fin > lst || stod(a.Table[start][col]) < stod(a.Table[fin][col]))) {
            buf[i] = a.Table[start];
            start++;
        }
        else {
            buf[i] = a.Table[fin];
            fin++;
        }
    }
    for (int i = fst; i <= lst; i++) a.Table[i] = buf[i];

    delete[] buf;

}

void merge_r(dualtype& arr, const uint16_t first, const uint16_t last, const uint16_t& col) {
    if (first < last) {
        merge_r(arr, first, (first + last) / 2, col);
        merge_r(arr, (first + last) / 2 + 1, last, col);
        merge_sort_r(arr, first, last, col);
    }
}

void merge_sort(dualtype& a, const uint16_t& col, const bool& to_low)
{
    merge_r(a, col, static_cast<uint16_t>(a.Table.size())-1, col);
    if(to_low == true)
        tolow(a, a.Table.size());
}

void shell_sort(dualtype& a, const uint16_t& col, const bool& to_low)
{
    auto range = static_cast<double>(a.Table.size());
    constexpr double factor = 1.2473309;
    if(a.is_Str_read == true)
    {
        while(true)
        {
            for(uint64_t i = 1, j = static_cast<uint64_t>(range)-1; j-i > 0 && j <= a.Table.size(); ++i, ++j)
            {
                if(a.Table[i][col] > a.Table[j][col])
                    swap(a.Table[i], a.Table[j]);
            }

            if(range <= 2)
                break;
            
            range /= factor;
        }
    }
    else
    {
        while(true)
        {
            for(uint64_t i = 1, j = static_cast<uint64_t>(range)-1; j-i >= 1 && j < a.Table.size() && j > i; ++i, ++j)
            {
                if(stod(a.Table[i][col]) > stod(a.Table[j][col]))
                    swap(a.Table[i], a.Table[j]);
            }

            if(range <= 1)
                break;
        
            range /= factor;
        }
    }
    
    if(to_low == true)
        tolow(a, a.Table.size());
}

// ReSharper disable once IdentifierTypo
/**
 * \brief make a heap(binary tree) from a[n] array
 * \param a a[n] array
 * \param first first
 * \param last last
 * \param col column of sort
 */
void heapify(dualtype& a, uint64_t first, const uint64_t last, const uint16_t& col)
{
    uint64_t largest;
    bool f_done = false;

    while (first * 2 <= last && !f_done) {
        if (first * 2 == last || stod(a.Table[first * 2][col]) > stod(a.Table[first * 2 + 1][col]))
            largest = first * 2;
        else
            largest = first * 2 + 1;

        if (stod(a.Table[first][col]) < stod(a.Table[largest][col])) {
            swap(a.Table[first], a.Table[largest]);
            first = largest;
        }
        else f_done = true;
    }
}

void heap_sort(dualtype& a, const uint16_t& col, const bool& to_low)
{
    for (uint64_t i = a.Table.size() / 2; i >= 1; --i)
        heapify(a, i, a.Table.size() - 1, col);
    
    for (uint64_t i = a.Table.size() - 1; i >= 2; --i) {
        swap(a.Table[1], a.Table[i]);
        heapify(a, 1, i - 1, col);
    }
    
    if(to_low == true)
        tolow(a, a.Table.size());
}

void literal_sort(dualtype& a, const uint16_t& col, const bool& to_low)
{
    a.is_Str_read = true;
    // ReSharper disable once CommentTypo
    shell_sort(a, col, to_low);  // NOLINT(clang-diagnostic-cast-qual, clang-diagnostic-cast-align, performance-no-int-to-ptr, clang-diagnostic-int-to-pointer-cast)
    a.is_Str_read = false;
}