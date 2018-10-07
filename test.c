
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**
 * 1. get length of file
 * 2. create array to store transformed chars
 * 3. write array to new file
 */

// char *switchLowerAndUpper(char filename[], long int len)
// {
//   char new_str[len];
//   int i = 0;
//   FILE *fp;
//   fp = fopen(filename, "r");
//   char c = fgetc(fp);

//   while (c != EOF)
//   {
//     if (isupper(c))
//     {
//       new_str[i] = tolower(c);
//     }
//     else if (islower(c))
//     {
//       new_str[i] = toupper(c);
//     }
//     else
//     {
//       new_str[i] = c;
//     }
//     c = fgetc(fp);
//     i++;
//   }
//   fclose(fp);
//   return new_str;
// }

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
char transformChar(char c)
{
  if (isupper(c))
  {
    return tolower(c);
  }
  else if (islower(c))
  {
    return toupper(c);
  }
  else
  {
    return c;
  }
}

char *concat(const char *s1, const char *s2)
{
  char *result = malloc(strlen(s1) + strlen(s2) + 1);
  strcpy(result, s1);
  strcat(result, s2);
  return result;
}

int main(int argc, char *argv[])
{
  char FILENAME[] = "test.txt";
  long int length_of_file = getFileSize(FILENAME);
  printf("length of file is %ld bytes\n", length_of_file);

  char processed_file[length_of_file + 1];

  int i = 0;
  FILE *fp;
  fp = fopen(FILENAME, "r");
  char c;
  while ((c = getc(fp)) != EOF)
  {
    processed_file[i] = transformChar(c);
    i++;
  }
  fclose(fp);
  
  char* NEWFILENAME = concat(FILENAME, ".reverse");

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
  return 0;
}
