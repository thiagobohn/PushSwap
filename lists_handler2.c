/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_handler2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbohn-co <tbohn-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:22:21 by tbohn-co          #+#    #+#             */
/*   Updated: 2024/05/16 13:26:06 by tbohn-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static int	ft_find_next_min(t_list *list);

void	ft_assigning_indexes(t_list *list)
{
	int		i;
	int		count;
	int		position;
	t_node	*node;

	i = 0;
	while (++i < list->size)
	{
		node = list->begin;
		position = ft_find_next_min(list);
		count = 0;
		while (++count <= position)
			node = node->next;
		node->index = i;
	}
	node = list->begin;
	while (node->index != -1)
		node = node ->next;
	node->index = i;	
}

static int	ft_find_next_min(t_list *list)
{
	int		min;
	int		position;
	int		count;
	t_node	*node;

	min = INT_MAX;
	count = 0;
	node = list->begin;
	while (node != NULL)
	{
		if (node->index == -1 && node->val < min)
		{
			min = node->val;
			position = count;
		}
		node = node->next;
		count++;
	}
	return (position);
}