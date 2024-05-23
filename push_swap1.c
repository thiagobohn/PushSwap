/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbohn-co <tbohn-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:55:58 by tbohn-co          #+#    #+#             */
/*   Updated: 2024/05/23 19:13:54 by tbohn-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	ft_calculat_position(t_list *list);
static void	ft_define_targets(t_list *a, t_list *b);
static int	ft_find_target_position(t_node *node, int index);

void	ft_sort3(t_list *list)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = list->begin->val;
	n2 = list->begin->next->val;
	n3 = list->end->val;
	if (n1 < n2 && n2 > n3)
	{
		ft_reverse_rotate(list, 'a');
		if (n1 < n3)
			ft_swap(list, 'a');
	}
	else
	{
		if (n1 > n3)
		{
			ft_rotate(list, 'a');
			if (n2 > n3)
				ft_swap(list, 'a');
		}
		else
			ft_swap(list, 'a');
	}
}

void	ft_push_swap(t_list *a, t_list *b)
{
	while (a->size > 3)
		ft_push(a, b, 'b');
	if (!ft_is_sorted(a))
		ft_sort3(a);
	while (b->size > 0)
	{
		ft_calculat_position(a);
		ft_calculat_position(b);
		ft_define_targets(a, b);
		ft_execute_action_sequence(a, b, ft_calculating_costs(a, b));
	}
	if (a->begin->index != 1 && a->begin->pos < a->size / 2)
	{
		while (a->begin->index != 1)
			ft_reverse_rotate(a, 'a');
	}
	else
	{
		while (a->begin->index != 1)
			ft_rotate(a, 'a');
	}
}

static void	ft_calculat_position(t_list *list)
{
	t_node	*node;
	int		count;

	node = list->begin;
	count = 0;
	while (node)
	{
		node->pos = count++;
		node = node->next;
	}
}

static void	ft_define_targets(t_list *a, t_list *b)
{
	t_node	*node;

	node = b->begin;
	while (node)
	{
		node->target_pos = ft_find_target_position(a->begin, node->index);
		node = node->next;
	}
}

static int	ft_find_target_position(t_node *node, int index)
{
	int	target_pos;
	int	next_index;
	int	lowest_index;

	lowest_index = INT_MAX;
	next_index = INT_MAX;
	while (node)
	{
		if (node->index > index && node->index < next_index)
		{
			target_pos = node->pos;
			next_index = node->index;
		}
		else if (next_index == INT_MAX && node->index < lowest_index)
		{
			target_pos = node->pos;
			lowest_index = node->index;
		}
		if (node->index == index + 1)
			return (target_pos);
		node = node->next;
	}
	return (target_pos);
}
