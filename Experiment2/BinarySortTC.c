#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int binarySearch(int a[], int item, int low, int high)
{
    if (high <= low)
        return (item > a[low])?  (low + 1): low;
 
    int mid = (low + high)/2;
 
    if(item == a[mid])
        return mid+1;
 
    if(item > a[mid])
        return binarySearch(a, item, mid+1, high);
    return binarySearch(a, item, low, mid-1);
}
 
// Function to sort an array a[] of size \'n\'
void binarySort(int a[], int n)
{
    int i, loc, j, selected;
 
    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];
 
        // find location where selected should be inserted
        loc = binarySearch(a, selected, 0, j);
 
        // Move all elements after location to create space
        while (j >= loc)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = selected;
    }
}
// driver code
int main()
{
    int data[15000], i;
    clock_t start, end;
    double total;
    for (i = 0; i < 15000; i++)
    {
        // best case
        //  data[i] = i;
        // average case
        data[i] = rand();
        // worstcase
        //  data[i] = 15000-i;
    }
    start = clock();
    binarySort(data,15000);

    end = clock();
    total = ((double)(end - start));
    printf("the time taken is: %lf", total);
}