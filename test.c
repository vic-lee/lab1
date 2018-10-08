
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * 1. get length of the array
 * 2. if even -> divide into 2 arrays
 * 3. if odd -> divide into 2 arrays & number in the middle
 * 4. if length of subarray > 2 -> repeat
 * 5. else (len=2), compare and swap
 */

void merge(int arr[], int l, int m, int r)
{
  /**
   * 1. create left and right arrays
   * 2. copy data into left and right arrays
   * 3. merge into original array, in sequence of decreasing size
   */
  int leftsize = m - l + 1;
  int rightsize = r - m;
  int L[leftsize], R[rightsize];
  for (int i = 0; i < leftsize; i++)  L[i] = arr[l + i];
  for (int j = 0; j < rightsize; j++) R[j] = arr[m + 1 + j];
  int l_idx = 0, r_idx = 0, a_idx = l;
  while (l_idx < leftsize && r_idx < rightsize)
  {
    /**
     * for each increment in the original array,
     * the slot takes in the larger value in either array
     */
    if (L[l_idx] >= R[r_idx])
    {
      arr[a_idx] = L[l_idx];
      l_idx++;
    }
    else 
    {
      arr[a_idx] = R[r_idx];
      r_idx++;
    }
    a_idx++;
  }

  /**
   * For the remaining values in either left or right array, 
   * add them to the original array sequentially
   */
  while (l_idx < leftsize)
  {
    arr[a_idx] = L[l_idx];
    l_idx++;
    a_idx++;
  }
  while(r_idx < rightsize) 
  {
    arr[a_idx] = R[r_idx];
    r_idx++;
    a_idx++;
  }
}

void mergeSort(int arr[], int l, int r)
{
  if (l < r)
  {
    int m = (l + r) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

void printArray(int A[], int size)
{
  for (int i = 0; i < size; i++) printf("%d ", A[i]);
  printf("\n");
}

int main(int argc, char *argv[])
{
  int NUM[] = {1, 2, 3, 4, 7, 8, 31, 36, 4, 2456, 55, 7};
  int LEN = 12;
  printArray(NUM, LEN);
  mergeSort(NUM, 0, LEN - 1);
  printArray(NUM, LEN);
  return 0;
}
