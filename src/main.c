#include "main.h"


unsigned int line_number = 0;
char *buff = NULL;

int main(int ac, char **av)
{
  int isat = 1;
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
      line_number++;
      char *token = strtok(buff, " ");
      if(!(line_command(token))) break;
      if (isat) write(1, "> ", 2);
  }
  if (buff) free(buff);
  if (file) fclose(file);
  return (0);
}


int line_command(char *token)
{
  if (!(strcmp(token, "push")))
  {
    token = strtok(NULL, " ");
    if (!token) return 0;
  }

  else return 0;
  return 1;
}