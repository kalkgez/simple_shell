#include "shell.h"

/**
 * _strcat - A function that concatenates two strings
 * * @dest: The destination string
 * @src: The source string
 * Return: The pointer to the resulting string
*/
char *_strcat(char *dest, const char *src)
{
	int n;
	int m;

	for (n = 0; dest[n] != '\0'; n++)
		;

	for (m = 0; src[m] != '\0'; m++)
	{
		dest[n] = src[m];
		n++;
	}

	dest[n] = '\0';
	return (dest);
}
/**
 * *_strcpy - copies a string
 * @dest: The destination string
 * @src: The source string
 * Return: The pointer to the resulting string
 */
char *_strcpy(char *dest, char *src)
{
	size_t a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}
/**
 * _strcmp - Compare two strings
 * @s1: First string to compare
 * @s2: Second string to compare
 * Return: An integer
 */
int _strcmp(char *s1, char *s2)
{
	int n;

	for (n = 0; s1[n] == s2[n] && s1[n]; n++)
		;

	if (s1[n] > s2[n])
		return (1);
	if (s1[n] < s2[n])
		return (-1);
	return (0);
}
/**
 * _strchr - A function that locate first occurrence
 * @s: String to search
 * @c: Character to locate
 * Return: A pointer
 */
char *_strchr(char *s, char c)
{
	unsigned int n = 0;

	for (; *(s + n) != '\0'; n++)
		if (*(s + n) == c)
			return (s + n);
	if (*(s + n) == c)
		return (s + n);
	return ('\0');
}
/**
 * _strspn - A function that get the length of the prefix
 * @s: String to search in
 * @accept: String containing the character to match
 * Return: The number of characters
 */
int _strspn(char *s, char *accept)
{
	int n, m, boolean;

	for (n = 0; *(s + n) != '\0'; n++)
	{
		boolean = 1;
		for (m = 0; *(accept + m) != '\0'; m++)
		{
			if (*(s + n) == *(accept + m))
			{
				boolean = 0;
				break;
			}
		}
		if (boolean == 1)
			break;
	}
	return (n);
}
