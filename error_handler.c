/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srmeneses <srmeneses@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:51:45 by tbohn-co          #+#    #+#             */
/*   Updated: 2024/04/02 19:24:45 by srmeneses        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static int	ft_is_nbr(char *arg);
static void	ft_repeated_nbr(t_list *a, t_list *repeat, int nbr);

void	ft_validet_nbr(t_list *a, t_list *repeat, char *nbr_cadidate)
{
	long int	nbr;

	if (ft_is_nbr(nbr_cadidate))
	{
		nbr = ft_atoi(nbr_cadidate);
		if ((nbr < 2147483647) && (nbr > -2147483648))
		{
			ft_repeated_nbr(a, repeat, nbr);
			ft_add(a, nbr, LAST);
		}
		else
			ft_error_handler(2, a);
	}
	else
		ft_error_handler(2, a);
}

static int	ft_is_nbr(char *arg)
{
	if (*arg == '-')
	{
		arg++;
		if (ft_isdigit(*arg))
			arg++;
		else
			return (0);
	}
	while (*arg)
	{
		if (ft_isdigit(*arg))
			arg++;
		else
			return (0);
	}
	return (1);
}

static void	ft_repeated_nbr(t_list *a, t_list *repeat, int nbr)
{
	t_node *new;

	new = repeat->begin;
	while (new != NULL)
	{
		if (new->val == nbr)
		{
			ft_destroy_list(&repeat);
			ft_error_handler(2, a);
		}
		new = new->next;
	}
	ft_add(repeat, nbr, LAST);
}

void	ft_error_handler(int error, t_list *list)
{
	if (error == 2)
		ft_destroy_list(&list);
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}
