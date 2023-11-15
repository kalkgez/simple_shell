#include "shell.h"

/**
 * get_len - A function the get the length of an integer
 * @n: An integer value
 * Return: Length of the integer
 */
int get_len(int n)
{
	unsigned int r;
	int length = 1;

	if (n < 0)
	{
		length++;
		r = n * -1;
	}
	else
	{
		r = n;
	}
	while (r > 9)
	{
		length++;
		r = r / 10;
	}

	return (length);
}
/**
 * aux_itoa - A function that convert an integer to a string
 * @n: Integer value
 * Return: A pointer to the resulting sting
 */
char *aux_itoa(int n)
{
	unsigned int r;
	int length = get_len(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (length + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + length) = '\0';

	if (n < 0)
	{
		r = n * -1;
		buffer[0] = '-';
	}
	else
	{
		r = n;
	}

	length--;
	do {
		*(buffer + length) = (r % 10) + '0';
		r = r / 10;
		length--;
	}
	while (r > 0)
		;
	return (buffer);
}
/**
 * _atoi - A function that convert a string to an integer
 * @s: A string to convert
 * Return: The converted integer value
 */
int _atoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, n;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}

	for (n = count - size; n < count; n++)
	{
		oi = oi + ((*(s + n) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}
