#include "shell.h"

/**
 * repeated_char - A function that count the number of repeated
 * @input: The input spring
 * @i: The current index
 * Return: The count of repeated character
 */
int repeated_char(char *input, int i)
{
	if (*(input - 1) == *input)
		return (repeated_char(input - 1, i + 1));

	return (i);
}

/**
 * error_sep_op - A function that check for syntax
 * errors related to separator operation
 * @input: The input string
 * @i: The current index
 * @last: The last character
 * Return: The index when the error occur
 */
int error_sep_op(char *input, int i, char last)
{
	int _count;

	_count = 0;
	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
		return (error_sep_op(input + 1, i + 1, last));

	if (*input == ';')
		if (last == '|' || last == '&' || last == ';')
			return (i);

	if (*input == '|')
	{
		if (last == ';' || last == '&')
			return (i);

		if (last == '|')
		{
			_count = repeated_char(input, 0);
			if (_count == 0 || _count > 1)
				return (i);
		}
	}

	if (*input == '&')
	{
		if (last == ';' || last == '|')
			return (i);

		if (last == '&')
		{
			_count = repeated_char(input, 0);
			if (_count == 0 || _count > 1)
				return (i);
		}
	}

	return (error_sep_op(input + 1, i + 1, *input));
}

/**
 * first_char - A function that find the first valid character in a string
 * @input: The input string
 * @i: A pointer to store
 * Return: 0 if a valid character is found
 */
int first_char(char *input, int *i)
{
	for (*i = 0; input[*i]; *i += 1)
	{
		if (input[*i] == ' ' || input[*i] == '\t')
			continue;

		if (input[*i] == ';' || input[*i] == '|' || input[*i] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * print_syntax_error - A function that print a syntax error message
 * @datash: A pointer to the data shell
 * @input: The input string
 * @i: The index
 * @bool: A flag indicating if the error is related
 * Return: void
 */
void print_syntax_error(data_shell *datash, char *input, int i, int bool)
{
	char *msg, *msg2, *msg3, *errorMessage, *counter;
	int length;

	if (input[i] == ';')
	{
		if (bool == 0)
			msg = (input[i + 1] == ';' ? ";;" : ";");
		else
			msg = (input[i - 1] == ';' ? ";;" : ";");
	}

	if (input[i] == '|')
		msg = (input[i + 1] == '|' ? "||" : "|");

	if (input[i] == '&')
		msg = (input[i + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax error: \"";
	msg3 = "\"unexpected\n";
	counter = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(counter);
	length += _strlen(msg) + _strlen(msg2) + _strlen(msg3) + 2;

	errorMessage = malloc(sizeof(char) * (length + 1));
	if (errorMessage == 0)
	{
		free(counter);
		return;
	}
	_strcpy(errorMessage, datash->av[0]);
	_strcat(errorMessage, ": ");
	_strcat(errorMessage, counter);
	_strcat(errorMessage, msg2);
	_strcat(errorMessage, msg);
	_strcat(errorMessage, msg3);
	_strcat(errorMessage, "\0");

	write(STDERR_FILENO, errorMessage, length);
	free(errorMessage);
	free(counter);
}

/**
 * check_syntax_error - A function check for syntax error in the input string
 * @datash: A pointer to the data shell
 * @input: The input string
 * Return: 1 if a syntax error is found
 */
int check_syntax_error(data_shell *datash, char *input)
{
	int startingIndex = 0;
	int firstValidChar = 0;
	int i = 0;

	firstValidChar = first_char(input, &startingIndex);
	if (firstValidChar == -1)
	{
		print_syntax_error(datash, input, startingIndex, 0);
		return (1);
	}

	i = error_sep_op(input + startingIndex, 0, *(input + startingIndex));
	if (i != 0)
	{
		print_syntax_error(datash, input, startingIndex + i, 1);
		return (1);
	}

	return (0);
}
