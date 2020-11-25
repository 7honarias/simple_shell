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

/**
 * _strcpy - function that copies the string pointed to by
 * src
 * @dest: char*
 * @src: char *
 * Return: nothing
 */
char *_strcpy(char *dest, char *src)
{
	char a = 0;
	char b = 0;

	if (dest && src)
	{
		while (*(src + a))
			++a;
		if (src + a <= dest)
		{
			do {
				*(dest + b++) = *src++;
			} while (a--);
		}
		return (dest);
	}
	return (dest);
}
/**
 * _strdup - duplicates a string
 * @src: string to duplicate
 * Return: pointer to a string
 */
char *_strdup(char *src)
{
	char *dst = malloc(_strlen(src) + 1);

	if (dst == NULL)
		return (NULL);
	_strcpy(dst, src);
	return (dst);
}
