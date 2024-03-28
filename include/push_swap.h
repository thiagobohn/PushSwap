/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbohn-co <tbohn-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:52:05 by tbohn-co          #+#    #+#             */
/*   Updated: 2024/03/28 17:09:54 by tbohn-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>//////////////////////////////

typedef struct s_node
{
	int				val;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	struct s_node	*begin;
	struct s_node	*end;
	int				size;
}	t_list;

void	ft_args_check(int argc, char **argv);
void	ft_error_handler(int error);

t_node	*ft_create_node(int val);
t_list	*ft_create_list(void);
void	ft_destroy_list(t_list **list_ref);
void	ft_add_begin(t_list *list, int val);
void	ft_remove_first(t_list *list);

int	ft_atoi(const char *nptr);
int	ft_isdigit(int c);

#endif