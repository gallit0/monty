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

int pall(struct stack(**head))
{
  struct stack *p = (*head);
  if (!p)
  {
    puts("NULL");
    return 1;
  }
  while(p)
  {
    printf("%i\n", p->n);
    p = p->next;
  }
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