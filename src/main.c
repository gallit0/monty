#include "main.h"


int main(int ac, char **av)
{
  int isat = 1;
  char *buff = NULL;
  size_t buffsize = 0;
  FILE *file = NULL;

  if (ac >= 2)
  {
    if (!(file = fopen(av[1], "r"))) exit(1);
    isat = 0;
  }
  else file = stdin;

  if (isat) write(1, "> ", 2);
  while (getline(&buff, &buffsize, file) >= 0)
  {
      if (isat) write(1, "> ", 2);
      puts(buff);
  }
  free(buff);
  fclose(file);
  return (0);
}