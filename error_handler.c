/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbohn-co <tbohn-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:51:45 by tbohn-co          #+#    #+#             */
/*   Updated: 2024/04/01 12:03:08 by tbohn-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	ft_nbr_check(char *arg)
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

void	ft_error_handler(int error, t_list *list)
{
	if (error == 2)
		ft_destroy_list(&list);
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}
