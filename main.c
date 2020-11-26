#include "shell.h"
/**
 * main - funtion main
 * @argc: number of arguments but for now not passed arguments
 * @argv: the array of pointers to fill with set_argv
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int err = 0;
	char *input = 0;

	do {
		input = 0;
		/*print_prompt();*/
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
/* read*/
		err = read_line(&input);
		if (err < 0)
		{
			free(input);
			if (isatty(STDIN_FILENO))
				write(1, "\n", 1);
			exit(EXIT_SUCCESS);
		}
/* eval*/
		err = eval(input, argv[0]);
		free(input);
/* loop*/
	} while (!err);

	(void)argc;
	return (0);
}
