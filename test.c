
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_prime(int n)
{
  if (n <= 1) return 0;
  if (n == 2) return 1;
  for (int i = 2; i < n; i++) 
  {
    if (n % i == 0) return 0;
  }
  return 1;
}

int main(int argc, char *argv[])
{
  int MIN = 1, MAX = 20;
  for (int i = MIN; i < MAX+1; i++) 
  {
    if (!is_prime(i)) printf("%d ", i);
  }
  printf("\n");
  return 0;
}
