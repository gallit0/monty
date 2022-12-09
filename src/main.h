#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern unsigned int line_number;
extern char *buff;
extern char error[];

typedef struct stack
{
  int n;
  struct stack_s *next;
} stack;

#endif
