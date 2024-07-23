/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-dahr <med-dahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 00:59:18 by med-dahr          #+#    #+#             */
/*   Updated: 2024/07/23 00:59:20 by med-dahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_args_join(char **av, int ac, t_src *src)
{
	char	*cp1;
	char	*cp2;
	int		k;

	k = 0;
	cp2 = ft_strdup("");
	while (++k < ac && av[k] != NULL)
	{
		cp1 = ft_strjoin(cp2, av[k]);
		if (cp2)
			free(cp2);
		if (k != ac - 1)
		{
			cp2 = ft_strjoin(cp1, " ");
			if (cp1)
				free(cp1);
			cp1 = cp2;
		}
	}
	src->add_args = ft_strdup(cp1);
	if (src->add_args == NULL)
		free_err(src, "Error\n");
	if (cp1)
		free(cp1);
}

int	ft_min_num(t_src *src)
{
	int	min;
	int	i;

	i = 0;
	min = src->stack_a[0];
	while (src->stack_a[i])
	{
		if (src->stack_a[i] < min)
			min = src->stack_a[i];
		i++;
	}
	return (min);
}

int	min_num_pos(t_src *src, int size)
{
	int	i;

	i = 0;
	while (src->stack_a[i] && size >= 0)
	{
		if (src->stack_a[i] == ft_min_num(src))
			return (1);
		size--;
		i++;
	}
	return (0);
}

void	free_all(t_src *src)
{
	if (src != NULL)
	{
		if (src->stack_a != NULL)
			free(src->stack_a);
		if (src->stack_b != NULL)
			free(src->stack_b);
		if (src->add_args != NULL)
			free(src->add_args);
		if (src->indx != NULL)
			free(src->indx);
		if (src != NULL)
			free(src);
	}
}
