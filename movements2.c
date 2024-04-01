/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbohn-co <tbohn-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:18:48 by tbohn-co          #+#    #+#             */
/*   Updated: 2024/04/01 17:14:11 by tbohn-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_reverse_rotate(t_list *list, char stack)
{
	ft_add(list, list->end->val, FIRST);
	ft_remove(list, LAST);
	if (stack == 'a')
		write(STDOUT_FILENO, "rra", 3);
	else if (stack == 'b')
		write(STDOUT_FILENO, "rrb", 3);
}

void	ft_rrr(t_list *a, t_list*b)
{
	ft_reverse_rotate(a, 'r');
	ft_reverse_rotate(b, 'r');
	write(STDOUT_FILENO, "rrr", 3);
}