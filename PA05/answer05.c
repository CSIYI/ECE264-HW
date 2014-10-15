#include<stdio.h>
#include<stdlib.h>

//print function
void print(int * arr, int length)//FROM BOOK
{
  int ind;
  for (ind = 0; ind < length -1; ind ++ )
  {
    printf("%d + ", arr[ind]);
   
  }
  printf("%d\n", arr[length - 1]);
}
//
//partitionALL
void partition(int * arr, int ind, int input)//FROM BOOK
{
  int value;
  if(input == 0)
  {
    print(arr, ind);
  
  }

  for (value = 1; value <= input; value ++)
  {
    arr[ind] = value;
    partition(arr, ind + 1, input - value);
  }
}

void partitionALL(int value)//FROM BOOK
{
  int * arr;
  arr = malloc(sizeof(int) * value);
  partition(arr, 0,value);
  free(arr);
   
}
//
//partitionIncreasing
void partitionIN(int * arr, int ind, int input, int inc)
{
  int value;
  if (input == 0)
  {
    print(arr, ind);
  }
  
  for(value = inc; value <= input; value ++)
  {
    arr[ind] = value;
    inc = value +1 ;
   
    partitionIN(arr, ind + 1, input - value, inc);
  }

}

void partitionIncreasing(int value)
{
   int * arr;
   arr = malloc(sizeof(int) * value);
   partitionIN(arr, 0, value, 1);
   free(arr);
  
}
//
//partitionDecreasing
void partitionDE (int * arr, int ind, int input)
{
  int value;
  if (input == 0)
  {
    print(arr, ind);
  }
  int quo = input/2 + 1;  
  for (value = quo; value <= input; value ++)
  {
    arr[ind] = value;
    quo = input - value;
    partitionDE(arr, ind + 1, input -value);

  }
}
  
void partitionDecreasing(int value)
{
  int * arr;
  arr = malloc(sizeof(int) * value);
  partitionDE(arr, 0,value);
  free(arr);
}  
//
//partitionOdd
void partitionO (int * arr, int ind, int input)
{
  int value;
  if (input == 0)
  {
    print(arr, ind);
  }
  for(value = 1; value <= input; value += 2 )
  {
    arr[ind] = value;
    partitionO(arr, ind + 1, input - value);
  }
} 

void partitionOdd(int value)
{
  int * arr;
  arr = malloc(sizeof(int) * value);
  partitionO(arr, 0, value);
  free(arr);
}
//
//partitionEven
void partitionE(int * arr, int ind, int input)
{
  int value;
  if (input == 0)
  {
    print(arr, ind);
  }
  for (value = 2; value <= input; value += 2 )
  {
    arr[ind] = value;
    partitionE(arr, ind + 1, input - value);
  }
}

void partitionEven(int value)
{
  int * arr;
  arr = malloc(sizeof(int) * value);
  partitionE(arr, 0, value);
  free(arr);
}

//
//partitionOddAndEven
void partitionOE(int * arr, int ind, int input)//FROM THE BOOK
{
  int value;
  
  if (input == 0)
  {
    print(arr, ind);
  }
  for(value = 1; value <= input; value ++)
  {
      int check = 0;
      if (ind == 0)
      {
        check = 1;
      }
      else
      {      
        check = (arr[ind - 1] % 2) != (value % 2);
      }
       
      if (check == 1)
      {
        arr[ind] = value;           
        partitionOE(arr, ind + 1, input - value);
      }
       
       
  }
}
void partitionOddAndEven(int value)
{
  int * arr;
  arr = malloc(sizeof(int) * value);
  partitionOE(arr, 0 , value);
  free(arr);
}
//
//partitionPrime
void partitionP(int * arr, int ind, int input)
{
  int value;
  if (input == 0)
  {
    print(arr, ind);
  }
  for(value = 1; value <= input; value ++)
  {
    int check = 0;
    if (ind == 0)
    {
      check = 1;
    }
    else
    {
      int i;
      for (i = 2; i < value; i++)
      {
        if(value % i == 0 && i != value)
        {
          check = 0;
        }
      }
      check = 1;
    }
    if (check == 1)
    {
      arr[ind] = value;
      partitionP(arr, ind + 1, input - value);
    }
}
}
void partitionPrime(int value)
{
  int * arr;
  arr = malloc(sizeof(int) * value);
  partitionP(arr, 0 , value);
  free(arr);
}
// test main function
int main()
{
  printf("print out all the partition\n");
  partitionALL(5);
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
  partitionPrime(5);
  return 0;
}
//
