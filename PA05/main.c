#include <stdio.h>
#include "answer05.h"
int main()
{
  printf("print out all the partition\n");
  partitionAll(5);
  printf("print out increasing partition\n");
  partitionIncreasing(5);
  printf("print out decreasing partition\n");
  partitionDecreasing(5);
  printf("more ex for de\n");
  partitionDecreasing(6);
  printf("print out odd partition\n");
  partitionOdd(5);
  printf("print out even partition\n");
  partitionEven(6);
  printf("print out odd and even partition\n");
  partitionOddAndEven(5);
  printf("print prime partition\n");
  partitionPrime(9);
  return 0;
}


