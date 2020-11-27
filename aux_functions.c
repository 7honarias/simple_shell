#include "shell.h"

/**
 * strip_line - remove the new line character
 * @line: input got from getline
 * Return: no return
 */

void strip_line(char *line)
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
 * tokenize_line - the string be will separate and be stored in the array
 * @line: input to break
 * @tokens: pointer to array
 * Return: Nothing
 */
void tokenize_line(char *line, char **tokens)
{
	const char *delim;
	char *token;
	int num_tokens;

	strip_line(line);
	delim = " ";
	token = strtok(line, delim);
	num_tokens = 0;

	while (token)
	{
		tokens[num_tokens] = token;

		token = strtok(NULL, delim);
		num_tokens++;
	}

}
/**
 * eval - manager the input and execute program
 * @input: string with the program to execute
 * @name: name of file
 * Return: 0, 1 or -1 if fail
 */

int eval(path_s *head, char *const tokens[])
{
	path_s *temp = head;
	char command[100];
	int i, j;

	while (temp)
	{
		for (j = 0; temp->s[j]; j++)
		{
			command[j] = temp->s[j];
		}
		command[j] = '/';

		j++;
		for (i = 0; tokens[0][i]; i++, j++)
		{
			command[j] = tokens[0][i];
		}
		command[j] = '\0';


		execve(command, tokens, NULL);

		temp = temp->next;
	}

	if (execve(tokens[0], tokens, NULL))
	{
		return(1);
	}
	return (0);

}
