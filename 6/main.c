// The maximum sum subarray problem
// consists in finding the maximum sum of a contiguous
// subsequence in an array or list of integers:

// maxSequence({-2, 1, -3, 4, -1, 2, 1, -5, 4}, 9)
// // should return 6, from sub-array: {4, -1, 2, 1}
// Easy case is when the list is made up of only positive numbers
// and the maximum sum is the sum of the whole array.
// If the list is made up of only negative numbers, return 0 instead.

// Empty list is considered to have zero greatest sum.
// Note that the empty list or array is also a valid sublist/subarray.
#include <stddef.h>
#include <stdio.h>

//My solution ~O(n^2)
int maxSequence(const int *array, size_t n)
{
    int i = 0, next_max = 0, max = 0, positive = 0, counter = 0, buf = 0;

    while (buf < n)
    {
        positive = 0;
        next_max = 0;
        counter = 0;
        for (i = buf; array[i] <= 0; ++i)
            ;
        for (; i < n; ++i)
        {
            if (array[i] > 0)
                positive += array[i];
            if (array[i] < 0)
                break;
        }
        for (; array[i] <= 0; ++i)
        {
            counter += array[i];
            if (counter > next_max)
                next_max = counter;
        }
        buf = i;
        for (; i < n; ++i)
        {
            counter += array[i];
            if (counter > next_max)
                next_max = counter;
        }
        if (positive + next_max > max)
            max = positive + next_max;
    }
    return max;
}

//Best soulution O(n)
int maxSequence2(const int *array, size_t n)
{
    int max_so_far = 0;
    int max_ending_here = 0;
    for (int i = 0; i < n; i++)
    {
        max_ending_here += array[i];
        if (max_ending_here < 0)
            max_ending_here = 0;
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}

int main()
{
    const int array[] = {2, -1, 2, -1, 2, -1, 2, -1, 2};
    fprintf(stdout, "%d", maxSequence2(array, 9));

    return 0;
}