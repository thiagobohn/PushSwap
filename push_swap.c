/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbohn-co <tbohn-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:52:01 by tbohn-co          #+#    #+#             */
/*   Updated: 2024/04/01 17:31:54 by tbohn-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static t_list	*ft_create_a(char **input_a);
void			ft_print_list(t_list *list);//////////////////

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc > 1)
	{
		a = ft_create_a(argv);
		b = ft_create_a(argv);
		ft_print_list(a);
		printf("\n");
		ft_print_list(b);
		printf("\n");
		
		printf("SWAP A\n");
		ft_swap(a, 'a');
		ft_print_list(a);
		printf("\n");
		ft_print_list(b);
		printf("\n");
		
		printf("ROTATE A\n");
		ft_rotate(a, 'a');
		ft_print_list(a);
		printf("\n");
		ft_print_list(b);
		printf("\n");
		
		printf("PUSH B\n");
		ft_push(b, a, 'b');
		ft_print_list(a);
		printf("\n");
		ft_print_list(b);
		printf("\n");
		
		printf("PUSH B\n");
		ft_push(b, a, 'b');
		ft_print_list(a);
		printf("\n");
		ft_print_list(b);
		printf("\n");
		
		printf("RRR\n");
		ft_rrr(a, b);
		ft_print_list(a);
		printf("\n");
		ft_print_list(b);
		printf("\n");
		
		ft_destroy_list(&a);
		ft_destroy_list(&b);
	}
	else
		ft_error_handler(1, NULL);
}

static t_list	*ft_create_a(char **input_a)
{
	int			i;
	long int	nbr;
	t_list		*list;

	list = ft_create_list();
	i = 0;
	while (input_a[++i])
	{
		if (ft_nbr_check(input_a[i]))
		{
			nbr = ft_atoi(input_a[i]);
			if ((nbr < 2147483647) && (nbr > -2147483648))
				ft_add(list, nbr, LAST);
			else
				ft_error_handler(2, list);
		}
		else
			ft_error_handler(2, list);
	}
	return (list);
}

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
