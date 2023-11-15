#include "shell.h"

/**
 * _strdup - A function that duplicate a string
 * @s: A string to be duplicated
 * Return: A pointer to a newly allocated space
 */
char *_strdup(const char *s)
{
	char *main;
	size_t length;

	length = _strlen(s);
	main = malloc(sizeof(char) * (length + 1));
	if (main == NULL)
		return (NULL);
	_memcpy(main, s, length + 1);
	return (main);
}

/**
 * _strlen - A function that calculate the length og a string
 * @s: A string to calculate the length
 * Return: The length of the string
 */
int _strlen(const char *s)
{
	int length;

	for (length = 0; s[length] != 0; length++)
	{
	}
	return (length);
}

/**
 * cmp_chars - A function that compares characters
 * @str: A String to compare
 * @delim: Delimiter string
 *
 * Return: 1 if all characters in ‘str’ match
 */

int cmp_chars(char str[], const char *delim)
{
	unsigned int n, m, r;

	for (n = 0, r = 0; str[n]; n++)
	{
		for (m = 0; delim[m]; m++)
		{
			if (str[n] == delim[m])
			{
				r++;
				break;
			}
		}
	}
	if (n == r)
		return (1);
	return (0);
}
/**
 * _strtok - A function that tokenize a string
 * @str: A string to tokenized
 * @delim: A Delimiter string
 *
 * Return: A pointer to the next token found in ‘str’
 */

char *_strtok(char str[], const char *delim)
{
	static char *split, *end;
	char *start;
	unsigned int n, boolean;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		split = str;
		n = _strlen(str);
		end = &str[n];
	}
	start = split;
	if (start == end)
		return (NULL);
	for (boolean = 0; *split; split++)
	{
		if (split != start)
			if (*split && *(split - 1) == '\0')
				break;
		for (n = 0; delim[n]; n++)
		{
			if (*split == delim[i])
			{
				*split = '\0';
				if (split == start)
					start++;
				break;
			}
		}
		if (boolean == 0 && *split)
			boolean = 1;
	}
	if (boolean == 0)
		return (NULL);
	return (start);
}
/**
 * _isdigit - A function that check a character is a digit
 *
 * @s: A character to check
 * Return: 1 if the character is a digit, 0 otherwise
 */
int _isdigit(const char *s)
{
	unsigned int n;

	for (n = 0; s[n]; n++)
	{
		if (s[n] < 48 || s[n] > 57)
			return (0);
	}
	return (1);
}
