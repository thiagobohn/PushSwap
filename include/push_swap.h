/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbohn-co <tbohn-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:52:05 by tbohn-co          #+#    #+#             */
/*   Updated: 2024/05/15 11:21:57 by tbohn-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>//////////////////////////////

# define FIRST 1
# define LAST 0

typedef struct s_node
{
	int				val;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	struct s_node	*begin;
	struct s_node	*end;
	int				size;
}	t_list;

void		ft_error_handler(int error, t_list *repeated);
void		ft_validet_nbr(t_list *list, char *nbr_cadidate);

t_node		*ft_create_node(int val);
t_list		*ft_create_list(void);
void		ft_destroy_list(t_list **list_ref);
void		ft_add(t_list *list, int val, int position);
void		ft_remove(t_list *list, int position);

long int	ft_atoi(const char *nbr);
int			ft_isdigit(int c);

void		ft_swap(t_list *list, char stack);
void		ft_ss(t_list *a, t_list *b);
void		ft_push(t_list *l1, t_list *l2, char stack);
void		ft_rotate(t_list *list, char stack);
void		ft_rr(t_list *a, t_list*b);
void		ft_reverse_rotate(t_list *list, char stack);
void		ft_rrr(t_list *a, t_list*b);

#endif