#include "push_swap.h"

int ft_min(t_src *src , int size)
{
	int i;
	int min;

	i = 0;
	min = src->stack_a[0];

	while (i < size)
	{
		if (min > src->stack_a[i])
			min = src->stack_a[i];
		i++;
	}
	return (min);
}

void	five_or_four_sorting(t_src *src)
{
	int size = src->size_a;
	while (size > 3)
	{
		if(src->stack_a[0] == ft_min(src, size))
		{
			push("pb\n", src);
			--size;
		}
		else if (src->stack_a[src->size_a - 1] == ft_min(src, size))
			rrab(src->stack_a, src->size_a, "a");
		else
			rab(src->stack_a, src->size_a, "a");
	}
	three_sorting(src);
	while (src->size_b > 0)
    {
        push("pa\n", src);
    }
}

void	three_sorting(t_src *src)
{
	if(src->stack_a[0] > src->stack_a[1] && src->stack_a[1] > src->stack_a[2])
	{
		swap(src->stack_a, src->size_a);
		rrab(src->stack_a, src->size_a, "a");
	}
	else if(src->stack_a[0] > src->stack_a[1] && src->stack_a[1] < src->stack_a[2])
	{
		if(src->stack_a[0] > src->stack_a[2])
			rab(src->stack_a, src->size_a, "a");
		else
			swap(src->stack_a, src->size_a);
	}
	else if(src->stack_a[0] < src->stack_a[1] && src->stack_a[1] > src->stack_a[2])
		{
			if(src->stack_a[0] < src->stack_a[2])
			{
				swap(src->stack_a, src->size_a);
				rab(src->stack_a, src->size_a, "a");
			}
			else
				rrab(src->stack_a, src->size_a, "a");
		}
}


int if_sorted(t_src *src)
{
	int i;

	i = 0;
	while (i < src->size_a - 1)
	{
		if (src->stack_a[i] > src->stack_a[i + 1])
			return 0;
		i++;
	}
	return (1);
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
	else if(src->size_a <= 100)
		range(src, 15);
	else if(src->size_a > 100)
		range(src, 35);
}
