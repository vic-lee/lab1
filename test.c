
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**
 * 1. get length of file
 * 2. create array to store transformed chars
 * 3. write array to new file
 */

int main(int argc, char *argv[]) 
{
  char FILENAME[] = "test.txt";
  long int length_of_file = getFileSize(FILENAME);
  printf("length of file is %ld bytes",length_of_file);

  char processed_file[length_of_file + 1];
  

  return 0;
}

char switchLowerAndUpper(char filename[], long int len)
{
  char processed_str[len];
  FILE *fp;
  fp = fopen(filename, "r");
  char c = fgetc(fp);
  while (c != EOF) 
  {

  }
  fclose(fp);
}

long int getFileSize(char filename[]) 
{
  FILE *fp;
  fp = fopen(filename, "r"); 
  fseek(fp, 0L, SEEK_END);
  long int len = ftell(fp);
  // printf("length of file is %ld bytes",len);
  fclose(fp);
  return len;
}