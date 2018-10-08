#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int within_bounds(int p)
{
  int MIN = 1, MAX = 9;
  if (p >= MIN && p <= MAX)
    return 1;
  return 0;
}

int has_nb(int p, int cond)
{
  if (within_bounds(p) && p % 3 == cond)
    return 1;
  return 0;
}

int check_nb(char nb[], int p)
{
  int RIGHT_NB_CONDITION = 0;
  int TOP_RIGHT_NB_CONDITION = 0;
  int BTM_RIGHT_NB_CONDITION = 0;
  int LEFT_NB_CONDITION = 1;
  int TOP_LEFT_NB_CONDITION = 1;
  int BTM_LEFT_NB_CONDITION = 1;
  int TOP_NB_CONDITION = 2;
  int BTM_NB_CONDITION = 2;

  int RIGHT_NB_IDX = p + 1;
  int TOP_RIGHT_NB_IDX = p - 2;
  int BTM_RIGHT_NB_IDX = p + 4;
  int LEFT_NB_IDX = p - 1;
  int TOP_LEFT_NB_IDX = p - 4;
  int BTM_LEFT_NB_IDX = p + 2;
  int TOP_NB_IDX = p - 3;
  int BTM_NB_IDX = p - 3;

  if (strcmp(nb, "R") == 0)
    return has_nb(RIGHT_NB_IDX, RIGHT_NB_CONDITION);
  else if (strcmp(nb, "TR") == 0)
    return has_nb(TOP_RIGHT_NB_IDX, TOP_RIGHT_NB_CONDITION);
  else if (strcmp(nb, "BR") == 0)
    return has_nb(BTM_RIGHT_NB_IDX, BTM_RIGHT_NB_CONDITION);
  else if (strcmp(nb, "L") == 0)
    return has_nb(LEFT_NB_IDX, LEFT_NB_CONDITION);
  else if (strcmp(nb, "TL") == 0)
    return has_nb(TOP_LEFT_NB_IDX, TOP_LEFT_NB_CONDITION);
  else if (strcmp(nb, "BL") == 0)
    return has_nb(BTM_LEFT_NB_IDX, BTM_LEFT_NB_CONDITION);
  else if (strcmp(nb, "T") == 0)
    return has_nb(TOP_NB_IDX, TOP_NB_CONDITION);
  else if (strcmp(nb, "B") == 0)
    return has_nb(BTM_NB_IDX, BTM_NB_CONDITION);
  return 0; //fallback
}

int check_all_nbs(int p) 
{
  /** 
   * Check all neighbours
   * if has neighbour, see what neighbour is
   * count 1s
   * if num1 == 2 || 3, return 1
   * else return 0
   */
  return 0;
}

void file_to_arr(char* filename, int arr[])
{
  FILE* fp = fopen(filename, "r");
  int i=0;
  int num;
  while(fscanf(fp, "%d", &num) > 0) {
      arr[i] = num;
      i++;
  }
  fclose(fp);
}

void print_arr(int A[], int size)
{
  for (int i = 0; i < size; i++) printf("%d ", A[i]);
  printf("\n");
}

int main(int argc, char *argv[])
{
  /** 
   * 1. for each cell
   * 2. check each of its neighbour 
   *    1. if neighbour exists, check if it is 1
   * 3. if total1 == 2 or total1 == 3,  cell = 1
   * 4. else,                           cell = 0
   */

  /*     assume index in + 1 form    */

  // char FNAME[] = "testf3.in";
  // int GEN = 1;
  // int p = 5;
  // bool has_right_nb = ((p % 3) == 0);
  
  int MATRIX_SIZE = 9;

  int nums[MATRIX_SIZE];
  file_to_arr("testf3.in", nums);
  

  printf("%d", check_nb("T", 3));

  return 0;
}
