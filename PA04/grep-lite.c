#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char ** argv)
{
  int ind;
  for (ind = 1; ind < argc; ind ++)
  { 
    if (strcmp(argv[ind], "--help") == 0)
      {
        printf("Usage: grep-lite [OPTION]... PATTERN\n");
        printf("Search for PATTERN in standard input. PATTERN is a\n");
        printf("string. grep-lite will search standard input line by\n");
        printf("line, and (by default) print out those lines which\n");
        printf("contain pattern as a substring.\n\n");
        printf("  -v, --invert-match     print non-matching lines\n");
        printf("  -n, --line-number      print line numbers with output\n");
        printf("  -q, --quiet            suppress all output\n\n");
        printf("Exit status is 0 if any line is selected, 1 otherwise;\n");
        printf("if any error occurs, then the exit status is 2.\n");
        return EXIT_SUCCESS;
       }
  }
  int indx;
  for( indx = 1; indx < (argc - 1); indx ++)
  {
    if((strcmp(argv[indx],"-v")) != 0 && (strcmp(argv[indx], "-n")) != 0 && (strcmp(argv[indx], "-q")) != 0 && (strcmp(argv[indx], "--invert-match")) != 0 && (strcmp(argv[indx], "--quiet") != 0  && strcmp(argv[indx], "--line-number") != 0))
    {
      fprintf(stderr, "Bogus command-line arguments!\n");
      return 2;
    }
  }   
  if (argv[argc - 1][0] == '-' )
  {
    fprintf(stderr, "Pattern can't start with '-'\n");
    return 2;
  }
  int num;
  int count_v = 0;
  int count_n = 0;
  int count_q = 0;
  for( num = 1; num < (argc - 1); num ++)
  { 
    if (strcmp(argv[num],"-v") == 0 || strcmp(argv[num], "--invert-match") == 0)
    {
      count_v ++;
    }
    if (strcmp(argv[num], "-n") == 0 || strcmp(argv[num], "--line-number") == 0)
    {
      count_n ++;
    }
    if (strcmp(argv[num], "-q") == 0 ||strcmp( argv[num], "--quiet") == 0)
    {
      count_q ++;
    }
  } 
    int check = 1 ;
    int num_line = 0; 
    int n = 2000;
    char buffer[n];
    while(fgets(buffer, n, stdin) != NULL)
    { 
      num_line ++;
      if ((strstr(buffer, argv[argc  - 1])) == NULL)
      {
        
        
        if (count_n != 0 && count_v != 0 && count_q == 0)
        {
          printf("%d:", num_line);
        }
        if(count_v != 0 && count_q == 0)
        {
         printf("%s", buffer);
        }
      }
      else 
      {
        check = 0;
        if (count_v == 0 && count_q == 0 )
        {
	  if(count_n != 0)
          {
	    printf("%d:", num_line);
	  }       	
          printf("%s", buffer);
        }
      }
          
     }
     return check;
}   

    
    



  




