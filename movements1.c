/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbohn-co <tbohn-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:51:21 by tbohn-co          #+#    #+#             */
/*   Updated: 2024/05/16 16:03:15 by tbohn-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_swap(t_list *list, char stack)
{
	list->begin = list->begin->next;
	list->begin->prev->next = list->begin->next;
	list->begin->prev->prev = list->begin;
	list->begin->next->prev = list->begin->prev;
	list->begin->next = list->begin->prev;
	list->begin->prev = NULL;
	if (stack == 'a')
		write(STDOUT_FILENO, "sa\n", 3);
	else if (stack == 'b')
		write(STDOUT_FILENO, "sb\n", 3);
}

void	ft_ss(t_list *a, t_list *b)
{
	ft_swap(a, 's');
	ft_swap(b, 's');
	write(STDOUT_FILENO, "ss\n", 3);
}

void	ft_push(t_list *l1, t_list *l2, char stack)
{
	ft_add(l2, l1->begin->val, FIRST);
	ft_remove(l1, FIRST);
	if (stack == 'a')
		write(STDOUT_FILENO, "pa\n", 3);
	else
		write(STDOUT_FILENO, "pb\n", 3);
}

void	ft_rotate(t_list *list, char stack)
{
	ft_add(list, list->begin->val, LAST);
	ft_remove(list, FIRST);
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
