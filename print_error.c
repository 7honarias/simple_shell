#include "shell.h"

/**
 * print_error - prints a error
 * @count: the number of error
 * @command: the command that caused the error
 * @name: the name of this program
 */

void print_error(int count, char *name, char *command)
{
	char scount[150];

	tostring(scount, count);
	_puts(name);
	_puts(": ");
	_puts(scount);
	_puts(": ");
	_puts(command);
	_puts(": not found\n");
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

/**
 * tostring - convert int to array
 * @scount: array with the int to convert
 * @count: int to convert to string
 * Return: string
 */

char *tostring(char *scount, int count)
{
	int i, rem, len = 0, n;

	n = count;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	for (i = 0; i < len; i++)
	{
		rem = count % 10;
		count = count / 10;
		scount[len - (i + 1)] = rem + '0';
	}
	scount[len] = '\0';
	return (scount);
}
