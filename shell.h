#ifndef __SHELL__
#define __SHELL__

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define TOKEN_LIMIT 1024
void print_prompt(void);
int read_line(char **input);
static void strip_line(char *line);
static int tokenize_line(char *line, char ***tokens);
int eval(char *input);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *src);

#endif
