#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "answer09.h"
/********************************************Explode*/
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
/********************************************************/
BusinessNode * create_node(char * stars, char * names, char * address)
{
  BusinessNode * copy = malloc(sizeof(BusinessNode));
  copy -> name = names;
  copy -> stars = stars;
  copy -> address = address;
  copy -> left = NULL;
  copy -> right = NULL;
  return copy;  
}

BusinessNode * tree_insert(BusinessNode * node, BusinessNode * root)
{ 
  if(root == NULL)
  {
    return(node);
  }
  if ((strcmp(node -> name, root -> name)) <= 0)
  {
    root-> left = tree_insert(node, root -> left);
  }
  if ((strcmp(node -> name, root -> name)) > 0)
  {
    root-> right = tree_insert(node, root -> right);
  }
  return root;
}

BusinessNode * load_tree_from_file(char * filename)
{
  FILE * fp;
  fp = fopen(filename, "r");
  int ptr = 3;
  char sstr[300];
  char ** str;
  BusinessNode * rt = NULL;
  BusinessNode * head = NULL;
  if (fp == NULL)
  {
    return NULL;
  }
  while (fgets(sstr, 300, fp) != NULL)
    {  
      str = explode(sstr, "\t", &ptr);     
      head = create_node(str[0],str[1],str[2]);
      rt = tree_insert(head, rt);
      free(str);
    }
  fclose(fp);
  return rt;
}

BusinessNode * tree_search_name(char * name, BusinessNode * root)
{
  BusinessNode * point = NULL;
  if (root == NULL)
  {
    return NULL;
  }
  if(strcmp(name, root -> name) == 0)
  {
    point =  root;
    return(point);
  }
  if(strcmp(name, root -> name) < 0)
  {
    point = tree_search_name(name, root -> left);
  }
  else
  {
    point = tree_search_name(name, root-> right);
  }
  return (point);
}

void print_node(BusinessNode * node)
{
  printf("%s\n", node -> name);
  printf("============\n");
  printf("Stars:\n");
  printf("   %s\n", node ->stars);
  printf("Address:\n");
  printf("   %s\n", node -> address);
}

void print_tree(BusinessNode * tree)
{
  if (tree == NULL)
  {
    return;
  }
  print_tree(tree -> left);
  print_tree(tree -> right);
  print_node(tree);

}

void destroy_tree(BusinessNode * root)
{
  if (root != NULL)
  {
    free(root -> address);
    free(root -> stars);
    free(root -> name);
    destroy_tree(root -> left);
    destroy_tree(root -> right);
    
  }
  free(root);
  return;
}
  

   

