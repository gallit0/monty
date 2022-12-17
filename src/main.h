#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern unsigned int line_number;
extern char *buff;
extern char error[];

struct stack {
  int n;
  struct stack *next;
};

int push(char *token, struct stack **head);
int pall(struct stack(**head));

void garbage_collector(struct stack *head);

#endif
