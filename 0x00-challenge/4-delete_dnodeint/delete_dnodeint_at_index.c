#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *prev_node;
	dlistint_t *tmp;
	unsigned int p;

	if (*head == NULL)
	{
		return (-1);
	}

	if (0 == index)
        {
                tmp = (*head)->next;
                free(*head);
                *head = tmp;
                if (tmp != NULL)
                {
                        tmp->prev = NULL;
                }
		return (1);
        }

	tmp = *head;
	p = 0;
	while (p < index && tmp != NULL)
	{
		prev_node = tmp;
		tmp = tmp->next;
		p++;
	}

	if (p != index || !tmp)
		return (-1);

	prev_node->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = prev_node;

	free(tmp);

	return (1);
}
