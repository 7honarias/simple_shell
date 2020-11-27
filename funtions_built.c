#include "shell.h"

/**
 * _builtin - function to find built-in
 * @tokens: arguments to enter
 * @list_built: names of the built-in
 * @num_erro: counter variable
 * @tofree: the struct that has de pointers to free
 * @name_file: name
 * Return: 0
 */
int _builtin(char **tokens, built_in *list_built, int num_erro
	     , tofree_s tofree, char *name_file)
{
	int i;

	for (i = 0; list_built[i].name; i++)
	{
		if ((_strcmp(list_built[i].name, tokens[0])) == 0)
		{
			return (list_built[i].func(tokens
						, num_erro, tofree, name_file));
		}
	}
	(void)num_erro;
	return (0);
}

/**
 * f_exit - function to implement exit built-in
 * @argv: arguments
 * @c: the counter to errors
 * @n: name
 * @tofree: the struct that has de pointers to free
 * Return: 0 or other number if fails
 */
int f_exit(char **argv, int c, tofree_s tofree, char *n)
{
	int status = 0, i = 0;
	char cstring[120];

	if (argv[1] != NULL)
	{
		for (i = 0; argv[1][i]; i++)
		{
			if (argv[1][i] < 48 || argv[1][i] > 57)
			{
				tostring(cstring, c);
				_puts(n);
				_puts(": ");
				_puts(cstring);
				_puts(": ");
				_puts("exit: Illegal number: ");
				_puts(argv[1]);
				_puts("\n");

				exit(2);
			}
		}
		for (i = 0; argv[1][i]; i++)
		{
			status = status * 10 + (argv[1][i] - '0');
		}
	}
	free_all(tofree);
	exit(status);
}

/**
 * f_env - prints the environment variables of this program
 * @argv: arguments
 * @c: the conter to errors
 * @n: name
 * @tofree: the struct that has de pointers to free
 * Return: 0 or other number if fails
 */
int f_env(char **argv, int c, tofree_s tofree, char *n)
{
	int i;

	if (argv[1] != NULL)
	{
		_puts(argv[0]);
		_puts(": ");
		_puts(argv[1]);
		_puts(": No such file or directory\n");
		return (-1);
	}
	for (i = 0; __environ[i] != NULL; i++)
	{
		_puts(__environ[i]);
		_puts("\n");
	}
	(void)n;
	(void)c;
	(void)tofree;
	return (1);
}

/**
 * free_all - this free all memory allocates
 * @tofree: the structs that contains the pointers
 *
 * Return: nothing
 */
void free_all(tofree_s tofree)
{
	free_PATH(tofree.f_header_PATH[0]);
	free(tofree.f_buff_line[0]);
	free(tofree.f_arguments[0]);
}
/**
 * _strcmp - compares two strings
 * Description: work exactly like strcmp
 * @s1: is the first string to comparate
 * @s2: is the second string to comparate
 * Return: returns one integer
 */
int _strcmp(char *s1, char *s2)
{
	int counter;

	for (counter = 0; s1[counter] != '\0'; counter++)
	{
		if (s1[counter] != s2[counter])
		{
			return (s1[counter] - s2[counter]);
		}
	}
	return (0);
}
