/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbohn-co <tbohn-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:53:24 by tbohn-co          #+#    #+#             */
/*   Updated: 2024/05/23 19:28:45 by tbohn-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_actions_with_cost_a_negative(t_list *a, t_list *b, t_node *node)
{
	if (node->cost_b < 0)
	{
		ft_rrr(a, b);
		node->cost_b++;
	}
	else if (node->cost_b > 0)
	{
		ft_reverse_rotate(a, 'a');
		ft_rotate(b, 'b');
		node->cost_b--;
	}
	else
		ft_reverse_rotate(a, 'a');
	node->cost_a++;
}

void	ft_actions_moving_only_b(t_list *b, t_node *node)
{
	if (node->cost_b > 0)
	{
		ft_rotate(b, 'b');
		node->cost_b--;
	}
	else
	{
		ft_reverse_rotate(b, 'b');
		node->cost_b++;
	}
}
