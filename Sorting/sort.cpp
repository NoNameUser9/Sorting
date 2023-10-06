#include "sort.h"
#include "struct.h"

// ReSharper disable once IdentifierTypo
void tolow(dualtype& a, const uint64_t& num)
{
    auto* temp = new std::vector<std::string>[num];
    for(uint64_t i = 1; i < num; ++i)
        temp[num - i-1] = a.Table[i];
    for(uint64_t i = 1; i < num; ++i)
        a.Table[i] = temp[i];
    //
    // if(a.is_Str_read)
    // {
    //     auto* temp_str = new std::string[num];
    //     for(int i = 1; i < num; ++i)
    //         temp_str[num - i-1] = a.Table[i];
    //     for(int i = 1; i < num; ++i)
    //         a.Table[i] = temp_str[i];
    // }
}

void bubble_sort(dualtype& a, const uint64_t& col, const bool& to_low)
{
    bool swapped = false;
    auto num_t = a.Table.size();
    
    while (true)
    {
        for(uint64_t i = 1; i < num_t - 1; ++i)
        {
            if(a.Table[i][col] > a.Table[i+1][col])
            {
                swap(a.Table[i], a.Table[i+1]);
                swapped = true;
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

void selection_sort(dualtype& a, const uint64_t& col, const bool& to_low)
{
    uint64_t index = 0;
    for(uint64_t i = 1; i < a.Table.size() - 1; ++i)
    {
        for(uint64_t i1 = i; i1 < a.Table.size(); ++i1)
        {
            if(a.Table[i1][col] < a.Table[index][col])
                index = i1;
        }
        swap(a.Table[i], a.Table[index]);
    }
    
    if(to_low == true)
        tolow(a, a.Table.size());
}

void insertion_sort(dualtype& a, const uint64_t& col, const bool& to_low)
{
    for(uint64_t i = 1; i < a.Table.size(); ++i)
    {
        for(uint64_t i1 = i; i1 > 0; --i1)
        {
            if(a.Table[i1][col] < a.Table[i1-1][col])
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
uint64_t partition(dualtype& a, const uint64_t& start, uint64_t pivot, const uint64_t& col)
{
    uint64_t i = start;
    while(i < pivot)
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
    return pivot;
}

void q_sort_r(dualtype& a, const uint64_t& start, const uint64_t end, const uint64_t& col)
{
    if(start < end)
    {
        const uint64_t pivot = partition(a, start, end, col);
		
        q_sort_r(a, start, pivot - 1, col);
        q_sort_r(a, pivot + 1, end, col);
    }
}

void q_sort(dualtype& a, const uint64_t& col, const bool& to_low)
{
    q_sort_r(a, 1, a.Table.size()-1, col);
    
    if(to_low == true)
        tolow(a, a.Table.size());
}

// ReSharper disable CommentTypo
// void merge_sort_r(dualtype& a, const int num)
// {
//     if (num < 2)return;
//     merge_sort_r(a, num / 2);
//     merge_sort_r(&a[num / 2], num - (num / 2));
//     const auto buf = new int[num];
//     // ReSharper disable once IdentifierTypo
//     int idbuf = 0, idl = 0, idr = num / 2 ;
//     while ((idl < num / 2) && (idr < num))
//         if (a[idl] < a[idr]) 
//             buf[idbuf++] = a[idl++];
//         else
//             buf[idbuf++] = a[idr++];
//     while (idl < num / 2) buf[idbuf++] = a[idl++];
//     while (idr < num) buf[idbuf++] = a[idr++];
//     for (idl = 0; idl < num; idl++)a[idl] = buf[idl];
//     delete[]buf;
// }
// ReSharper restore CommentTypo


void merge_sort(dualtype& a, const uint64_t& col, const bool& to_low)
{
    // merge_sort_r(a, col);
    if(to_low == true)
        tolow(a, a.Table.size());
}

void shell_sort(dualtype& a, const uint64_t& col, const bool& to_low)
{
    if(a.is_Str_read == true)
    {
        auto range = static_cast<double>(a.Table.size());
        while(true)
        {
            constexpr double factor = 1.2473309;
            
            for(uint64_t i = 1, j = static_cast<uint64_t>(range)-1; j-i >= 1 && j < a.Table.size() && j > i; ++i, ++j)
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
        auto range = static_cast<double>(a.Table.size());
        while(true)
        {
            constexpr double factor = 1.2473309;
            
            for(uint64_t i = 1, j = static_cast<uint64_t>(range)-1; j-i >= 1 && j < a.Table.size() && j > i; ++i, ++j)
            {
                if(stoi(a.Table[i][col]) > stoi(a.Table[j][col]))
                    swap(a.Table[i], a.Table[j]);
            }

            if(range <= 2)
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
 * \param n number of array elements
 * \param i largest element of array
 */
void heapify(dualtype& a, const uint64_t n, const uint64_t i)
{
    uint64_t largest = i;
    
    if(const uint64_t l = 2*i + 1; l < n && a.Table[l] > a.Table[largest])
        largest = l;
    
    if(const uint64_t r = 2*i + 2; r < n && a.Table[r] > a.Table[largest])
        largest = r;

    if(largest != i)
    {
        swap(a.Table[largest], a.Table[i]);
        heapify(a, n, largest);
    }
}

void heap_sort(dualtype& a, const uint64_t& col, const bool& to_low)
{
    for(uint64_t i = a.Table.size()/2 - 1; i > 0; --i)
        heapify(a, a.Table.size(), i);

    for(uint64_t i = a.Table.size()-1; i> 0; --i)
    {
        swap(a.Table[0], a.Table[i]);
        heapify(a, i, 0);
    }
    
    if(to_low == true)
        tolow(a, a.Table.size());
}

void literal_sort(dualtype& a, const uint64_t& col, const bool& to_low)
{
    a.is_Str_read = true;
    // ReSharper disable once CommentTypo
    shell_sort(a, col, to_low);  // NOLINT(clang-diagnostic-cast-qual, clang-diagnostic-cast-align, performance-no-int-to-ptr, clang-diagnostic-int-to-pointer-cast)
    a.is_Str_read = false;
    a.is_Str = true;
}