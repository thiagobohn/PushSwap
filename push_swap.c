/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srmeneses <srmeneses@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:52:01 by tbohn-co          #+#    #+#             */
/*   Updated: 2024/04/02 19:33:52 by srmeneses        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static t_list	*ft_create_a(char **input_a);
// static void		ft_push_swap(t_list *a, t_list *b);
static void		ft_check_sort(t_list *list);
void			ft_print_list(t_list *list);//////////////////

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc > 1)
	{
		a = ft_create_a(argv);
		ft_check_sort(a);
		b = ft_create_list();
		// ft_push_swap(a, b);
		ft_destroy_list(&a);
		ft_destroy_list(&b);
	}
	else
		ft_error_handler(1, NULL);
}

static t_list	*ft_create_a(char **input_a)
{
	int			i;
	t_list		*list;
	t_list		*repeat;

	list = ft_create_list();
	repeat = ft_create_list();
	i = 0;
	while (input_a[++i])
	{
		ft_validet_nbr(list, repeat, input_a[i]);
	}
	ft_destroy_list(&repeat);
	return (list);
}

static void		ft_check_sort(t_list *list)
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
	printf("já está ordenado\n");
}

// static void	ft_push_swap(t_list *a, t_list *b)
// {
// 	while (a != NULL)
// 	{
		
// 	}
// }

void	ft_print_list(t_list *list)///////////////
{
	t_node	*aux;

	aux = list->begin;
	while (aux != NULL)
	{
		printf("%d ", aux->val);
		aux = aux->next;
	}
}////////////////
