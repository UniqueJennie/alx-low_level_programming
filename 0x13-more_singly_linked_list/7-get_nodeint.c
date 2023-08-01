#include "lists.h"

/**
 * get_nodeint_at_index - returns node at a particular index in linked list
 * @head: the first node in the linked list
 * @index: index of the node to return
 * Return: pointer to the node being searched for, or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *temp = head;

	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}

	return (temp ? temp : NULL);
}
