/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbohn-co <tbohn-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:51:45 by tbohn-co          #+#    #+#             */
/*   Updated: 2024/03/28 09:51:46 by tbohn-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_args_check(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc != 2)
		exit(EXIT_FAILURE);
	while (argv[1][i])
	{
		if ((argv[1][i] >= 48 && argv[1][i] <= 57) || argv[1][i] == ' ')
			i++;
		else
			ft_error_handler(1);
	}
}

void	ft_error_handler(int error)
{
	(void)error;
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}
