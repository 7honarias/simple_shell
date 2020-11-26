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
	size_t len = 50;
	int char_read = 0;

	char_read = getline(input, &len, stdin);

	return (char_read);
}

/**
 * tokenize_line - the string be will separate and be stored in the array
 * @line: input to break
 * @tokens: pointer to array
 * Return: tokens number
 */

int tokenize_line(char *line, char ***tokens)
{
	const char *delim;
	char *token;
	int num_tokens;

	strip_line(line);
	delim = " ";
	token = strtok(line, delim);
	num_tokens = 0;

	*tokens = malloc(sizeof(char *) * TOKEN_LIMIT);
	/**tokens = calloc(TOKEN_LIMIT, sizeof(char *));*/
	while (token)
	{
		(*tokens)[num_tokens++] = token;

		if (num_tokens == TOKEN_LIMIT)
			return (-1);

		token = strtok(NULL, delim);
	}

	return (num_tokens);
}

/**
 * eval - manager the input and execute program
 * @input: string with the program to execute
 * Return: 0, 1 or -1 if fail
 */

int eval(char *input)
{
	char **tokens;
	char *input_dup = _strdup(input);
	int num_tokens = tokenize_line(input_dup, &tokens);
	pid_t pid;
	int status;


	if (num_tokens == 0)
	{
		free(tokens);
		free(input_dup);
		return (0);
	}
	if (num_tokens < 0)
	{
		free(tokens);
		free(input_dup);
		printf("Huge number of tokens\n");
		return (-1);
	}

	pid = fork();

	if (pid > 0)
	{
		waitpid(pid, &status, 0);
		free(input_dup);
		free(tokens);
		if (WIFEXITED(status))
			return (0);
		else
			return (1);
	}
	else
	{
		execve(tokens[0], tokens, NULL);
	}
	return (0);
}
