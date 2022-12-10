#include "main.h"

int push(char *token, struct stack **head)
{
  struct stack *p = NULL;
  int n = atoi(token);
  if (!(p = malloc(sizeof(struct stack)))) exit (-2);
  p->n = n;
  p->next = (*head);
  (*head) = p;
  return 1;
}


void garbage_collector(struct stack *head)
{
  if (head)
  {
    garbage_collector(head->next);
    free(head);
  }
}