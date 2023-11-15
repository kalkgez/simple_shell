#include "shell.h"

/**
 * add_rvar_node - A function that adds
 * a variable node to the end of the variable
 * @head: A pointer to the head of the variable list
 * @lvar: Length of the variable name
 * @val: Pointer to the value string
 * @lval: Length of the value string
 * Return: A pointer to the head of the updated variable list
 */
r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval)
{
	r_var *form, *temp;

	form = malloc(sizeof(r_var));
	if (form == NULL)
		return (NULL);

	form->len_var = lvar;
	form->val = val;
	form->len_val = lval;

	form->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = form;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = form;
	}

	return (*head);
}

/**
 * free_rvar_list - A function that frees the memory allocated for the variable
 * @head: pointer to the head of the variable list
 * Return: void
 */
void free_rvar_list(r_var **head)
{
	r_var *temp;
	r_var *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}

