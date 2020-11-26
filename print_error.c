#include "shell.h"
/**
 * print_error - prints a error
 * @name: the name of this program
 */
void print_error(char *name)
{
	_puts(name);
	_puts(": ");
	_puts("No such file or directory\n");

	exit(127);
}
/**
 * _puts - function to print string
 * @str: string to print
 * Return: write macro
 */
int _puts(char *str)
{
	int len;

	if (str == NULL)
		str = "(null)";

	for (len = 0; str[len] != '\0'; len++)
	{
	}
	return (write(1, str, len));
}
