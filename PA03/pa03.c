#include<stdio.h>
#include<string.h>
#include"answer03.h"

int main (int argc,char **argv)
{
   int i;
   int number = 0;
   int* num = &number;
   char** arr;
   //:wq char* string;
   char *glue = malloc(sizeof(char)*3); 
   char *s = malloc(sizeof(char)*20);

   glue = strdup(" ");//delims
   s = strdup("good monrning");

   arr =  explode(s,glue,num);
   for(i=0;i<number;i++)
     {
       printf("%s\n",arr[i]);
     }

   // string = implode(arr,number,glue);
   // printf("\n%s\n",string);
   
   free(s);
   free(glue);
   for(i=0;i<(*num);i++)
     {
       free(arr[i]);
     }
   free(arr);
   // free(string);
   return 0;
}


