/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-dahr <med-dahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 00:12:51 by med-dahr          #+#    #+#             */
/*   Updated: 2024/07/23 01:03:29 by med-dahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dup(t_src *src)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (cnt < src->size_a)
	{
		i = cnt + 1;
		while (i < src->size_a)
		{
			if (src->stack_a[cnt] == src->stack_a[i])
				free_err(src, "Error\n");
			i++;
		}
		cnt++;
	}
}

int	*bubble_sort(int *arr, int len)
{
	int	i;
	int	j;
	int	swap;

	i = -1;
	while (++i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] > arr[j])
			{
				swap = arr[i];
				arr[i] = arr[j];
				arr[j] = swap;
			}
			j++;
		}
	}
	return (arr);
}
