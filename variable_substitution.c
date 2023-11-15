#include "shell.h"

/**
 * check_env - A function that check the environment for a specific variable
 * @h: A pointer to the struct
 * @in: Input string
 * @data: A pointer to the data shell struct
 * Return: void
 */
void check_env(r_var **h, char *in, data_shell *data)
{
	int row, con, m, value;
	char **_envr;

	_envr = data->_environ;
	for (row = 0; _envr[row]; row++)
	{
		for (m = 1, con = 0; _envr[row][con]; con++)
		{
			if (_envr[row][con] == '=')
			{
				value = _strlen(_envr[row] + con + 1);
				add_rvar_node(h, m, _envr[row] + con + 1, value);
				return;
			}

			if (in[m] == _envr[row][con])
				m++;
			else
				break;
		}
	}

	for (m = 0; in[m]; m++)
	{
		if (in[m] == ' ' || in[m] == '\t' || in[m] == ';' || in[m] == '\n')
			break;
	}

	add_rvar_node(h, m, NULL, 0);
}

/**
 * check_vars - A function that check for variable i the input string
 * @h: A pointer to the struct
 * @in: Input string
 * @st: String
 * @data: A pointer to the data shell struct
 * Return: The number of characters processed
 */
int check_vars(r_var **h, char *in, char *st, data_shell *data)
{
	int n, lst, lpd;

	lst = _strlen(st);
	lpd = _strlen(data->pid);

	for (n = 0; in[n]; n++)
	{
		if (in[n] == '$')
		{
			if (in[n + 1] == '?')
				add_rvar_node(h, 2, st, lst), n++;
			else if (in[n + 1] == '$')
				add_rvar_node(h, 2, data->pid, lpd), n++;
			else if (in[n + 1] == '\n')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[n + 1] == '\0')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[n + 1] == ' ')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[n + 1] == '\t')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[n + 1] == ';')
				add_rvar_node(h, 0, NULL, 0);
			else
				check_env(h, in + n, data);
		}
	}

	return (n);
}

/**
 * replaced_input - A function that replace variables in the input string
 *
 * @head: A pointer to the struct
 * @input: Input string
 * @new_input: New input string
 * @nlen: Length of the new input string
 * Return: The new input string with replaced variables
 */
char *replaced_input(r_var **head, char *input, char *new_input, int nlen)
{
	r_var *indx;
	int n, m, k;

	indx = *head;
	for (m = n = 0; n < nlen; n++)
	{
		if (input[m] == '$')
		{
			if (!(indx->len_var) && !(indx->len_val))
			{
				new_input[n] = input[m];
				m++;
			}
			else if (indx->len_var && !(indx->len_val))
			{
				for (k = 0; k < indx->len_var; k++)
					m++;
				n--;
			}
			else
			{
				for (k = 0; k < indx->len_val; k++)
				{
					new_input[n] = indx->val[k];
					n++;
				}
				m += (indx->len_var);
				n--;
			}
			indx = indx->next;
		}
		else
		{
			new_input[n] = input[m];
			m++;
		}
	}

	return (new_input);
}

/**
 * rep_var - Replace variables in the input string with their values
 *
 * @input: Input string
 * @datash: A pointer to the data shell struct
 * Return: The modified input string with replaced variable
 */
char *rep_var(char *input, data_shell *datash)
{
	r_var *head, *indx;
	char *status, *new_input;
	int olen, nlen;

	status = aux_itoa(datash->status);
	head = NULL;

	olen = check_vars(&head, input, status, datash);

	if (head == NULL)
	{
		free(status);
		return (input);
	}

	indx = head;
	nlen = 0;

	while (indx != NULL)
	{
		nlen += (indx->len_val - indx->len_var);
		indx = indx->next;
	}

	nlen += olen;

	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[nlen] = '\0';

	new_input = replaced_input(&head, input, new_input, nlen);

	free(input);
	free(status);
	free_rvar_list(&head);

	return (new_input);
}
