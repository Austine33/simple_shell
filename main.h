#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
extern char **environ;
char *getcmd(void);
int execute_args(char **tokens);
char **tokenise(char *line);
int cmd_exists(char **arr);
#endif
