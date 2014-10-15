#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char ** argv)
{ 
  int ind;
  
  for (ind = 1; ind < argc; ind ++)
  {
    if (strcmp(argv[ind], "--help") == 0)
    {
      printf("Usage: cat-lite [--help] [FILE]...\n");
      printf("With no FILE, or when FILE is -, read standard input.\n\n");
      printf("Examples:\n");
      printf("  cat-lite README   Print the file README to standard output.\n");
      printf("  cat-lite f - g    Print f's contents, then standard input,\n"); 
      printf("                    then g's contents.\n");
      printf("  cat-lite          Copy standard input to standard output.\n");
      return EXIT_SUCCESS; 
    }

  }
  if (argc == 1)
  {
    char ch; 
     while ((ch = fgetc(stdin)) != EOF)
     {
       fprintf(stdout, "%c", ch);
     }
  }
  int num = 1;  
  for(num = 1; num < argc; num ++)
  {
     if(strcmp(argv[num],"-") == 0)
     { 
       int n = 300;
       char buffer[n];  
       while (fgets( buffer, n , stdin) != NULL)
       {
         printf("%s\n", buffer);
       }
     }
     else
     {
       FILE * fp = fopen(argv[num], "r");
       if (fp == NULL)
       {
         fprintf(stderr, "cat cannnot open %s\n", argv[num]);
         return EXIT_FAILURE;
       }
       char ch;  
       while ((ch = fgetc(fp)) != EOF)
       {
         printf("%c", ch);
       }
       fclose(fp);
     }
   }
     return EXIT_SUCCESS;
}   
     
     
       
   
