#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int 			*content;
	struct s_list	*next;
    struct s_list	*previus;
}	t_list;

void	ft_args_check(int argc, char **argv);
void    ft_error_handler(int error);

t_list	*ft_lstnew(int content);

#endif