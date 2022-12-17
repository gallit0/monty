#include "main.h"


int line_command(char *buff, struct stack **head)
{
  int i = 0;
  char *token = strtok(buff, " \n");
  if (!(strcmp(token, "push")))
  {
    token = strtok(NULL, " \n");
    if (!token)
    {
      fprintf(stderr, "L%u: no number after push command\n", line_number);
      return 0;
    }
    for (unsigned int i = 0; token[i]; i++)
    {
      if (!isdigit(token[i]))
      {

        fprintf(stderr, "L%u: %s is not a number\n", line_number, token);
        return 0;
      }
    }
    push(token, head);
    return 1;
  }
  else if (!(strcmp(token, "pall")))
  {
    pall(head);
    return 1;
  }
  else if(!strcmp(token, "pint"))
  {
    pint(head);
    return 1;
  }
  else
  {
    fprintf(stderr, "L%u: <%s> command nonexisting\n", line_number, token);
    return 0;
  }
}


unsigned int line_number = 0;
char *buff = NULL;
char error[512];

int main(int ac, char **av)
{
  struct stack *head = NULL;
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
      token = strtok(strdup(buff), " \n");
      if (token)
      {
        if (!line_command(buff, &head)) break;
      }
      if (isat) write(1, "> ", 2);
  }
  garbage_collector(head);
  if (buff) free(buff);
  if (file) fclose(file);
  return (0);
}
