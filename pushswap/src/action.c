#include "push_swap.h"

void	five_or_four_sorting(t_src *src)
{
	while(src->size_b <= 1)
	{
		if(src->stack_a[0] == 0 || src->stack_a[0] == 1)
			push("pb\n", src);
		else
			rotate(src->stack_a, src->size_a, "up", "a");
	}
	if(src->stack_b[0] == 0)
		swap(src->stack_b, src->size_b);
	if(src->stack_a[2] != 4)
	{
		if(src->stack_a[0] == 4)
			rotate(src->stack_a, src->size_a, "up", "a");
		else
			rotate(src->stack_a, src->size_a, "down", "a");
	}
	if(src->stack_a[0] > src->stack_a[1])
		swap(src->stack_a, src->size_a);
	push("pa\n", src);
	push("pa\n", src);
}

void	swap(int *arr, int size)
{
	int cp;

	if(size <= 0)
		return;
	cp = arr[0];
	arr[0] = arr[1];
	arr[1] = cp;
	write(1, "sa\n", 3);
}

void	rotate(int *src, int size, char *s1, char *s2)
{
	int	tmp;

	if(size < 0)
		return ;
	if(ft_strncmp(s1, "up", 5) == 0)
	{
		tmp = src[0];
		ft_memmove(src, src + 1, sizeof(int) * (size - 1));
		src[size - 1] = tmp;
		write(1, "r", 1);
		write(1, s2, ft_strlen(s2));
		write(1, "\n", 1);
	}
	else if(ft_strncmp(s1, "down", 5) == 0)
	{
		tmp = src[size - 1];
		ft_memmove(src + 1, src, sizeof(int) * (size - 1));
		src[0] = tmp;
		write(1, "rr", 2);
		write(1, s2, ft_strlen(s2));
		write(1, "\n", 1);
	}
}

void	three_sorting(t_src *src)
{
	if(src->stack_a[2] != '2')
	{
		if(src->stack_a[0] == 2)
			rotate(src->stack_a, src->size_a, "up", "a");
		else
			rotate(src->stack_a, src->size_a, "down", "a");
	}
	if(src->stack_a[1] < src->stack_a[0])
		swap(src->stack_a, src->size_a);
}

void	check_action(t_src *src)
{
	if(src->size_a == 2 && src->stack_a[0] > src->stack_a[1])
		swap(src->stack_a, src->size_a);
	else if(src->size_a == 3)
		three_sorting(src);
	else if(src->size_a == 4 || src->size_a == 5)
		five_or_four_sorting(src);
	else
		sorting_radix(src);
}
