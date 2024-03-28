/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbohn-co <tbohn-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:51:45 by tbohn-co          #+#    #+#             */
/*   Updated: 2024/03/28 17:27:33 by tbohn-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_args_check(int argc, char **argv)
{
	int		i;
	char	*arg;

	if (argc < 2)
		ft_error_handler(1);
	i = 0;
	while (argv[++i])
	{
		arg = argv[i];
		if (*arg == '-')
		{
			arg++;
			if (ft_isdigit(*arg))
				arg++;
			else
				ft_error_handler(1);
		}
		while (*arg)
		{
			if (ft_isdigit(*arg))
				arg++;
			else
				ft_error_handler(1);
		}
	}
}

void	ft_error_handler(int error)
{
	if (error == 1)
		write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}
