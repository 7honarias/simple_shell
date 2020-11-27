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

/**
 * struct path - struct path
 * @s: it's the string
 * @next: it's the next node
 */

typedef struct path
{
	char *s;
	struct path *next;
} path_s;

/**
 * struct _free - struct that will have the pointers to free
 * @f_header_PATH: linked list that will have the PATH
 * @f_buff_line: string set by get line
 * @f_arguments: arguments to free
 */

typedef struct _free
{
	path_s **f_header_PATH;
	char **f_buff_line;
	char ***f_arguments;
} tofree_s;

/**
 * struct built - the struct to the built-ins
 * @name: the name of the built-in
 * @func: the function to the built-in
 */

typedef struct built
{
	char *name;
	int (*func)(char **argv, int c, tofree_s tofree, char *n);
} built_in;

/*PROTYPE FUNCTIONS*/

void strip_line(char *line);
void tokenize_line(char *input, char **tokens);
int eval(path_s *head, char *const tokens[]);
/* print error */
char *tostring(char *scount, int count);
void print_error(int count, char *name, char *command);
int _puts(char *str);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
/*path built in*/
int f_exit(char **argv, int c, tofree_s tofree, char *n);
int f_env(char **argv, int c, tofree_s tofree, char *n);
int _builtin(char **argv, built_in *b, int c, tofree_s t, char *n);
int _strcmp(char *s1, char *s2);
/*path*/
path_s *create_linkedlist_path(char *path);
void _new_node(char *s, path_s **head);
path_s *create_node(char *s);
void free_PATH(path_s *head);
char *_getenv(const char *name);
char **malloc_arguments(void);
void free_all(tofree_s tofree);

#endif
