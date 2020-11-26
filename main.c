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
		print_prompt();
/* read*/
		err = read_line(&input);
		if (err < 0)
		{
			free(input);
			break;
		}
/* eval*/
		err = eval(input);
		free(input);
/* loop*/
	} while (!err);

	return (0);
}
