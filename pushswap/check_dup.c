/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-dahr <med-dahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:57:18 by med-dahr          #+#    #+#             */
/*   Updated: 2024/07/24 15:57:20 by med-dahr         ###   ########.fr       */
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

int	is_valide_input(char **av, int ac)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (!(process_str(av[i])))
			return (0);
	}
	return (1);
}
