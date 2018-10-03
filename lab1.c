
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


/*********************************************************************************/

/* 
 * Do  NOT change anything in main function 
 */
int main(int argc, char * argv[])
{
  int option = 0;
  int i, j, k;
  int * list;
  
  if(argc < 2 )
  {
     fprintf(stderr,"Usage: lab1 num [input]\n");
     fprintf(stderr,"num: 1, 2, 3, 4, or 5\n");
     exit(1);
  }
  
  option = atoi(argv[1]);
  
  switch(option)
  {
    case 1: if(argc != 5)
	    {
	      fprintf(stderr,"Usage: lab1 1 A B C\n");
	      fprintf(stderr,"A, B, and C: Positive integers where A <= B and C < B \n");
	      exit(1);
	    }
	    i = atoi(argv[2]);
	    j = atoi(argv[3]);
	    k = atoi(argv[4]);
	   
	    f1(i, j, k);
	    
	    break;
	    
	    
    case 2: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 2 filename\n");
	      fprintf(stderr,"filename: the name of the file containing the characters\n");
	      exit(1);
	    }
	    
	    f2(argv[2]);
	    
	    break;

	    
    case 3: if(argc != 4)
	    {
	      fprintf(stderr,"Usage: lab1 3 filename gen\n");
	      fprintf(stderr,"filename: the name of the file containing the characters\n");
	      fprintf(stderr,"gen: number of generations nonzero positive integer \n");
	      exit(1);
	    }
	    
	    i = atoi(argv[3]);
	    f3(argv[2], i);
	    
	    break; 
	    
	    
    case 4: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 4 num\n");
	      fprintf(stderr,"num: nonzero positive integer = number of elements in the array\n");
	      exit(1);
	    }
	    
	    i = atoi(argv[2]);
	    if(!(list = (int *)malloc(i*sizeof(int))))
	    {
	      fprintf(stderr,"Cannot allocate an integer array of %d elements\n", i);
	      exit(0);
	    }
	    for(j = 0; j < i; j++)
	    {
	      printf("enter element %d: ", j);
	      scanf("%d",&list[j]);
	    }
	    
	    f4(list, i);
	    
	    break;

	    
    case 5: if(argc != 4)
	    {
	      fprintf(stderr,"Usage: lab1 5 A B\n");
	      fprintf(stderr,"A B: positive nonzero integers where A <= B\n");
	      exit(1);
	    } 
	    
	    i = atoi(argv[2]);
	    j = atoi(argv[3]);
	    
	    f5(i, j);
	    
	    break;

	          
	    
    default: fprintf(stderr, "You entered an invalid option!\n");
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
void f2(char * filename)
{

  /** 
   * Algorithm: 
   * 1. open file with read priviledge
   * 2. if there's file and user has priviledge 
   *    1. instantiate empty string: str
   *    2. read each char in file 
   *    3. for each char, there are 3 cases:
   *      1. uppercase letter: append lowercase letter to str
   *      2. lowercase letter: append uppercase letter to str
   *      3. empty space:      append empty space to str
   *    4. close file
   *    5. create new file named filename + ".reverse"
   *    6. write str to this new file
   * END
   */

int c;
char *str;
FILE *fp;
fp = fopen(filename, "w");
if (fp) 
{
  while ((c = getc(fp)) != EOF) 
  {
    char *cf;
    if (isupper(c))
    {
      *cf = tolower(c);
    }
    else if (islower(c)) 
    {
      *cf = toupper(c);
    }
    strcat(str, *cf);
    printf("%s\n", str);
  }
  fclose(fp);
}

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



}

/*********************************************************************************/

/*
 * function 4
 * intput: an array of n integers
 * output: print on the screen the array sorted in reverse order followed by a new line
 */
void f4(int * num, int n)
{
  

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


}

/*********************************************************************************/

