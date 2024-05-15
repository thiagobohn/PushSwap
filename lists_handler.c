/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbohn-co <tbohn-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:51:51 by tbohn-co          #+#    #+#             */
/*   Updated: 2024/05/15 12:54:19 by tbohn-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

t_node	*ft_create_node(int val)
{
	t_node	*node;

	node = malloc(1 * sizeof(t_node));
	node->val = val;
	node->index = 0;
	node->pos = 0;
	node->target_pos = 0;
	node->cost_a = 0;
	node->cost_a = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_list	*ft_create_list(void)
{
	t_list	*list;

	list = (t_list *)malloc(1 * sizeof(t_list));
	list->begin = NULL;
	list->end = NULL;
	list->size = 0;
	return (list);
}

void	ft_destroy_list(t_list **list_ref)
{
	t_list	*list;
	t_node	*current;
	t_node	*aux;

	list = *list_ref;
	current = list->begin;
	while (current != NULL)
	{
		aux = current;
		current = current->next;
		free(aux);
	}
	free(list);
	list_ref = NULL;
}

void	ft_add(t_list *list, int val, int position)
{
	t_node	*new;

	new = ft_create_node(val);
	if (position == FIRST)
	{
		new->next = list->begin;
		if (list->size == 0)
			list->end = new;
		else
			list->begin->prev = new;
		list->begin = new;
	}
	else
	{
		new->prev = list->end;
		if (list->size == 0)
			list->begin = new;
		else
			list->end->next = new;
		list->end = new;
	}
	list->size++;
	// printf("Lista: beg:%p end:%p size:%d\n", list->begin, list->end, list->size);
	// printf("Nó: endereço:%p prev:%p next:%p\n", new, new->prev, new->next);
}

void	ft_remove(t_list *list, int position)
{
	t_node	*aux;

	if (list->size == 1)
	{
		free(list->begin);
		list->begin = NULL;
	}
	else
	{
		if (position == FIRST)
		{	
			aux = list->begin->next;
			aux->prev = NULL;
			free(list->begin);
			list->begin = aux;
		}
		else
		{
			aux = list->end->prev;
			aux->next = NULL;
			free(list->end);
			list->end = aux;
		}	
	}
	list->size--;
}
