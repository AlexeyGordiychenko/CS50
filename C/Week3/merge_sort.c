#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printArray(int arr[], int size);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int p, int q, int r);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc < 3)
    {
        printf("Usage: ./merge_sort filename\n");
        return 1;
    }

    int listsize = atoi(argv[2]);
    string listname = argv[1];

    // open correct file
    char filename[9];
    sprintf(filename, "%s%i.txt", listname, listsize);
    FILE *listfile = fopen(filename, "r");
    if (listfile == NULL)
    {
        printf("Error opening file %s.\n", filename);
        return 1;
    }

    // load file into an array of size
    int unsorted_array[listsize];

    for (int i = 0; i < listsize; i++)
    {
        fscanf(listfile, "%d", &unsorted_array[i]);
    }

    mergeSort(unsorted_array, 0, listsize - 1);
    printArray(unsorted_array, listsize);
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%i\n ", arr[i]);
    //printf("\n");
}
