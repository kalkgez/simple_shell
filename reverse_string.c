#include "shell.h"

/**
 * rev_string - A function that reverse a string
 * @s: A string to reverse
 * Return: void
 */
void rev_string(char *s)
{
	int _count = 0, n, m;
	char *string, temporary;

	while (_count >= 0)
	{
		if (s[_count] == '\0')
			break;
		_count++;
	}
	string = s;

	for (n = 0; n < (_count - 1); n++)
	{
		for (m = n + 1; m > 0; m--)
		{
			temporary = *(string + m);
			*(string + m) = *(string + (m - 1));
			*(string + (m - 1)) = temporary;
		}
	}
}
