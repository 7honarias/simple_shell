#include "shell.h"

/**
 * main - funtion main
 * @argc: number of arguments but for now not passed arguments
 * @argv: the array of pointers to fill with set_argv
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	path_s *header_PATH = NULL;
	int status, err = 0;
	ssize_t sizes_line = 0;
	char *input = NULL, **tokens = NULL;
	size_t len = 0;

	built_in builtin_list[] = {{"exit", f_exit}, {"env", f_env}, {"NULL", NULL}};
	tofree_s tofree;

	tofree.f_buff_line = &input;
	tofree.f_header_PATH = &header_PATH;
	tofree.f_arguments = &tokens;
	tokens = malloc_arguments();
	header_PATH = create_linkedlist_path(_getenv("PATH"));
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		err++;
		sizes_line = getline(&input, &len, stdin);
		if (sizes_line < 0)
		{
			free_all(tofree);
			if (isatty(STDIN_FILENO))
				write(1, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		tokenize_line(input, tokens);
		if (tokens[0] != NULL)
			if (_builtin(tokens, builtin_list, err, tofree, argv[0]) == 0)
				if (fork() == 0)
					if (eval(header_PATH, tokens) != 0)
						print_error(err, argv[0], tokens[0]);
		wait(&status);
	}
	(void)argc;
	return (WEXITSTATUS(status));
}

/**
 * malloc_arguments - function to set memory to arguments
 * Return: arguments
 */

char **malloc_arguments(void)
{
	char **tokens = NULL;

	tokens = malloc(sizeof(tokens) * 120);
	if (tokens == NULL)
	{
		_puts("fail memory allocation\n");
		exit(EXIT_FAILURE);
	}
	return (tokens);
}
