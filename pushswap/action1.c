/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-dahr <med-dahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:57:14 by med-dahr          #+#    #+#             */
/*   Updated: 2024/07/24 15:57:15 by med-dahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_src *src)
{
	int	temp;
	int	i;

	if (src->size_b > 0)
	{
		temp = src->stack_b[0];
		i = 0;
		while (i < src->size_b - 1)
		{
			src->stack_b[i] = src->stack_b[i + 1];
			i++;
		}
		src->size_b--;
		i = src->size_a;
		while (i > 0)
		{
			src->stack_a[i] = src->stack_a[i - 1];
			i--;
		}
		src->stack_a[0] = temp;
		src->size_a++;
	}
}

void	push_b(t_src *src)
{
	int	temp;
	int	i;

	if (src->size_a > 0)
	{
		temp = src->stack_a[0];
		i = 0;
		while (i < src->size_a - 1)
		{
			src->stack_a[i] = src->stack_a[i + 1];
			i++;
		}
		src->size_a--;
		i = src->size_b;
		while (i > 0)
		{
			src->stack_b[i] = src->stack_b[i - 1];
			i--;
		}
		src->stack_b[0] = temp;
		src->size_b++;
	}
}

void	push(char *ptr, t_src *src)
{
	if (ft_strncmp(ptr, "pa\n", 3) == 0)
		push_a(src);
	else if (ft_strncmp(ptr, "pb\n", 3) == 0)
		push_b(src);
	write(1, ptr, ft_strlen(ptr));
}

int	ft_max_num(t_src *src)
{
	int	max;
	int	i;

	i = 0;
	max = src->stack_b[0];
	while (i < src->size_b)
	{
		if (src->stack_b[i] > max)
		{
			max = src->stack_b[i];
		}
		i++;
	}
	return (max);
}

void	range(t_src *src, int end)
{
	int	index;
	int	size;

	size = src->size_a;
	while (src->size_a)
	{
		index = get_index(src->indx, src->stack_a[0], size);
		if (index < src->size_b)
			push("pb\n", src);
		else if (index >= src->size_b && index <= src->size_b + end)
		{
			push("pb\n", src);
			rab(src->stack_b, src->size_b, "b");
		}
		else
			rab(src->stack_a, src->size_a, "a");
	}
	push_all_to_stack_a(src);
}
