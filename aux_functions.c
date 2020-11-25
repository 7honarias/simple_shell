#include "shell.h"

/**
 * strip_line - remove the new line character
 * @line: input got from getline
 * Return: no return
 */

static void strip_line(char *line)
{
	size_t len = _strlen(line);
	size_t end = len - 1;

	while (1)
	{
		if (line[end] == '\n')
			line[end] = '\0';
		if (end == 0)
			break;
		end--;
	}

	if (line[end] == '\n')
		line[end] = '\0';
}

/**
 * print_prompt - prints the prompt
 * Return: no return
 */

void print_prompt(void)
{
	printf("$ ");
}

/**
 * read_line - read the line from the standar input
 * @input: string when the input will be stored
 * Return: no return
 */

int read_line(char **input)
{
	size_t len;
	int char_read = getline(input, &len, stdin);

	return (char_read);
}

/**
 * _strlen - return the length the a string
 * @s: is the pointer the variable "n"
 * Return: Always 1 (Success)
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != 0; i++)
	{
	}
	return (i);
}
