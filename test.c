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
int is_same_line(int p, int nbp)
{
  return ((nbp - 1) / 3) == ((p - 1) / 3);
}
int is_line_before(int p, int nbp)
{
  return ((nbp - 1) / 3) + 1 == ((p - 1) / 3);

}
int is_line_after(int p, int nbp)
{
  // printf("neighbour %d line number is %d\n", nbp, nbp / 3);
  // printf("cell %d line number is %d\n", p, p / 3);
  return ((nbp - 1) / 3) - 1 == ((p - 1) / 3);

}
int check_nb(char nb[], int p, int nbp)
{
  // if (within_bounds(p) && p % 3 == cond)
  //   return 1;
  if ( strcmp(nb, "T") == 0 || strcmp(nb, "B") == 0 )
  {
    /** 
     * as long as top or bottom index is within bounds, 
     * top or bottom neighbour exists. 
     */
    return within_bounds(nbp);
  }
  else if ( strcmp(nb, "L") == 0 || strcmp(nb, "R") == 0 )
  {
    /**
     * as long as left or right index is within bounds 
     * and is on the same line as the original index, 
     * left or right neighbour exists.
     */
    return within_bounds(nbp) && is_same_line(p, nbp);
  }
  else if ( strcmp(nb, "TL") == 0 || strcmp(nb, "TR") == 0 )
  {
    /** 
     * as long as top left or top right index is within
     * bounds and is on the line before the original 
     * index, top left or top right neighbour exists.
     */
    return within_bounds(nbp) && is_line_before(p, nbp);
  }
  else if ( strcmp(nb, "BL") == 0 || strcmp(nb, "BR") == 0 )
  {
    /** 
     * as long as bottom left or bottom right index 
     * is within bounds and is on the line after the 
     * original index, bottom left or bottom right 
     * neighbour exists.
     */
    return within_bounds(nbp) && is_line_after(p, nbp);
  }
  return 0;
}

int get_nb_idx(char nb[], int p)
{
  int RIGHT_NB_IDX = p + 1;
  int TOP_RIGHT_NB_IDX = p - 2;
  int BTM_RIGHT_NB_IDX = p + 4;
  int LEFT_NB_IDX = p - 1;
  int TOP_LEFT_NB_IDX = p - 4;
  int BTM_LEFT_NB_IDX = p + 2;
  int TOP_NB_IDX = p - 3;
  int BTM_NB_IDX = p + 3;
  
  if (strcmp(nb, "R") == 0)
    return RIGHT_NB_IDX;
  else if (strcmp(nb, "TR") == 0)
    return TOP_RIGHT_NB_IDX;
  else if (strcmp(nb, "BR") == 0)
    return BTM_RIGHT_NB_IDX;
  else if (strcmp(nb, "L") == 0)
    return LEFT_NB_IDX;
  else if (strcmp(nb, "TL") == 0)
    return TOP_LEFT_NB_IDX;
  else if (strcmp(nb, "BL") == 0)
    return BTM_LEFT_NB_IDX;
  else if (strcmp(nb, "T") == 0)
    return TOP_NB_IDX;
  else if (strcmp(nb, "B") == 0)
    return BTM_NB_IDX;
  return -1; //fallback
}

int has_nb(char nb[], int p)
{
  // int RIGHT_NB_CONDITION = 0;
  // int TOP_RIGHT_NB_CONDITION = 0;
  // int BTM_RIGHT_NB_CONDITION = 0;
  // int LEFT_NB_CONDITION = 1;
  // int TOP_LEFT_NB_CONDITION = 1;
  // int BTM_LEFT_NB_CONDITION = 1;
  // int TOP_NB_CONDITION = 2;
  // int BTM_NB_CONDITION = 2;

  int RIGHT_NB_IDX = p + 1;
  int TOP_RIGHT_NB_IDX = p - 2;
  int BTM_RIGHT_NB_IDX = p + 4;
  int LEFT_NB_IDX = p - 1;
  int TOP_LEFT_NB_IDX = p - 4;
  int BTM_LEFT_NB_IDX = p + 2;
  int TOP_NB_IDX = p - 3;
  int BTM_NB_IDX = p + 3;

  if (strcmp(nb, "R") == 0)
    return check_nb("R", p, RIGHT_NB_IDX);
  else if (strcmp(nb, "TR") == 0)
    return check_nb("TR", p, TOP_RIGHT_NB_IDX);
  else if (strcmp(nb, "BR") == 0)
    return check_nb("BR", p, BTM_RIGHT_NB_IDX);
  else if (strcmp(nb, "L") == 0)
    return check_nb("L", p, LEFT_NB_IDX);
  else if (strcmp(nb, "TL") == 0)
    return check_nb("TL", p, TOP_LEFT_NB_IDX);
  else if (strcmp(nb, "BL") == 0)
    return check_nb("BL", p, BTM_LEFT_NB_IDX);
  else if (strcmp(nb, "T") == 0)
    return check_nb("T", p, TOP_NB_IDX);
  else if (strcmp(nb, "B") == 0)
    return check_nb("B", p, BTM_NB_IDX);
  return 0; //fallback
}

int is_nb_one(int arr[], char nb[], int p)
{
  int n = arr[get_nb_idx(nb, p) - 1];
  printf("%s\t neighbour at index %d is %d\n", nb, p, n);
  if (n == 1)
    return 1;
  return 0;
}

int check_all_nbs(int arr[], int p) 
{
  /** 
   * Check all neighbours
   * if has neighbour, see what neighbour is
   * count 1s
   * if num1 == 2 || 3, return 1
   * else return 0
   */
  int one_counter = 0;

  if (has_nb("R", p))
    one_counter += is_nb_one(arr, "R", p);
  if (has_nb("TR", p))
    one_counter += is_nb_one(arr, "TR", p);
  if (has_nb("BR", p))
    one_counter += is_nb_one(arr, "BR", p);
  if (has_nb("L", p))
    one_counter += is_nb_one(arr, "L", p);
  if (has_nb("TL", p))
    one_counter += is_nb_one(arr, "TL", p);
  if (has_nb("BL", p))
    one_counter += is_nb_one(arr, "BL", p);
  if (has_nb("T", p))
    one_counter += is_nb_one(arr, "T", p);
  if (has_nb("B", p))
    one_counter += is_nb_one(arr, "B", p);
  
  printf("one counter is %d\n", one_counter);

  if (one_counter == 2 || one_counter == 3)
    return 1;

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

void print_matrix(int A[])
{
  for (int i = 0; i < 9; i++) 
  {
    printf("%d ", A[i]);
    if ((i + 1) % 3 == 0)
      printf("\n");
  }
  // printf("\n");
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
  char FILENAME[] = "testf3.in";

  int mtx[MATRIX_SIZE], newmtx[MATRIX_SIZE];

  file_to_arr(FILENAME, mtx);

  // printf("has neighbour %s at index %d: %d\n", "B", 1, has_nb("B", 1));

  // int checknum = 9;
  // printf("is one counter for cell '%d' 2 or 3? %d\n", checknum, check_all_nbs(mtx, checknum));

  for (int i=0; i<9; i++)
    newmtx[i] = check_all_nbs(mtx, i+1);

  print_matrix(newmtx);


  return 0;
}
