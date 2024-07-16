#include "push_swap.h"

void	five_or_four_sorting(t_src *src)
{
	int tmp;

	tmp = src->size_a / 2;
	while(src->size_a > 3 && src->stack_a)
	{
		if(1 == min_num_pos(src, tmp))
			ra(src->stack_a, src->size_a, "up", "a");
		else
			rra(src->stack_a, src->size_a, "down", "a");

		if(src->stack_a[0] == ft_min_num(src))
		{
			push("pb\n", src);
		}

	}
	three_sorting(src);
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

void	three_sorting(t_src *src)
{
	if(src->stack_a[1] < src->stack_a[0] && src->stack_a[1] < src->stack_a[2] && src->stack_a[0] < src->stack_a[2])
		swap(src->stack_a, src->size_a);
	else if(src->stack_a[0] > src->stack_a[1] && src->stack_a[1] > src->stack_a[2])
	{
		swap(src->stack_a, src->size_a);
		rra(src->stack_a, src->size_a, "down", "a");
	}
	else if(src->stack_a[0] > src->stack_a[1] && src->stack_a[1] < src->stack_a[2] && src->stack_a[0] > src->stack_a[2])
		ra(src->stack_a, src->size_a, "up", "a");
	else if (src->stack_a[0] < src->stack_a[1] && src->stack_a[1] > src->stack_a[2] && src->stack_a[0] < src->stack_a[2])
	{
		swap(src->stack_a, src->size_a);
		ra(src->stack_a, src->size_a, "up", "a");
	}
	else if(src->stack_a[0] < src->stack_a[1] && src->stack_a[1] > src->stack_a[2] && src->stack_a[0] > src->stack_a[2])
		rra(src->stack_a, src->size_a, "down", "a");
}

void	check_action(t_src *src)
{
	if(src->size_a <= 1)
	{
		free_err(src, "");
		exit(0);
	}
	else if(src->size_a == 2)
		swap(src->stack_a, src->size_a);
	else if(src->size_a == 3)
		three_sorting(src);
	else if(src->size_a == 4 || src->size_a == 5)
		five_or_four_sorting(src);
	else
		sorting_radix(src);
}
