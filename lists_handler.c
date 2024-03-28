/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbohn-co <tbohn-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:51:51 by tbohn-co          #+#    #+#             */
/*   Updated: 2024/03/28 16:23:04 by tbohn-co         ###   ########.fr       */
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

void	ft_add_begin(t_list *list, int val)
{
	t_node	*new;

	new = ft_create_node(val);
	new->next = list->begin;
	if (list->begin == NULL)
		list->end = new;
	else
		list->begin->prev = new;
	list->begin = new;
}

void	ft_remove_first(t_list *list)
{
	t_node	*aux;

	aux = list->begin->next;
	aux->prev = NULL;
	free(list->begin);
	list->begin = aux;
}
