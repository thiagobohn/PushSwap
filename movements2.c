/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbohn-co <tbohn-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:18:48 by tbohn-co          #+#    #+#             */
/*   Updated: 2024/05/23 19:18:23 by tbohn-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_reverse_rotate(t_list *list, char stack)
{
	t_node	*node;

	node = list->end;
	list->end = list->end->prev;
	list->end->next = NULL;
	node->next = list->begin;
	node->prev = NULL;
	list->begin->prev = node;
	list->begin = node;
	if (stack == 'a')
		write(STDOUT_FILENO, "rra\n", 4);
	else if (stack == 'b')
		write(STDOUT_FILENO, "rrb\n", 4);
}

void	ft_rrr(t_list *a, t_list*b)
{
	ft_reverse_rotate(a, 'r');
	ft_reverse_rotate(b, 'r');
	write(STDOUT_FILENO, "rrr\n", 4);
}

void	ft_rotate(t_list *list, char stack)
{
	t_node	*node;

	node = list->begin;
	list->begin = list->begin->next;
	list->begin->prev = NULL;
	list->end->next = node;
	node->prev = list->end;
	node->next = NULL;
	list->end = node;
	if (stack == 'a')
		write(STDOUT_FILENO, "ra\n", 3);
	else if (stack == 'b')
		write(STDOUT_FILENO, "rb\n", 3);
}

void	ft_rr(t_list *a, t_list*b)
{
	ft_rotate(a, 'r');
	ft_rotate(b, 'r');
	write(STDOUT_FILENO, "rr\n", 3);
}
