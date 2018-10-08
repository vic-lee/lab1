
/*
 * IMPORTANT: WRITE YOUR NAME AND NetID BELOW.
 * 
 * Last Name: Lee
 * First Name: Vic
 * Netid: sl5450
 * 
 * You will do your project in this file only.
 * Do not change function delarations. However, feel free to add new functions if you want.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Function declarations: do not change that, but you may add your own functions */
void f1(int, int, int);
void f2(char *);
void f3(char *, int);
void f4(int *, int);
void f5(int, int);

/* Add here function declarations of your own, if any. */

long int get_file_size(char filename[]);
char transform_char(char c);
char *concat(const char *s1, const char *s2);
void print_arr(int A[], int size);
void merge_sort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
int is_prime(int n);
int within_bounds(int p);
int is_same_line(int p, int nbp);
int is_line_before(int p, int nbp);
int is_line_after(int p, int nbp);
int check_nb(char nb[], int p, int nbp);
int get_nb_idx(char nb[], int p);
int has_nb(char nb[], int p);
int is_nb_one(int arr[], char nb[], int p);
int check_all_nbs(int arr[], int p);
void file_to_arr(char* filename, int arr[]);
void print_matrix(int A[]);
void arrcpy(int des[], int org[], int len);

/*********************************************************************************/

/* 
 * Do  NOT change anything in main function 
 */
int main(int argc, char *argv[])
{
  int option = 0;
  int i, j, k;
  int *list;

  if (argc < 2)
  {
    fprintf(stderr, "Usage: lab1 num [input]\n");
    fprintf(stderr, "num: 1, 2, 3, 4, or 5\n");
    exit(1);
  }

  option = atoi(argv[1]);

  switch (option)
  {
  case 1:
    if (argc != 5)
    {
      fprintf(stderr, "Usage: lab1 1 A B C\n");
      fprintf(stderr, "A, B, and C: Positive integers where A <= B and C < B \n");
      exit(1);
    }
    i = atoi(argv[2]);
    j = atoi(argv[3]);
    k = atoi(argv[4]);

    f1(i, j, k);

    break;

  case 2:
    if (argc != 3)
    {
      fprintf(stderr, "Usage: lab1 2 filename\n");
      fprintf(stderr, "filename: the name of the file containing the characters\n");
      exit(1);
    }

    f2(argv[2]);

    break;

  case 3:
    if (argc != 4)
    {
      fprintf(stderr, "Usage: lab1 3 filename gen\n");
      fprintf(stderr, "filename: the name of the file containing the characters\n");
      fprintf(stderr, "gen: number of generations nonzero positive integer \n");
      exit(1);
    }

    i = atoi(argv[3]);
    f3(argv[2], i);

    break;

  case 4:
    if (argc != 3)
    {
      fprintf(stderr, "Usage: lab1 4 num\n");
      fprintf(stderr, "num: nonzero positive integer = number of elements in the array\n");
      exit(1);
    }

    i = atoi(argv[2]);
    if (!(list = (int *)malloc(i * sizeof(int))))
    {
      fprintf(stderr, "Cannot allocate an integer array of %d elements\n", i);
      exit(0);
    }
    for (j = 0; j < i; j++)
    {
      printf("enter element %d: ", j);
      scanf("%d", &list[j]);
    }

    f4(list, i);

    break;

  case 5:
    if (argc != 4)
    {
      fprintf(stderr, "Usage: lab1 5 A B\n");
      fprintf(stderr, "A B: positive nonzero integers where A <= B\n");
      exit(1);
    }

    i = atoi(argv[2]);
    j = atoi(argv[3]);

    f5(i, j);

    break;

  default:
    fprintf(stderr, "You entered an invalid option!\n");
    exit(1);
  }

  return 0;
}

/********************************************************************************************/
/******* Start filling the blanks from here and add any extra functions you want, if any *****/

/*
 * function 1:
 * intput: start, end, and increment
 * output: print on the screen: start start+incr start+2incr ... end
 * Example: start = 1, end = 5, incr = 3
 * f1 must print on the screen (pay attention to spaces): 1 4 5
 * At the end, print a new line before returning
 * */
void f1(int start, int end, int incr)
{

  /** 
   * Algorithm:
   * 1. Create and initialize a new variable: current = start;
   * 2. While current is less than or equal to end, 
   *    1. print current
   *    2. increment current by incr
   * 3. finally, print end, then print a new line 
   * 
   * END 
   * 
   * Note: as lab1ref's output indicates, 
   * 1. when end can be written as start + n*incr, end is printed twice
   * 2. there is no input validation in this function 
   */

  int current = start;

  while (current <= end)
  {
    printf("%d ", current);
    current += incr;
  }

  printf("%d\n", end);
}

/*********************************************************************************/

/* 
 * function 2:
 * intput: filename for a file that contains characters in upper/lower case as well as spaces
 * output: filename.reverse that contains the same characters as the original but the case is 
 *         reversed and the spaces are intact
 * Note1: filename can be any name, for example: info.txt or characters or data.info, ...
 * Note2: The given file will not contain anything but alphabets and spaces.
 */
void f2(char *filename)
{
  /**
   * Algorithm: 
   * 1. get length of file
   * 2. get transformed file
   *    1. walk through file character by character
   *    2. store transformed value (lower to upper, upper to lower)
   * 3. write transformed value to new file
   */

  // 1. get length of file
  long int length_of_file = get_file_size(filename);
  // printf("length of file is %ld bytes\n", length_of_file);

  // 2. get processed string (lower to upper, upper to lower)

  char processed_file[length_of_file + 1];

  int i = 0;
  FILE *fp;
  fp = fopen(filename, "r");
  char c;
  while ((c = getc(fp)) != EOF)
  {
    processed_file[i] = transform_char(c);
    i++;
  }
  fclose(fp);

  // 3. write to new file

  char *NEWFILENAME = concat(filename, ".reverse");

  fp = fopen(NEWFILENAME, "w");

  int l = sizeof(processed_file) / sizeof(processed_file[0]);
  for (int i = 0; i < l - 1; i++)
  {
    fprintf(fp, "%c", processed_file[i]);
    // fprintf(fp, "%c", 'h');
  }
  printf("\n");

  free(NEWFILENAME);

  fclose(fp);
}

/*********************************************************************************/

/*
 * function 3:
 * Two inputs: - filename that contains a 3x3 matrix of cels. Each cell is either 1 or  0. 
 *             - a positive number of generations
 * output: print on the screen the 3x3 matrix, one row per line,
 *           following the following rules
 * rule 1: a cell that has 2 or 3 neighboring 1's becomes 1 in the next generation
 * rule 2: any other case, the cell becomes in the next generation 
 * Example: If the file has 0110101000 
 * It means the first row is: 011 
 * the second row is 010  and the 3rd row is 000 
 */
void f3(char *filename, int gen)
{
   /** 
   * 1. for each cell
   * 2. check each of its neighbour 
   *    1. if neighbour exists, check if it is 1
   * 3. if total1 == 2 or total1 == 3,  cell = 1
   * 4. else,                           cell = 0
   */

  /*     assume index in + 1 form    */
  
  int MATRIX_SIZE = 9;
  // char FILENAME[] = "testf3.in";
  // int GEN = 2;

  int mtx[MATRIX_SIZE], newmtx[MATRIX_SIZE];

  file_to_arr(filename, mtx);

  // printf("has neighbour %s at index %d: %d\n", "B", 1, has_nb("B", 1));
  // int checknum = 9;
  // printf("is one counter for cell '%d' 2 or 3? %d\n", checknum, check_all_nbs(mtx, checknum));
  
  // printf("matrix in generation 1 is:\n");
  // print_matrix(mtx);

  
  for(int i = 0; i < gen; i++)
  {
    // get new matrix after transformation
    for (int i=0; i<9; i++)
      newmtx[i] = check_all_nbs(mtx, i+1);
    printf("matrix in generation %d is:\n", i+1);
    print_matrix(newmtx);
    // set initial state 'mtx' to 'newmtx';
    arrcpy(mtx, newmtx, 9);
  }
}

/*********************************************************************************/

/*
 * function 4
 * intput: an array of n integers
 * output: print on the screen the array sorted in reverse order followed by a new line
 */
void f4(int *num, int n)
{
  /**
   * See merge_sort() for the solution.
   */
  merge_sort(num, 0, n - 1);
  print_arr(num, n);
}

/*********************************************************************************/

/* 
 * function 5:
 * input: two positive nonzero integers a and b where a <= b
 * output: print on the screen the non-prime numbers betweeb a and b, 
 *         including a and b themselves if they are non-prime. 
 *          0, 1, and 2 are assumed not to be prime, in case you encounter them.
 *         Leave a space between each two numbers.
 *         At the end, print a new line.
 */
void f5(int a, int b)
{
  /**
   * Algorithm: 
   * 1. go through each number between min and max
   *    1. if number is not prime, print
   */
  for (int i = a; i < b + 1; i++) 
  {
    if (!is_prime(i)) printf("%d ", i);
  }
  printf("\n");
}

/*********************************************************************************/


// Helper functions

/**
 * This function returns a file's size.
 * input:   filename
 * output:  the size of this file (long int)
 * note:    this function assumes this file exists.
 */
long int get_file_size(char filename[])
{
  FILE *fp;
  fp = fopen(filename, "r");
  fseek(fp, 0L, SEEK_END);
  long int len = ftell(fp);
  // printf("length of file is %ld bytes",len);
  fclose(fp);
  return len;
}

/**
 * This function transforms character to uppercase if it is lower case
 * or to lowercase if it is upper case. 
 * 
 * input:   character
 * output:  lowercased form of a uppercase character, 
 *          or uppercase form of a lowercase character
 * 
 * note:    for a space character, this function returns a space character
 */
char transform_char(char c)
{
  if (isupper(c))       return tolower(c);
  else if (islower(c))  return toupper(c);
  else                  return c;
}

/**
 * This function concatinates 2 strings. 
 * 
 * input:   string1, string2
 * output:  a concatinated string: string1 + string2
 */
char *concat(const char *s1, const char *s2)
{
  char *result = malloc(strlen(s1) + strlen(s2) + 1);
  strcpy(result, s1);
  strcat(result, s2);
  return result;
}

/**
 * This is a utility function for printing arrays. 
 * 
 * input:   array, size of the array
 * output:  array printed on screen
 */
void print_arr(int A[], int size)
{
  for (int i = 0; i < size; i++) printf("%d ", A[i]);
  printf("\n");
}

/**
 * This function merge sorts an int array recursively. 
 * 
 * input:   array, left starting index, right starting index
 * output:  returns nothing. sorts the array from the argument directly. 
 * 
 * initial state: 
 *        left starting index = 0; 
 *        right starting index = array_len - 1; 
 */
void merge_sort(int arr[], int l, int r)
{
  if (l < r)
  {
    int m = (l + r) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

/**
 * This function merges left and right arrays in order of decreasing int size. 
 * 
 * input:     array, 
 *            left starting index, 
 *            middle index, 
 *            right starting index;
 * output:    returns nothing. sorts array directly.
 * 
 */
void merge(int arr[], int l, int m, int r)
{
  /**
   * 1. create left and right arrays
   * 2. copy data into left and right arrays
   * 3. merge into original array, in sequence of decreasing size
   */

  /* 1. create left and right arrays */
  int leftsize = m - l + 1;
  int rightsize = r - m;
  int L[leftsize], R[rightsize];

  /* 2. copy data into left & right arrays */
  for (int i = 0; i < leftsize; i++)  L[i] = arr[l + i];
  for (int j = 0; j < rightsize; j++) R[j] = arr[m + 1 + j];
  int l_idx = 0, r_idx = 0, a_idx = l;

  /* 3. merge into original array in sequence of decreasing size */
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
}   // end of merge()

/**
 * This function checks if a number is prime.
 * 
 * input:   number to check
 * output:  1 if number is prime, 0 if number is not prime
 * 
 * note:    although 2 is a prime, according to description, 
 *          0, 1, and 2 are assumed not to be prime
 */
int is_prime(int n)
{
  if (n <= 2) return 0;
  // if (n == 2) return 1;
  for (int i = 2; i < n; i++) 
  {
    if (n % i == 0) return 0;
  }
  return 1;
}

/**
 * This function checks if an index is within the bounds 
 * of a 3x3 matrix. For instance, 5 is within bounds and 
 * 11 is not. 
 * 
 * input:   index
 * output:  1 if index is within bounds; 0 if index is not.
 * 
 * note:    this function assumes starting index = 1   
 */
int within_bounds(int p)
{
  int MIN = 1, MAX = 9;
  if (p >= MIN && p <= MAX)
    return 1;
  return 0;
}

/**
 * This function checks if 2 cells are on the same line 
 * in a 3x3 matrix. For instance, in the following matrix: 
 * 
 * 1 3 7 
 * 2 9 8
 * 4 5 6
 * 
 * 9 & 8 are on the same line, while 9 & 2 is not. 
 * 
 * input:   index1, index2
 * output:  1 if on the same line, 0 otherwise. 
 * 
 * note:    this function assumes starting index = 1   
 */
int is_same_line(int p, int nbp)
{
  return ((nbp - 1) / 3) == ((p - 1) / 3);
}

/**
 * This function checks if 1 cell is on the line before another 
 * in a 3x3 matrix. For instance, in the following matrix: 
 * 
 * 1 3 7 
 * 2 9 8
 * 4 5 6
 * 
 * 3 is on the line before 9, while 2 is not.
 * 
 * input:   index, index_to_check
 * output:  1 if index_to_check is on the line before index, 0 otherwise.
 * 
 * note:    this function assumes starting index = 1   
 */
int is_line_before(int p, int nbp)
{
  return ((nbp - 1) / 3) + 1 == ((p - 1) / 3);

}

/**
 * This function checks if 1 cell is on the line after another 
 * in a 3x3 matrix. For instance, in the following matrix: 
 * 
 * 1 3 7 
 * 2 9 8
 * 4 5 6
 * 
 * 4 is on the line before 9, while 2 is not.
 * 
 * input:   index, index_to_check
 * output:  1 if index_to_check is on the line after index, 0 otherwise.
 * 
 * note:    this function assumes starting index = 1   
 */
int is_line_after(int p, int nbp)
{
  // printf("neighbour %d line number is %d\n", nbp, nbp / 3);
  // printf("cell %d line number is %d\n", p, p / 3);
  return ((nbp - 1) / 3) - 1 == ((p - 1) / 3);

}

/**
 * This is a helper function for has_nb().
 * 
 * This function checks if a cell is of a certain type of neighbour 
 * to another cell. For instance, it checks if cell 5 is the left
 * neighbour of cell 8.
 * 
 * input:     neighbour_type: 
 *              "T": top neighbour
 *              "B": bottom neighbour
 *              "L": left neighbour
 *              "R": right neighbour
 *              "TL": top left neighbour
 *              "TR": top right neighbour
 *              "BL": bottom left neighbour
 *              "BR": bottom right neighbour
 *            index, 
 *            neighbour_index
 * 
 * output:    1 if cell at neighbour_index is of neighbour_type 
 *            to cell at index, 0 otherwise. 
 * 
 * note: default to false (0) if an incorrect neighbour_type is given.
 * note: this function assumes starting index = 1.
 */
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
  return 0;   //fallback
}

/**
 * This function returns the index of a specific neighbour type
 * of an index. For instance, it can return the index of cell 4's 
 * left neighbour.  
 * 
 * Note that in a 3x3 matrix, cell 4 does not have a left cell. 
 * Because this function does not check if neighbour exists, this 
 * function should only be called after has_nb() returns true.
 * 
 * input:     neighbour_type: 
 *              "T": top neighbour
 *              "B": bottom neighbour
 *              "L": left neighbour
 *              "R": right neighbour
 *              "TL": top left neighbour
 *              "TR": top right neighbour
 *              "BL": bottom left neighbour
 *              "BR": bottom right neighbour
 *            index
 * output:    neighbour_index; -1 if provided with wrong neighbour_type
 * 
 * note: this function assumes starting index = 1.
 */
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

/**
 * This function checks if a cell has a certain type of neighbour.
 * For instance, it checks if cell 5 has top left neighbour. 
 * 
 * input:     neighbour_type: 
 *              "T": top neighbour
 *              "B": bottom neighbour
 *              "L": left neighbour
 *              "R": right neighbour
 *              "TL": top left neighbour
 *              "TR": top right neighbour
 *              "BL": bottom left neighbour
 *              "BR": bottom right neighbour
 *            index, 
 * 
 * output:    1 if cell has a neighbour of neighbour_type, 0 otherwise.
 * 
 * note: default to false (0) if an incorrect neighbour_type is given.
 * note: this function assumes starting index = 1.
 */
int has_nb(char nb[], int p)
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

/**
 * This function checks if a cell's certain neighbour is 1. 
 * For instance, it checks if cell 4's right neighbour equals to 1.
 * 
 * input:   array that stores 3x3 matrix, 
 *          neighbour_type:
 *              "T": top neighbour
 *              "B": bottom neighbour
 *              "L": left neighbour
 *              "R": right neighbour
 *              "TL": top left neighbour
 *              "TR": top right neighbour
 *              "BL": bottom left neighbour
 *              "BR": bottom right neighbour
 *          cell_index
 * 
 * output:  1 if certain neighbour is 1, 0 otherwise.
 * 
 * note: this function assumes cell has neighbour of neighbour_type.
 *       It should only be called if has_nb() returns true. 
 * 
 * note: this function assumes starting index = 1.  
 */
int is_nb_one(int arr[], char nb[], int p)
{
  int n = arr[get_nb_idx(nb, p) - 1];
  // printf("%s\t neighbour at index %d is %d\n", nb, p, n);
  if (n == 1)
    return 1;
  return 0;
}


/**
 * This function checks every potential neighbour of a cell in 
 * a 3x3 matrix (8 potential neighbours in total). It checks 
 * every neighbour if it is 1.
 * 
 * input:     an array storing the 3x3 matrix,
 *            cell index
 * output:    1 if the number of its neighbours being 1 is 2 or 3,
 *            0 otherwise. 
 * 
 * note:      this function assumes starting index = 1.
 */
int check_all_nbs(int arr[], int p) 
{
  /** 
   * Check all neighbours
   * if has neighbour, see what neighbour is
   * count number of 1s
   * if num_of_1s == 2 || 3, return 1
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
  
  // printf("one counter is %d\n", one_counter);

  if (one_counter == 2 || one_counter == 3)
    return 1;

  return 0;
}

/**
 * This function puts numbers of a matrix in a file into
 * an array. 
 * 
 * input:     a file storing the matrix, 
 *            destination_array
 * output:    destination_array storing numbers in a matrix
 * 
 * note: the size of destination_array is set outside this
 *       function. 
 */
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

/**
 * This function prints a 3x3 matrix. 
 * 
 * input:     an array storing a 3x3 matrix
 * output:    print a 3x3 matrix on screen
 */
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

/**
 * This function copies one array into another. 
 * 
 * input:   destination_array
 *          original_array
 *          length_of_both_arrays
 * 
 * note: data in the original array will override data 
 *       in destination array.
 * note: this function assumes int array
 * note: this function assume destination array and 
 *       original array has same length
 */
void arrcpy(int des[], int org[], int len)
{
  // printf("des before:\n");
  // print_matrix(des);
  for (int i = 0; i < len; i++)
  {
    des[i] = org[i];
  }
  // printf("des after:\n");
  // print_matrix(des);
}
