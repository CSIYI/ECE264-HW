#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "answer03.h"

/*int main(void)
{
 int len ;
 char * *strArr = explode ("100 224 147 80", " ", &len);
 char * str = implode(strArr, len, ",");
 printf("(%s)\n", str);

 return(0);
}
*/
char * strcat_ex (char * * dest, int * n, const char * src)
{
  int len_s;
  int len_d;
  char * new;
 
  len_s = strlen(src);
     
  if ( *dest == NULL)  
  { 
    * dest =malloc((1 + 2*len_s)*sizeof(char *));
    * dest[0] = '\0';
    strcpy(* dest, src);
  
    *n = 1+ 2*len_s;
    return(*dest);
  }
  len_d = strlen(* dest);  
  if (*n < (len_s + len_d + 1))
  {

    new = malloc((1 + 2*(len_d + len_s))*sizeof(char));
    new[0] = '\0';
    strcpy(new, *dest);            
    *n = 1 + 2*(len_d + len_s);
    free(*dest);
    *dest = new;
    strcat(*dest, src);
  }   
  else 
  {
     strcat(*dest, src);
     
  }
  return(*dest);
}


char * new_str(const char * s, int last, int len)
{
  char * str = malloc((len+1) * sizeof(char));
   memcpy(str, s+last, len);
  str[len] = '\0';
  return str; 
}

char * * explode(const char * str, const char * delims, int * arrLen)
{
   int n = 0; 
   int num = 0;
   while(str[num] != '\0')
   {
     if(strchr(delims, str[num]) != NULL)
     {
       n++;
     }
     num++;
   }
   char * * strArr = malloc((n + 1) * sizeof(char *));  
   int ind ;
   int arrInd = 0;
   int last = 0;
   for (ind = 0 ; ind < strlen(str); ind++)
   {
      if (strchr(delims, str[ind]) != NULL)
      {  
         strArr[arrInd] = new_str(str, last, ind - last);
         last= ind + 1;
         arrInd++;
       }                 
   }
   strArr[arrInd]=new_str(str, last, ind-last);
   * arrLen = n + 1;
   return(strArr);
}


              
char  *implode (char * * strArr, int len, const char * glue)
{ 
   char * new = NULL;
   int index3 = 0;
   int change_n = len;
   if (*strArr == NULL)
   {
     return(NULL);
   }
   if (len == 1)
   {
      new = strcat_ex(&new,&len,strArr[0]);
      return(new);
   }
   if(len ==2 )
   {
       new = strcat_ex(&new, &len,strArr[0]);       
       new = strcat_ex(&new, &len,glue);
       new = strcat_ex(&new, &len,strArr[1]);
     return(new);
   }

     for (index3 = 0; index3 < (len - 1); index3++)
     {  
        new = strcat_ex(&new, &change_n, strArr[index3]);
        new = strcat_ex(&new, &change_n, glue);
     }
     new = strcat_ex(&new,&change_n, strArr[index3]);
    

  return (new);

}

int my_compare(const void * a, const void *b)
  {
    int ans;
    ans = strcmp(*(const char **) a, *(const char **) b);
    return(ans);
  }


void sortStringArray(char * * arrString, int len)
{
    
  qsort(arrString, len, sizeof(char *), my_compare );

}


int mycompare(const void * a, const void * b)
{
  return(*(char *)a- *(char*)b);
}
void sortStringCharacters(char * str)
{
  qsort(str, strlen(str), sizeof(char), mycompare );
  
  return;
}

void destroyStringArray(char * * strArr, int len)
{
  int index6;
  for(index6 = 0; index6 < len; index6++)
  {
     free(strArr[index6]);
  }
  
  free(strArr);
}




 
