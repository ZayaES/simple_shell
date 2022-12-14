#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL
#define BUFSIZE 1024

#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>

void exec_process(char **path, char *line);
char **parsing_arg(char *line);
char *read_line(void);
int term_write(char *out);
void simple_shell(void);
void eval_com(char **f_com, char *i_com);

int _putchar(char c);
char **path_av(char **arg);
char **ph_to_dp(char *ph);
int number_of_dir(char *ph);
char *_getenv(char *name);

int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int _strlen(char *s);
char *_strcat(char *dest, char *src);

void _enviro(void);
void salto_linea(int n);
extern char **environ;
void _ext(void);

#endif
