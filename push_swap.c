/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbohn-co <tbohn-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:55:58 by tbohn-co          #+#    #+#             */
/*   Updated: 2024/05/22 11:28:32 by tbohn-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	ft_calculating_position(t_list *list);

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
		if(n1 < n3)
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
	ft_sort3(a);
	ft_calculating_position(a);
	ft_calculating_position(b);
}

static void	ft_calculating_position(t_list *list)
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
