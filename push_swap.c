/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbohn-co <tbohn-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:52:01 by tbohn-co          #+#    #+#             */
/*   Updated: 2024/03/28 17:18:51 by tbohn-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

t_list	*ft_create_a(char *input_a);

int	main(int argc, char **argv)
{
	//t_list	*a;

	ft_args_check(argc, argv);
	//a = ft_create_a(argv[1]);
}

t_list	*ft_create_a(char *input_a)
{
	t_list	*list;

	list = ft_create_list();
	while (input_a)
	{
		
		input_a++;
	}
	return (list);
}
