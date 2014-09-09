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


int my_coutchar(const char * str, char ch)
{  
   int length = 0;
   int index = 0;
  
   while (str[length] != '\0')
   {
      if (str[length] == ch)
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
  char * string = NULL;

do
{
     if (str[length] == ch)
     {
        string = (char *)&str[length];               
        return(string);
     }   
     length++;
}while(str[length] != '\0'); 

  return(string);
}


char *my_strrchr(const char * str, int ch)
{
  int length = my_strlen(str);
  char * string = NULL;
  
  while(str[length] != ch && length >= 0)
  {
    length--; 
  }
  if (length > 0) 
  {     
    string =(char *)&str[length];
  }
  
  
  return(string);
}


char * my_strstr(const char *haystack, const char * needle)
{
  int len = my_strlen(needle);
  int length = 0;
  int n ;   
  
  while(haystack[length] != '\0')
  {
     if(haystack[length] == needle[0])
     {
        
        for(n= 0; haystack[length+n] == needle[n];n++)
       {
           if (n == len)
           {
             return((char*)needle);
           }
        }
        return(NULL);           
      }       
      length++;
   }
  if (needle == '\0')
  {
      return((char*)haystack);
  
}
return(NULL);
}


char * my_strcpy(char * dest, const char * src)
{
  int index = 0;
  int length = 0; 
 
  while(src[length] != '\0')
  {
     dest[index] = src [index];
     index++;
     
  }
  return(dest);
}   


char * my_strcat(char * dest, const char * src)
{
  int index = 0;
  int length = 0;
  
  while( dest[length] != '\0')
  {
     length++;
  }
  
  dest[length]=' ';
   
  while (src[index] != '\0')
  {
     dest[1 + length + index]= src[index]; 
     index++;
  }
   
  return(dest);
}

int my_isspace(int ch)
{ 
  int ind = 0;
  if (ch == ' ' || ch == '\f' || ch =='\n' || ch == '\r' || ch == '\t' || ch == '\v')
  {
     ind = 1;
  } 
  return(ind);
}

/*
int my_atoi(const char * str)
{
  int ret = 0;
  int index = 0;
 
  while(str[index] != ' ')
  {
  */       










































  
 
   
