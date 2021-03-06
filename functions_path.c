#include "shell.h"

/**
 * _getenv - gets the value of an environment variable
 * @name: it's the name of the environment variable to find
 * Return: the value or NULL if not found
 */

char *_getenv(const char *name)
{
	char **p, *str;
	int i = 0, j = 0;

	for (p = __environ; *p; p++, i++)
	{
		str = *p;
		if (str[0] == name[0])
		{
			for (j = 0; str[j] != '='; j++)
			{
				if (str[j] != name[j])
					break;
			}
			if (str[j] == '=')
			{
				return (&str[j + 1]);
			}
		}
	}
	return (NULL);
}

/**
 * _print_PATH - print each directory passed as argument. one per line
 * @path: it's the path
 * Return: header
 */

path_s *create_linkedlist_path(char *path)
{
	path_s *header = NULL;
	char *token = NULL, *cp_path = NULL;
	int i, j;

	if (path == NULL)
	{
		return (NULL);
	}
	for (j = 0; path[j]; j++)
	{}
	cp_path = malloc(sizeof(char) * 1024);
	if (cp_path == NULL)
	{
		return (NULL);
	}
	for (i = 0; path[i]; i++)
	{
		cp_path[i] = path[i];
	}
	cp_path[i] = 0;
	token = strtok(cp_path, ":");
	while (token != NULL)
	{
		_new_node(token, &header);
		token = strtok(NULL, ":");
	}
	free(cp_path);
	return (header);
}

/**
 * _new_node - creates a new node in the linked list
 * @s: the string to save in the node
 * @head: it's the header of the linked list
 * Return void
 */

void _new_node(char *s, path_s **head)
{
	path_s *temp = NULL, *new = NULL;
	int i = 0;

	new = create_node(s);
	if (*head == NULL)
	{
		*head = new;
		return;
	}
	temp = *head;
	for (i = 0; temp->next; i++)
	{
		temp = temp->next;
	}
	temp->next = new;
}

/**
 * create_node - creates and initializes a new node
 * @s: the string to initializes the new node
 * Return: a pointer of the new node of NULL if fail
 */

path_s *create_node(char *s)
{
	path_s *new;
	int i;

	new = malloc(sizeof(path_s));
	if (new == NULL)
	{
		_puts("error creating node\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; s[i]; i++)
	{
	}
	new->s = malloc(sizeof(char) * i);
	if (new->s == NULL)
	{
		_puts("error creating node\n");
		free(new);
		exit(EXIT_FAILURE);
	}
	for (i = 0; s[i]; i++)
	{
		new->s[i] = s[i];
	}
	new->next = NULL;
	return (new);
}

/**
 * free_PATH - frees a listint_t list
 * @head: is the header of the linked list
 * Return: void
 */

void free_PATH(path_s *head)
{
	if (head)
	{
		free_PATH(head->next);
		free(head->s);
		free(head);
	}
}

