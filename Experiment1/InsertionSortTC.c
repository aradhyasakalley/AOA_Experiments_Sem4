#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
// driver code
int main() {
  int data[15000],i; 
  clock_t start,end;
  double total;
  for (i=0;i<15000;i++){
    //best case
    // data[i] = i;
    //average case
    data[i] = rand();
    //worstcase
    // data[i] = 15000-i;
  }
  start = clock();
  insertionSort(data, 15000);
  end = clock();
  total = ((double)(end - start));
  printf("the time taken is: %lf",total);


}