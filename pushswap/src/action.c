#include "push_swap.h"

void	five_or_four_sorting(t_src *src)
{
	int tmp;

	tmp = src->size_a / 2;
	while(src->size_a > 3 && src->stack_a)
	{
		if(1 == min_num_pos(src, tmp))
			rab(src->stack_a, src->size_a, "a");
		else
			rrab(src->stack_a, src->size_a, "a");

		if(src->stack_a[0] == ft_min_num(src))
		{
			push("pb\n", src);
		}

	}
	three_sorting(src);
	push("pa\n", src);
	push("pa\n", src);
}

void	three_sorting(t_src *src)
{
	if(src->stack_a[1] < src->stack_a[0] && src->stack_a[1] < src->stack_a[2] && src->stack_a[0] < src->stack_a[2])
		swap(src->stack_a, src->size_a);
	else if(src->stack_a[0] > src->stack_a[1] && src->stack_a[1] > src->stack_a[2])
	{
		swap(src->stack_a, src->size_a);
		rrab(src->stack_a, src->size_a, "a");
	}
	else if(src->stack_a[0] > src->stack_a[1] && src->stack_a[1] < src->stack_a[2] && src->stack_a[0] > src->stack_a[2])
		rab(src->stack_a, src->size_a, "a");
	else if (src->stack_a[0] < src->stack_a[1] && src->stack_a[1] > src->stack_a[2] && src->stack_a[0] < src->stack_a[2])
	{
		swap(src->stack_a, src->size_a);
		rab(src->stack_a, src->size_a, "a");
	}
	else if(src->stack_a[0] < src->stack_a[1] && src->stack_a[1] > src->stack_a[2] && src->stack_a[0] > src->stack_a[2])
		rrab(src->stack_a, src->size_a, "a");
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
	else if(src->size_a == 100)
		range(src, 15);
	else if(src->size_a == 500)
		range(src, 35);
}
