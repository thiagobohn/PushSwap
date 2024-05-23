/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbohn-co <tbohn-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:51:21 by tbohn-co          #+#    #+#             */
/*   Updated: 2024/05/23 19:23:24 by tbohn-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	ft_pushs_moviments_in_l1(t_list *l1);
static void	ft_pushs_moviments_in_l2(t_list *l2, t_node *node);

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
	ft_pushs_moviments_in_l1(l1);
	ft_pushs_moviments_in_l2(l2, node);
	if (stack == 'a')
		write(STDOUT_FILENO, "pa\n", 3);
	else
		write(STDOUT_FILENO, "pb\n", 3);
	l1->size--;
	l2->size++;
}

static void	ft_pushs_moviments_in_l1(t_list *l1)
{
	if (l1->begin->next)
	{
		l1->begin = l1->begin->next;
		l1->begin->prev = NULL;
	}
	else
		l1->begin = NULL;
}

static void	ft_pushs_moviments_in_l2(t_list *l2, t_node *node)
{
	if (l2->begin)
	{
		node->next = l2->begin;
		l2->begin->prev = node;
	}
	else
	{
		node->next = NULL;
		l2->end = node;
	}
	l2->begin = node;
}
