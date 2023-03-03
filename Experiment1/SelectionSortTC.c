#include <stdio.h>
#include <time.h>
#include <stdlib.h>
// function to swap the the position of two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {

 
      if (array[i] < array[min_idx])
        min_idx = i;
    }


    swap(&array[min_idx], &array[step]);
  }
}

// function to print an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
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
    // data[i] = rand();
    //worstcase
    data[i] = 15000-i;
  }
  start = clock();
  selectionSort(data, 15000);
  end = clock();
  total = ((double)(end - start));
  printf("the time taken is: %lf",total);


}