#include "sort.h"

void swap(int& a, int& b) noexcept
{
    const int temp = b;
    b = a;
    a = temp;
}

void bubble_sort(int* a, int num)
{
    bool swapped = false;

    while (true)
    {
        for(int i = 0; i < num - 1; ++i)
        {
            if(a[i] > a[i+1])
            {
                swap(a[i], a[i+1]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
        --num;
        swapped = false;
    }
}

void selection_sort(int* a, const int num)
{
    int index = 0;
    for(int i = 0; i < num - 1; ++i)
    {
        for(int i1 = i; i1 < num; ++i1)
        {
            if(a[i1] < a[index])
                index = i1;
        }
        swap(a[i], a[index]);
    }
}

void insertion_sort(int* a, const int num)
{
    for(int i = 1; i < num; ++i)
    {
        for(int i1 = i; i1 > 0; --i1)
        {
            if(a[i1] < a[i1-1])
                swap(a[i1], a[i1-1]);
        }
    }
}

/**
 * \brief find a pivot point in a[] array on interval from a[start] to a[pivot]
 * \param a a[] array
 * \param start begins from a[start]
 * \param pivot a[pivot] is a pivot of a[] array
 * \return pivot point sorted piece of a[] array
 */
int partition(int* a, const int start, int pivot)
{
    int i = start;
    while(i < pivot)
    {
        if(a[i] > a[pivot] && i == pivot-1)
        {
            swap(a[i], a[pivot]);
            pivot--;
        }
		
        else if(a[i] > a[pivot])
        {
            swap(a[pivot - 1], a[pivot]);
            swap(a[i], a[pivot]);
            pivot--;
        }
		
        else i++;
    }
    return pivot;
}

void q_sort_r(int* a, const int start, const int end)
{
    if(start < end)
    {
        const int pivot = partition(a, start, end);
		
        q_sort_r(a, start, pivot - 1);
        q_sort_r(a, pivot + 1, end);
    }
}

void q_sort(int* a, const int num)
{
    q_sort_r(a, 0, num-1);
}

void merge_sort_r(int* a, const int lo, const int hi)
{
    if(hi <= lo)
        return;
    const int mid = lo + (hi - lo) / 2;
    merge_sort_r(a, lo, mid);
    merge_sort_r(a, mid+1, hi);
}


void merge_sort(int* a, const int num)
{
    merge_sort_r(a, 0, num);
}

void shell_sort(int* a, const int num)
{
    double range = num;
    
    while(true)
    {
        constexpr double factor = 1.2473309;
        
        for(int i = 0, j = static_cast<int>(range)-1; j-i >= 1 && j < num; ++i, ++j)
        {
            if(a[i] > a[j])
                swap(a[i], a[j]);
        }
        
        if(range <= 1)
        break;
        
        range /= factor;
    }
}

// ReSharper disable once IdentifierTypo
/**
 * \brief make a heap(binary tree) from a[n] array
 * \param a a[n] array
 * \param n number of array elements
 * \param i largest element of array
 */
void heapify(int* a, const int n, const int i)
{
    int largest = i;
    
    if(const int l = 2*i + 1; l < n && a[l] > a[largest])
        largest = l;
    
    if(const int r = 2*i + 2; r < n && a[r] > a[largest])
        largest = r;

    if(largest != i)
    {
        swap(a[largest], a[i]);
        heapify(a, n, largest);
    }
}

void heap_sort(int* a, const int num)
{
    for(int i = num/2 - 1; i >= 0; --i)
        heapify(a, num, i);

    for(int i = num-1; i>= 0; --i)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void literal_sort(const std::string* a, const int num)
{
    // ReSharper disable once CppCStyleCast
    // ReSharper disable once CommentTypo
    shell_sort((int*)a->at(0), num);  // NOLINT(clang-diagnostic-cast-qual, clang-diagnostic-cast-align, performance-no-int-to-ptr, clang-diagnostic-int-to-pointer-cast)
    // for(int i = 0; i < num; ++i)
    // {
    //     
    // }
    
}