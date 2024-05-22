/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbohn-co <tbohn-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:51:21 by tbohn-co          #+#    #+#             */
/*   Updated: 2024/05/22 11:15:21 by tbohn-co         ###   ########.fr       */
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
	t_node	*node;

	node = l1->begin;
	if (l1->begin->next)
	{
		l1->begin = l1->begin->next;
		l1->begin->prev = NULL;
	}
	else
		l1->begin = NULL;
	if (l2->begin)
	{
		node->next = l2->begin;
		l2->begin->prev = node;
	}
	else
		node->next = NULL;
	l2->begin = node;
	if (stack == 'a')
		write(STDOUT_FILENO, "pa\n", 3);
	else
		write(STDOUT_FILENO, "pb\n", 3);
	l1->size--;
	l2->size++;
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
