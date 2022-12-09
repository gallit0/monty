#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
  int n;
  struct stack_s *prev;
  struct stack_s *next;
} stack;
#endif
