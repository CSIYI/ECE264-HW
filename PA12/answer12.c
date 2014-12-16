#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<math.h>
#include "answer12.h"
#define FlASE 0
#define TRUE 1
/*int main()
{
  uint128 j = 931214214489869;
  char * jstr =primalityTestParallel (j,4);
  printf("Hello World!\n");
  printf("j = %s\n", jstr);
  free(jstr);
  return (0);
}
*/
typedef struct div
{
  uint128 upper;
  uint128 lower;
  uint128 num;
  int rlt;
}Div;

uint128 alphaTou128(const char * str)
{
  uint128 ret = 0;
  if(*str == '-')
  {
    return 0;
  }
  if (*str == ' ')
  {
     str++;
  }
  if(*str>= '0' && *str <= '9')
  {    
    while (*str>= '0' && *str <= '9')
    {
      ret = ret*10 + (*str - '0');
      str++;
    }          
  }
  else
  {
    return 0;
  }
  return ret;
}
		 
char * u128ToString(uint128 value)
{
  uint128 tmd = value;
  int counter = 0;
  if(tmd == 0)
  {
    counter =1;
  }
  else
  {	  
    while(tmd !=  0)
    {
      tmd = tmd/10;
      counter ++;
    }
  } 
  char * arr = malloc((counter+1) *sizeof(char));
  int p;
  for (p = (counter-1); p >= 0; p--)
 {
    arr[p] = value % 10 + '0';
    value /= 10; 
  }
  arr[counter] = '\0';
  return arr;
}

void * test(void * number)
{
    Div * temp =(Div *)number;
    uint128 i;
    for (i = temp->lower; i <= temp->upper ; i++)
    {
        if ((temp->num % i) == 0)
        {
          temp->rlt = FALSE;
          return NULL;
        }
    }    temp->rlt = TRUE;
    return NULL;
}


int primalityTestParallel(uint128 value, int n_threads)
{


   if(value == 2)
  {
    return TRUE;
  }
  if(value % 2 == 0 )
  {
    return FALSE;
  } 
  if(value == 1)
  {
    return FALSE;
  }
  if (value == 3)
  {
    return TRUE;
  }
  uint128 ch = floor(sqrt(value));
  uint128 n = ch/ n_threads;
 
  Div * c = malloc(n_threads * sizeof(Div));
  pthread_t * threads = malloc(n_threads *sizeof(pthread_t));
  uint128 i;
  int check;  
  for(i = 0; i < n_threads; i++)
  {
    c[i].lower = i * n;
    c[i].upper = (i + 1) * n;
    c[i].num = value;
   // {
     // char * low_s = u128ToString(c[i].lower);
     // char * upp_s = u128ToString(c[i].upper);
     // printf("lower boundry : %s, higher boundry : %s\n",
//	     low_s, upp_s);    
     // free(low_s);
     // free(upp_s);
   // }
     if (c[i].lower <= 2)
    {
       c[i].lower = 3;
    }
    if(c[i].lower % 2 == 0)
    {
       c[i].lower ++;
    }
    if (c[i].upper < c[i].lower)
    {
       c[i].upper = c[i].lower;
    }

    check = pthread_create(& threads[i], NULL , test, (void *)& c[i]);
  }    
  
  int dex;
  int join;
  for(dex = 0; dex < n_threads; dex++)
  {
     join = pthread_join(threads[dex], NULL);
  }
  
  int ans = TRUE;
  int x;
  for (x = 0; x < n_threads; x++)
  { 
    if(c[x].rlt != 1)
    { 
      ans = FALSE;
      break;
    } 
  }
 // printf("%s\n", (ans ? "True" : "False"));
   
  free(threads);
  free(c);
  return ans;
}







