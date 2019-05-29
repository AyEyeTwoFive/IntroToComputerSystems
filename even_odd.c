/* C Program to Check Odd or Even using IF Condition */

#include<stdio.h>

int main()
{
  int number;

  printf(" Enter an integer to check Even or Odd \n");
  scanf("%d", &number);
  
  if (number & 1 == 1) 
     printf("%d is ODD\n", number);

  else
    printf("%d is EVEN\n", number);

  return 0;
}
