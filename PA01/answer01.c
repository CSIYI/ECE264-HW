#include <stdlib.h>
#include "answer01.h"

int arraySum(int * array, int len)
{   
    int counter;
    int sum = 0;
    for(counter = 0; counter <= len-1; counter ++)
    {
      sum += array[counter];
    }

    return sum;
}

int arrayCountNegative(int * array, int len)
{   
    int counter = 0 ;
    int neg = 0;
    while(counter <= len-1)
    {
      if(array[counter] < 0)
      {
         neg++;
      }
    counter++;
    }
    return neg;
}

int arrayIsIncreasing(int * array, int len)
{   
    int counter = 1;
    int point = 1;
    
    while (counter <= len-1)
    {
      if (array[counter] >= array[counter-1] )
      {
         counter ++;
      }
      else 
      {
        point = 0;
        counter += len;
      } 
    }
    if (len <= 1)
    {
       point = 1;
    }
  
    return point;
}

int arrayIndexRFind(int needle, const int * haystack, int len)
{   
    int counter = 0;
    int index = -1;
    while(counter <= len-1)
    {
      if (haystack[counter] == needle)
      {
         index = counter;
      }
      counter ++;
    }
     
    return index;
}

int arrayFindSmallest(int * array, int len)
{   
    int counter;
    int index = 0;
    for (counter = 0; counter<len; counter++)
    {
       if (array[index] <= array[counter] )
       {  
       }
       else 
       {
          index = counter;
       }
    } 
    return index;
}
