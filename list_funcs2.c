#include "monty.h"
#include "lists.h"

/**
<<<<<<< HEAD
 * insert_dnodeint_at_index - inserts a node into a graph.
 * doubly linked list at a specific index.
 * @h: a list with doubly pointers
 * @idx: the node index into which to insert
 * @n: the information to be entered
 * Return: the address of the new node, or NULL if it failed.
=======
 * insert_dnodeint_at_index - inserts a node in a
 * doubly linked list at a given index.
 * @h: a list with a double pointer
 * @idx: the node index to insert
 * @n: the data to be inserted
 *
 * Return the new node's address, or NULL if it failed.
 *
>>>>>>> a276b32c74361b72a94bfdb9e14bfd04e6a8651b
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i;
	dlistint_t *new;
	dlistint_t *temp = *h;

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (i = 0; temp && i < idx; i++)
	{
		if (i == idx - 1)
		{
			if (temp->next == NULL)
				return (add_dnodeint_end(h, n));
			new = malloc(sizeof(dlistint_t));
			if (!new || !h)
				return (NULL);
			new->n = n;
			new->next = NULL;
			new->next = temp->next;
			new->prev = temp;
			temp->next->prev = new;
			temp->next = new;
			return (new);
		}
		else
			temp = temp->next;
	}

	return (NULL);
}

/**
<<<<<<< HEAD
 * add_dnodeint_end - Adds a node to the end of a doubly linked list.
 * @head: a list with two pointers
 * @n: the information to be entered into the new node
 * Return:the address of the new element, or NULL if it failed.
=======
 * add_dnodeint_end – Inserts a new node at the end of a doubly linked list.
 * @head: a list with a double pointer
 * @n: the data to be inserted into the new node
 *
 * Return: the new element's address, or NULL if it failed.
 *
>>>>>>> a276b32c74361b72a94bfdb9e14bfd04e6a8651b
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *temp = *head;

	if (!head)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new;
	new->prev = temp;

	return (new);
}

/**
<<<<<<< HEAD
 * free_dlistint - removes a doubly linked list.
=======
 * free_dlistint - Destroys a doubly linked list.
>>>>>>> a276b32c74361b72a94bfdb9e14bfd04e6a8651b
 * @head: a reference to the list to be freed.
 *
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
<<<<<<< HEAD

=======
>>>>>>> a276b32c74361b72a94bfdb9e14bfd04e6a8651b
