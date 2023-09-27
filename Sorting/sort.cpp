#include "sort.h"
#include "struct.h"

// ReSharper disable once IdentifierTypo
void tolow(const dualtype& a, const int& num)
{
    auto* temp = new int[num];
    for(int i = 0; i < num; ++i)
        temp[num - i-1] = a.Int[i];
    for(int i = 0; i < num; ++i)
        a.Int[i] = temp[i];

    if(a.is_Str_read)
    {
        auto* temp_str = new std::string[num];
        for(int i = 0; i < num; ++i)
            temp_str[num - i-1] = a.Str[i];
        for(int i = 0; i < num; ++i)
            a.Str[i] = temp_str[i];
    }
}

void bubble_sort(const dualtype& a, const int& num, const bool& to_low)
{
    bool swapped = false;
    auto num_t = num;
    
    while (true)
    {
        for(int i = 0; i < num_t - 1; ++i)
        {
            if(a.Int[i] > a.Int[i+1])
            {
                swap(a.Int[i], a.Int[i+1]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
        --num_t;
        swapped = false;
    }
    
    if(to_low == true)
        tolow(a, num);
}

void selection_sort(const dualtype& a, const int& num, const bool& to_low)
{
    int index = 0;
    for(int i = 0; i < num - 1; ++i)
    {
        for(int i1 = i; i1 < num; ++i1)
        {
            if(a.Int[i1] < a.Int[index])
                index = i1;
        }
        swap(a.Int[i], a.Int[index]);
    }
    
    if(to_low == true)
        tolow(a, num);
}

void insertion_sort(const dualtype& a, const int& num, const bool& to_low)
{
    for(int i = 1; i < num; ++i)
    {
        for(int i1 = i; i1 > 0; --i1)
        {
            if(a.Int[i1] < a.Int[i1-1])
                swap(a.Int[i1], a.Int[i1-1]);
        }
    }
    
    if(to_low == true)
        tolow(a, num);
}

/**
 * \brief find a pivot point in a[] array on interval from a[start] to a[pivot]
 * \param a a[] array
 * \param start begins from a[start]
 * \param pivot a[pivot] is a pivot of a[] array
 * \return pivot point sorted piece of a[] array
 */
int partition(const dualtype& a, const int& start, int pivot)
{
    int i = start;
    while(i < pivot)
    {
        if(a.Int[i] > a.Int[pivot] && i == pivot-1)
        {
            swap(a.Int[i], a.Int[pivot]);
            pivot--;
        }
		
        else if(a.Int[i] > a.Int[pivot])
        {
            swap(a.Int[pivot - 1], a.Int[pivot]);
            swap(a.Int[i], a.Int[pivot]);
            pivot--;
        }
		
        else i++;
    }
    return pivot;
}

void q_sort_r(const dualtype& a, const int& start, const int end)
{
    if(start < end)
    {
        const int pivot = partition(a, start, end);
		
        q_sort_r(a, start, pivot - 1);
        q_sort_r(a, pivot + 1, end);
    }
}

void q_sort(const dualtype& a, const int& num, const bool& to_low)
{
    q_sort_r(a, 0, num-1);
    
    if(to_low == true)
        tolow(a, num);
}

void merge_sort_r(const dualtype& a, const int lo, const int hi)
{
    if(hi <= lo)
        return;
    const int mid = lo + (hi - lo) / 2;
    merge_sort_r(a, lo, mid);
    merge_sort_r(a, mid+1, hi);
}


void merge_sort(const dualtype& a, const int& num, const bool& to_low)
{
    merge_sort_r(a, 0, num);
    
    if(to_low == true)
        tolow(a, num);
}

void shell_sort(const dualtype& a, const int& num, const bool& to_low)
{
    double range = num;
    if(a.is_Str_read == true)
    {
        while(true)
        {
            constexpr double factor = 1.2473309;
            
            for(int i = 0, j = static_cast<int>(range)-1; j-i >= 1 && j < num; ++i, ++j)
            {
                if(a.Str[i] > a.Str[j])
                    swap(a.Str[i], a.Str[j]);
            }
            
            if(range <= 1)
                break;
            
            range /= factor;
        }
    }
    else
    {
        while(true)
        {
            constexpr double factor = 1.2473309;
            
            for(int i = 0, j = static_cast<int>(range)-1; j-i >= 1 && j < num; ++i, ++j)
            {
                if(a.Int[i] > a.Int[j])
                    swap(a.Int[i], a.Int[j]);
            }
            
            if(range <= 1)
            break;
            
            range /= factor;
        }
    }
    
    if(to_low == true)
        tolow(a, num);
}

// ReSharper disable once IdentifierTypo
/**
 * \brief make a heap(binary tree) from a[n] array
 * \param a a[n] array
 * \param n number of array elements
 * \param i largest element of array
 */
void heapify(const dualtype& a, const int n, const int i)
{
    int largest = i;
    
    if(const int l = 2*i + 1; l < n && a.Int[l] > a.Int[largest])
        largest = l;
    
    if(const int r = 2*i + 2; r < n && a.Int[r] > a.Int[largest])
        largest = r;

    if(largest != i)
    {
        swap(a.Int[largest], a.Int[i]);
        heapify(a, n, largest);
    }
}

void heap_sort(const dualtype& a, const int& num, const bool& to_low)
{
    for(int i = num/2 - 1; i >= 0; --i)
        heapify(a, num, i);

    for(int i = num-1; i>= 0; --i)
    {
        swap(a.Int[0], a.Int[i]);
        heapify(a, i, 0);
    }
    
    if(to_low == true)
        tolow(a, num);
}

void literal_sort(const dualtype& a, const int& num, const bool& to_low)
{
    // a.is_Str_read = true;
    // ReSharper disable once CommentTypo
    shell_sort(a, num, to_low);  // NOLINT(clang-diagnostic-cast-qual, clang-diagnostic-cast-align, performance-no-int-to-ptr, clang-diagnostic-int-to-pointer-cast)
    // a.is_Str_read = false;
    a.is_Str = true;
}