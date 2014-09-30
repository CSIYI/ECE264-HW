#include<stdio.h>
#include<stdlib.h>

int main(int argc, char ** argv)
{
  int ind = 1; 
     for(ind = 1; ind < argc; ind++)
     {
       printf("%s ",argv[ind]);
     }
   
  printf("\n");
return EXIT_SUCCESS;
}
