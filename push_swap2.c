/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbohn-co <tbohn-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:01:49 by tbohn-co          #+#    #+#             */
/*   Updated: 2024/05/22 19:04:59 by tbohn-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	ft_define_node_costs(t_list *list_a, t_node *node_b, int size_b);
static int	ft_define_total_cost(t_node *node);

int	ft_calculating_costs(t_list *a, t_list *b)
{
	int		cheaper;
	int		cheaper_pos;
	int		cost;
	t_node	*node_b;

	cheaper = INT_MAX;
	node_b = b->begin;
	while (node_b)
	{
		ft_define_node_costs(a, node_b, b->size);
		cost = ft_define_total_cost(node_b);
		if (cost == 0)
			return (node_b->pos);
		if (cost < cheaper)
		{
			cheaper = cost;
			cheaper_pos = node_b->pos;
		}
		node_b = node_b->next;
	}
	return (cheaper_pos);
}

static void	ft_define_node_costs(t_list *list_a, t_node *node_b, int size_b)
{
	int		mid_a;
	int		mid_b;
	t_node	*node_a;

	mid_a = list_a->size / 2;
	mid_b = size_b / 2;
	if (node_b->pos > mid_b)
		node_b->cost_b = node_b->pos - size_b;
	else
		node_b->cost_b = node_b->pos;
	node_a = list_a->begin;
	while (node_a->pos != node_b->target_pos)
		node_a = node_a->next;
	if (node_a->pos > mid_a)
		node_b->cost_a = node_a->pos - list_a->size;
	else
		node_b->cost_a = node_a->pos;
}

static int	ft_define_total_cost(t_node *node)
{
	if (node->cost_a > 0)
	{
		if (node->cost_b > 0)
		{
			if (node->cost_a > node->cost_b)
				return (node->cost_a);
			else
				return (node->cost_b);
		}
		else
			return (node->cost_a - node->cost_b);
	}
	else
	{
		if (node->cost_b < 0)
		{
			if (node->cost_a < node->cost_b)
				return (-node->cost_a);
			else
				return (-node->cost_b);
		}
		else
			return (node->cost_b - node->cost_a);
	}
}
