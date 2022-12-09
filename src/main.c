#include "main.h"


int line_command(char *token)
{
  int i = 0;

  if (!(strcmp(token, "push")))
  {
    token = strtok(NULL, " ");
    if (!token)
    {
      fprintf(stderr, "L%u: no number after push command\n", line_number);
      return 0;
    }
  }
  else return 0;
}


unsigned int line_number = 0;
char *buff = NULL;
char error[512];

int main(int ac, char **av)
{
  int isat = 1;
  size_t buffsize = 0;
  FILE *file = NULL;
  char *token = NULL;

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
      token = strtok(buff, " \n");
      if (*token)
      {
        if (!line_command(token)) break;
      }
      if (isat) write(1, "> ", 2);
  }
  if (buff) free(buff);
  if (file) fclose(file);
  return (0);
}

