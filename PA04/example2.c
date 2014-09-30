
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * * argv)
{
  // stdin, stdout, and stderr are FILE *, that always
  // exist for every progrm.
  // stdout and stderr go to the terminal
  // stdin *reads* from the terminal
  const char * filename = "example.c";
  FILE * fp = fopen(filename, "r");
  if(fp == NULL) {
    fprintf(stderr, "Failed to open file '%s'\n", filename);
    return EXIT_FAILURE;
  }

  int counter = 0;
  while(!feof(fp)) {
    int ch = fgetc(fp);
    printf("character %d = %d, which is '%c'\n",
	   counter++, ch, ch);
  }

  fclose(fp); // what is opened, must be closed.
  
  return 0;
}

