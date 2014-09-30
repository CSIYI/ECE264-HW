#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char ** argv)
{ 
  int ind;
  int n = 300; 
  for (ind = 1; ind < argc; ind ++)
  {
    if (strcmp(argv[ind], "--help") == 0)
    {
      printf("<help-message>\n");
      printf("Usage: cat-lite [--help] [FILE]...\n");
      printf("With no FILE, or when FILE is -, read standard input.\n\n");
      printf("Examples:\n");
      printf("  cat-lite README   Print the file README to standard output.\n");
      printf("  cat-lite f - g    Print f's contents, then standard input,\n"); 
      printf("                    then g's contents.\n");
      printf("  cat-lite          Copy standard input to standard output.\n");
      printf("</help-message>\n\n");
      return EXIT_SUCCESS; 
    }

  }
  int index;
  for(index = 1; index < argc; index ++)
  {
     if(strcmp(argv[index],"-") == 0)
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
       FILE * fp = fopen(argv[index], "r");
       if (fp == NULL)
       {
         fprintf(stderr, "cat cannnot open %s\n", argv[index]);
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
     
     
       
   
