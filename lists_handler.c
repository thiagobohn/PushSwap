/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srmeneses <srmeneses@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:51:51 by tbohn-co          #+#    #+#             */
/*   Updated: 2024/04/07 17:40:29 by srmeneses        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

t_node	*ft_create_node(int val)
{
	t_node	*node;

	node = malloc(1 * sizeof(t_node));
	node->prev = NULL;
	node->next = NULL;
	node->val = val;
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
		if (list->begin == NULL)
			list->end = new;
		else
			list->begin->prev = new;
		list->begin = new;
	}
	else
	{
		new->prev = list->end;
		if (list->begin == NULL)
			list->begin = new;
		else
			list->end->next = new;
		list->end = new;
	}
	list->size++;
}

void	ft_remove(t_list *list, int position)
{
	t_node	*aux;

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
	list->size--;
}
