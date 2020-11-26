#include "shell.h"
/**
 * main - funtion main
 * Return: Always 0
 */
int main(void)
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
		err = eval(input);
		free(input);
/* loop*/
	} while (!err);

	return (0);
}
