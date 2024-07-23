/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-dahr <med-dahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 23:55:36 by med-dahr          #+#    #+#             */
/*   Updated: 2024/07/23 00:11:45 by med-dahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(char *ptr, t_src *src)
{
	int		temp;
	int		i;

	if (ft_strncmp(ptr, "pb\n", 3) == 0)
	{
		if (src->size_a <= 0)
			return ;
		if (src->size_a > 0)
		{
			temp = src->stack_a[0];
			i = -1;
			while (++i < src->size_a - 1)
				src->stack_a[i] = src->stack_a[i + 1];
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
	write(1, ptr, ft_strlen(ptr));
}

void	push(char *ptr, t_src *src)
{
	int		temp;
	int		i;

	if (ft_strncmp(ptr, "pa\n", 3) == 0)
	{
		if (src->size_b > 0)
		{
			temp = src->stack_b[0];
			i = -1;
			while (++i < src->size_b - 1)
				src->stack_b[i] = src->stack_b[i + 1];
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
	else 
		push_b(ptr, src);
	write(1, ptr, ft_strlen(ptr));
}

int	ft_max_num(t_src *src)
{
	int		max;
	int		i;

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

int	get_index(int *indx, int nbr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (indx[i] == nbr)
		{
			return (i);
		}
		i++;
	}
	return (-1);
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
