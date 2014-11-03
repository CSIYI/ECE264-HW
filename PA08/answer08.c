#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "answer08.h"

List * List_createNode(const char * str)
{ 
   List * head = malloc(sizeof(List));
   head -> next = NULL;
   head -> str = strdup(str);
   return head;   
}

void List_destroy(List * list)
{
  if (list != NULL)
  {
    free(list -> str);  
    List_destroy(list -> next);
  }
  free(list);
  
}

int List_length(List * list)
{
  
  int counter = 0;
 
  List * temp = list;
  while(temp != NULL)
  {
    counter ++;
    temp = temp -> next;
  }
  return(counter);
}

void Order(struct ListNode_st ** dest, struct ListNode_st ** source)
{
  struct ListNode_st * new = *source;
  * source = new -> next;
  new -> next = * dest;
  * dest = new;
}

List * List_merge(List * lhs, List * rhs, int(* compar)(const char *, const char *))
{
  struct ListNode_st * result = NULL;
  struct ListNode_st ** ptr = &result;
   while(1)
   {
     if (lhs == NULL)
     {
       * ptr = rhs;
       break;
     }
     else if (rhs == NULL)
     {
       * ptr = lhs;
       break;
     }
     if(compar(lhs -> str ,rhs -> str) <= 0)
     {
        Order(ptr, &lhs);
     }
     else
     {
       Order(ptr, &rhs);
     }
     ptr = &((*ptr) -> next);
   }
   return(result);
}

void split(struct ListNode_st * source, struct ListNode_st ** start, struct ListNode_st ** end)
{
  struct ListNode_st * before;
  struct ListNode_st * after;
  if (source == NULL || source -> next == NULL)
  {
    *start  = source;
    *end = NULL;
  }
  else
  {
    before = source;
    after = source -> next;
    while(after != NULL)
    {
      after = after ->next;
      if(after != NULL)
      {
        before= before -> next;
        after = after -> next;
      }
    }
  *start = source;
  *end = before -> next;
  before -> next = NULL;
  }
}

List * List_sort( List * list, int(*compar)(const char *, const char *))
{
  struct ListNode_st * head = list;
  struct ListNode_st * One;
  struct ListNode_st * Two;

  if ((head == NULL) || (head ->  next == NULL))
  {
    return list;
  }
  split(head, &One, &Two);
  One = List_sort(One, compar);
  Two = List_sort(Two, compar);
  list = List_merge(One, Two, compar); 
  return(list);
}  
 
  


