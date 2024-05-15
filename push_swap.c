/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbohn-co <tbohn-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:52:01 by tbohn-co          #+#    #+#             */
/*   Updated: 2024/05/15 15:53:19 by tbohn-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static t_list	*ft_create_a(char **input_a);
//static void		ft_push_swap(t_list *a, t_list *b);
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
		//printf("a:\n");
		//ft_print_list(a);
		//printf("\n");
		// ft_push_swap(a, b);
		//printf("a:\n");
		//ft_print_list(a);
		//printf("\n");
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

	list = ft_create_list();
	i = 0;
	while (input_a[++i])
	{
		ft_validet_nbr(list, input_a[i]);
	}
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
	exit(EXIT_SUCCESS);
}

// static void	ft_push_swap(t_list *a, t_list *b)
// {
// 	int		max;
// 	t_node	*aux_a;

// 	while (a->size > 0)
// 	{
// 		max = a->begin->val;
// 		aux_a = a->begin->next;
// 		while (aux_a != NULL)
// 		{
// 			if (aux_a->val > max)
// 				max = aux_a->val;
// 			aux_a = aux_a->next;
// 		}
// 		while (a->begin->val != max)
// 		{
// 			ft_rotate(a, 'a');
// 		}
// 		ft_push(a, b, 'a');
// 	}
// 	while (b->size > 0)
// 		ft_push(b, a, 'b');
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
