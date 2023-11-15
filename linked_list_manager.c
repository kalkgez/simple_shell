#include "shell.h"

/**
 * add_sep_node_end -  A function that adds a separator node
 * @head: A pointer to the head of the separator
 * @sep:  Separator character (; | &)
 * Return: Pointer to the head of the updated separator list.
 */
sep_list *add_sep_node_end(sep_list **head, char sep)
{
	sep_list *form, *temp;

	form = malloc(sizeof(sep_list));
	if (form == NULL)
		return (NULL);

	form->separator = sep;
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
 * free_sep_list - A function that frees the memory allocated
 * @head: A pointer to the head of the separator list
 * Return: void
 */
void free_sep_list(sep_list **head)
{
	sep_list *temp;
	sep_list *curr;

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

/**
 * add_line_node_end - A function that adds a line at the end of the line
 * @head: A pointer to the head of the line list
 * @line: A pointer to the line of the string
 * Return: Pointer to the head of the updated line
 */
line_list *add_line_node_end(line_list **head, char *line)
{
	line_list *form, *temp;

	form = malloc(sizeof(line_list));
	if (form == NULL)
		return (NULL);

	form->line = line;
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
 * free_line_list - A function that frees the memory allocated for the line
 * @head: A pointer to the head of the line list
 * Return: void
 */
void free_line_list(line_list **head)
{
	line_list *temp;
	line_list *curr;

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
