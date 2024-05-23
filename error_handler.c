/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbohn-co <tbohn-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:51:45 by tbohn-co          #+#    #+#             */
/*   Updated: 2024/05/23 19:11:15 by tbohn-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static int	ft_is_nbr(char *arg);
static void	ft_repeated_nbr(t_list *a, int nbr);

void	ft_validet_nbr(t_list *a, char *nbr_cadidate)
{
	long int	nbr;

	if (ft_is_nbr(nbr_cadidate))
	{
		nbr = ft_atoi(nbr_cadidate);
		if ((nbr < INT_MAX) && (nbr > INT_MIN))
			ft_repeated_nbr(a, nbr);
		else
			ft_error_handler(2, a);
	}
	else
		ft_error_handler(2, a);
}

static int	ft_is_nbr(char *arg)
{
	if (*arg == '-' || *arg == '+')
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

static void	ft_repeated_nbr(t_list *a, int nbr)
{
	t_node	*new;

	new = a->begin;
	while (new != NULL)
	{
		if (new->val == nbr)
			ft_error_handler(2, a);
		new = new->next;
	}
	ft_add(a, nbr, LAST);
}

void	ft_error_handler(int error, t_list *repeat)
{
	if (error == 2)
		ft_destroy_list(&repeat);
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}
