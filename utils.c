/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbohn-co <tbohn-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:26:53 by tbohn-co          #+#    #+#             */
/*   Updated: 2024/04/01 15:32:44 by tbohn-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

long int	ft_atoi(const char *nbr)
{
	int			i;
	int			signal;
	long int	result;

	i = 0;
	signal = 1;
	result = 0;
	if (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			signal *= -1;
		i++;
	}
	while (nbr[i] && ft_isdigit(nbr[i]))
	{
		result = result * 10 + (nbr[i] - '0');
		i++;
	}
	return (result * signal);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
