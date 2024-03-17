#include "push_swap.h"

void	ft_error_handler(int error)
{
	(void)error;
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}