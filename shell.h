#ifndef __SHELL__
#define __SHELL__

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define TOKEN_LIMIT 1024
int read_line(char **input);
void strip_line(char *line);
int tokenize_line(char *line, char ***tokens);
int eval(char *input, char *name);
int _strlen(char *s);
int _puts(char *str);
void print_error(char *name);
char *_strcpy(char *dest, char *src);
char *_strdup(char *src);

#endif
