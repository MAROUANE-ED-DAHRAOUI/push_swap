#include "push_swap.h"

void	ra(int *arr, int size_a, char *s1, char *s2)
{
	int tmp;

	if(!arr[0] || !arr[1])
		return ;
	if(ft_strncmp(s1, "up", 5) == 0)
	{
		tmp = arr[0];
		ft_memmove(arr, arr + 1, sizeof(int) * (size_a - 1));
		arr[size_a - 1] = tmp;
		write(1, "r", 1);
		write(1, s2, ft_strlen(s2));
                write(1, "\n", 1);
	}
}

void	rra(int *arr, int size_a, char *s1, char *s2)
{
	int tmp;

	if(ft_strncmp(s1, "down", 5) == 0)
	{
		tmp = arr[size_a - 1];
		ft_memmove(arr + 1, arr, sizeof(int) * (size_a - 1));
		arr[0] = tmp;
		write(1, "rr", 2);
		write(1, s2, ft_strlen(s2));
		write(1, "\n", 1);
	}
}
