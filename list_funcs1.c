#include "monty.h"

/**
<<<<<<< HEAD
 * dlistint_len - returns the number of nodes in a doubly linked list.
 * @h:a link to the list
 * Return: total number of nodes.
=======
 * dlistint_len - returns the number of doubly linked list nodes
 * @h: a reference to the list
 *
 * Return: the number of nodes.
 *
>>>>>>> a276b32c74361b72a94bfdb9e14bfd04e6a8651b
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t nodes = 0;

	if (!h)
		return (0);

	while (h)
	{
		nodes++;
		h = h->next;
	}

	return (nodes);
}

/**
<<<<<<< HEAD
 * add_dnodeint - inserts a new node at the beginning of the list.
 * a double linked list
 * @head: a list with two pointers
 * @n: the information to be entered into the new node
 * Return: the address of the new element, or NULL if it failed.
=======
 * add_dnodeint - inserts a new node at the start of
 * a doubly linked list.
 * @head: a list with a double pointer
 * @n: the data to be inserted into the new node
 *
 * Return: the new element's address, or NULL if it failed.
 *
>>>>>>> a276b32c74361b72a94bfdb9e14bfd04e6a8651b
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	if (!head)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);

	new->n = n;

	new->next = *head;
	new->prev = NULL;

	if (*head)
		(*head)->prev = new;

	*head = new;

	return (new);
}

/**
<<<<<<< HEAD
 * print_dlistint - returns a double link list
 * @h: a list pointer
 * Return:the numb of nodes in the list.
=======
 * print_dlistint - returns a doubly linked list
 * @h: pointer to the list
 *
 * Return: the number of nodes in the list
 *
>>>>>>> a276b32c74361b72a94bfdb9e14bfd04e6a8651b
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t nodes = 0;

	if (!h)
		return (0);

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		nodes++;
	}

	return (nodes);
}

/**
<<<<<<< HEAD
 * delete_dnodeint_at_index - removes a node at a specified index.
 * A doubly linked list index.
 * @head: a list with double  pointers
 * @index: the index of the node to be destroyed
 * Return: if successful -1, otherwise return -1.
=======
 * delete_dnodeint_at_index - deletes a node at a given
 * index in a doubly linked list.
 * @head: a list with a double pointer
 * @index: the node to be deleted's index
 *
 * Return: 1 if successful, -1 if unsuccessful.
 *
>>>>>>> a276b32c74361b72a94bfdb9e14bfd04e6a8651b
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp = *head;
	unsigned int i = 0;

	if (!index)
	{
		(*head) = temp->next;
		if (temp->next)
			temp->next->prev = NULL;
		temp->next = NULL;
		free(temp);
		return (1);
	}

	while (i < index)
	{
		temp = temp->next;
		i++;
		if (!temp)
			return (0);
	}

	temp->prev->next = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;
	free(temp);

	return (1);
}

/**
<<<<<<< HEAD
 * get_dnodeint_at_index - retrieves the nth node in a doubly linked list.
 * @head: a pointer to a list
 * @index: the index of the node to return
 * Return: the address of the node, or NULL if it does not exist.
=======
 * get_dnodeint_at_index - returns the nth doubly linked list node.
 * @head: a list pointer
 * @index: the node index to return
 *
 * Return the node's address, or NULL if it does not exist.
 *
>>>>>>> a276b32c74361b72a94bfdb9e14bfd04e6a8651b
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (!head)
		return (NULL);

	while (head && i < index)
	{
		head = head->next;
		i++;
	}

	return (head ? head : NULL);
}
<<<<<<< HEAD

=======
>>>>>>> a276b32c74361b72a94bfdb9e14bfd04e6a8651b
