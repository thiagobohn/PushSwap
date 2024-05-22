/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbohn-co <tbohn-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:52:01 by tbohn-co          #+#    #+#             */
/*   Updated: 2024/05/22 18:28:17 by tbohn-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static t_list	*ft_create_a(char **input_a);
static void		ft_is_easy_to_solve(t_list *list);
static void		ft_is_sorted(t_list *list);
void			ft_print_list(t_list *list);//////////////////
void			ft_print_cost(t_list *list);//////////////////

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc > 1)
	{
		a = ft_create_a(argv);
		ft_is_easy_to_solve(a);
		ft_assigning_indexes(a);
		b = ft_create_list();
		printf("a:\n");/////////
		ft_print_list(a);///////
		printf("\n");///////////
		printf("b:\n");/////////
		ft_print_list(b);///////
		printf("\n");///////////
		ft_push_swap(a, b);
		printf("a:\n");/////////
		ft_print_list(a);///////
		printf("\n");///////////
		printf("b:\n");/////////
		ft_print_list(b);///////
		printf("\n");///////////
		ft_print_cost(b);///////
		printf("\n");///////////
		ft_destroy_list(&a);
		ft_destroy_list(&b);
	}
	else
		ft_error_handler(1, NULL);
	exit(EXIT_SUCCESS);
}

static t_list	*ft_create_a(char **input_a)
{
	int			i;
	t_list		*list;

	list = ft_create_list();
	i = 0;
	while (input_a[++i])
	{
		ft_validet_nbr(list, input_a[i]);
	}
	return (list);
}

static void	ft_is_easy_to_solve(t_list *list)
{
	ft_is_sorted(list);
	if (list->size < 4)
	{
		if (list->size == 2)
			ft_swap(list, 'a');
		else
			ft_sort3(list);
		exit(EXIT_SUCCESS);
	}
}

static void	ft_is_sorted(t_list *list)
{
	t_node *current;

	current = list->begin;
	while (current->next != NULL)
	{
		if (current->val > current->next->val)
			return ;
		else
			current = current->next;
	}
	exit(EXIT_SUCCESS);
}

void	ft_print_list(t_list *list)///////////////
{
	t_node	*aux;

	aux = list->begin;
	while (aux != NULL)
	{
		printf("%d , %d , %d , %d |", aux->target_pos, aux->pos, aux->index, aux->val);
		aux = aux->next;
	}
}////////////////

void	ft_print_cost(t_list *list)///////////////
{
	t_node	*aux;

	aux = list->begin;
	while (aux != NULL)
	{
		printf("    %d , %d     |", aux->cost_a, aux->cost_b);
		aux = aux->next;
	}
}////////////////
