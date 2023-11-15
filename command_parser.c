#include "shell.h"

/**
 * swap_char - A function that swap characters in a string
 * @input: Input string
 * @bool: A boolean value indicating the swapping operation
 * Return: Modified sting after swapping characters.
 */

char *swap_char(char *input, int bool)
{
	int n;

	if (bool == 0)
	{
		for (n = 0; input[n]; n++)
		{
			if (input[n] == '|')
			{
				if (input[n + 1] != '|')
					input[n] = 16;
				else
					n++;
			}

			if (input[n] == '&')
			{
				if (input[n + 1] != '&')
					input[n] = 12;
				else
					n++;
			}
		}
	}
	else
	{
		for (n = 0; input[n]; n++)
		{
			input[n] = (input[n] == 16 ? '|' : input[n]);
			input[n] = (input[n] == 12 ? '&' : input[n]);
		}
	}
	return (input);
}

/**
 * add_nodes - A function that add nodes to linked lists
 * @head_s: pointer to the head of the separator
 * @head_l: Pointer to the head of the line nodes list
 * @input: Input string
 * Return: void
 **/

void add_nodes(sep_list **head_s, line_list **head_l, char *input)
{
	char *form;
	int n;

	input = swap_char(input, 0);
	for (n = 0; input[n]; n++)
	{
		if (input[n] == ';')
			add_sep_node_end(head_s, input[n]);

		if (input[n] == '|' || input[n] == '&')
		{
			add_sep_node_end(head_s, input[n]);
			n++;
		}
	}

	form = _strtok(input, ";|&");
	do {
		form = swap_char(form, 1);
		add_line_node_end(head_l, form);
		form = _strtok(NULL, ";|&");
	} while (form != NULL);

}

/**
 * go_next - A function that move to the next nodes in the lists
 * @list_s: A pointer to the separator node list
 * @list_l: Pointer to the line nodes list
 * @datash: A pointer to the data_shell struct
 * Return: void
 */
void go_next(sep_list **list_s, line_list **list_l, data_shell *datash)
{
	int loop_separator;
	sep_list *ls_s;
	line_list *ls_l;

	loop_separator = 1;
	ls_s = *list_s;
	ls_l = *list_l;

	while (ls_s != NULL && loop_separator)
	{
		if (datash->status == 0)
		{
			if (ls_s->separator == '&' || ls_s->separator == ';')
				loop_separator = 0;
			if (ls_s->separator == '|')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		else
		{
			if (ls_s->separator == '|' || ls_s->separator == ';')
				loop_separator = 0;
			if (ls_s->separator == '&')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		if (ls_s != NULL && !loop_separator)
			ls_s = ls_s->next;
	}

	*list_s = ls_s;
	*list_l = ls_l;
}

/**
 * split_commands - A function that split the input into commands
 * @datash: A pointer to the data shell struct
 * @input: Input string
 * Return: 0 if execution is successfull
 */
int split_commands(data_shell *datash, char *input)
{
	sep_list *head_s, *list_s;
	line_list *head_l, *list_l;
	int num;

	head_s = NULL;
	head_l = NULL;

	add_nodes(&head_s, &head_l, input);

	list_s = head_s;
	list_l = head_l;

	while (list_l != NULL)
	{
		datash->input = list_l->line;
		datash->args = split_line(datash->input);
		num = exec_line(datash);
		free(datash->args);

		if (num == 0)
			break;

		go_next(&list_s, &list_l, datash);

		if (list_l != NULL)
			list_l = list_l->next;
	}

	free_sep_list(&head_s);
	free_line_list(&head_l);

	if (num == 0)
		return (0);
	return (1);
}

/**
 * split_line - A function that split the input in to tokens
 * @input: Input string
 * Return: Array of tokens
 */
char **split_line(char *input)
{
	size_t size;
	size_t n;
	char **tokens;
	char *token;

	size = TOK_BUFSIZE;
	tokens = malloc(sizeof(char *) * (size));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	token = _strtok(input, TOK_DELIM);
	tokens[0] = token;

	for (n = 1; token != NULL; n++)
	{
		if (n == size)
		{
			size += TOK_BUFSIZE;
			tokens = _reallocdp(tokens, n, sizeof(char *) * size);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = _strtok(NULL, TOK_DELIM);
		tokens[n] = token;
	}

	return (tokens);
}

