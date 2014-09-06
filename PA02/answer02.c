#include<stdio.h>
#include"answer02.h"

size_t my_strlen(const char * str)
{
   int length = 0;
   while (str[length] != '\0')
   {
       length++;
   }

   return(length);
}

int my_coutchar(const char * str, char ch);
{  
   int length = 0;
   int index = 0;
  
   while (str[length] != '\0')
   {
      if (str[length] = ch)
      {
        index ++;
      }
      length++;
   }
   return(index);
} 

char * my_strchr(const char * str, int ch)
{
  int length = 0;
  int index = 0;
  while (str[length] != '\0')
  {
     if (str[length] = ch)
     {
        
  
