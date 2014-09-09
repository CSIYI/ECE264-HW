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


int my_countchar(const char * str, char ch)
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
  int length = my_strlen(str);
  int count = 0; 
  char * string = NULL;

do
{
     if (str[count] == ch)
     {
        string = (char *)&str[count];               
        return(string);
     }
               
     count++;
     
}while(count <= length + 1); 

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
  if (length >= 0) 
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

  if (needle[0] == '\0')
  {
    return((char*)&haystack[0] );
  }  
  while(haystack[length] != '\0')
  {
     if(haystack[length] == needle[0])
     {
        
        for(n= 0; haystack[length+n] == needle[n];n++)
       {
           if (n == len-1)
           {
             return((char*)&haystack[length]);
           }
        }
        return(NULL);           
      }       
      length++;
   }
 
return(NULL);
}


char * my_strcpy(char * dest, const char * src)
{
  int index = 0;

  do
  {
     dest[index] = src [index];
     index++;
     
  }while(src[index] != '\0');
  dest[index] = '\0';
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
   
  while (src[index] != '\0')
  {
     dest[length + index]= src[index]; 
     index++;
  }
 
  dest[length + index ]='\0'; 
 
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



int my_atoi(const char * str)
{
  int ret = 0;
  int minus = 0;
    

  while (str[0] == ' ' || str[0] == '\f' || str[0] =='\n' || str[0] == '\r' || str[0] == '\t' || str[0] == '\v')
  {
     str++;
     
  }
  if(str[0] == '-')
  {
    str++;
    minus = -1; 
  }
      
  if(str [ret] >= '0' && str [ret] <= '9') 
  {
     while (str [0] >= '0' && str [0] <= '9')
     {
        ret = ret*10 + (*str - '0');
        str++;
      }
          
      if (minus != 0)
      {
        return(minus * ret);
      }
      else
      {
        return (ret);
      }
   }  
              
  else
  {
    return(0);
  }         

}







































  
 
   
