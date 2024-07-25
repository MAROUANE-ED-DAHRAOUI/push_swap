/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-dahr <med-dahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:57:23 by med-dahr          #+#    #+#             */
/*   Updated: 2024/07/24 15:57:25 by med-dahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	ft_atoi_helper(const char *str, int *i, int *sign)
{
	long long	num;

	num = 0;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	while (str[*i])
	{
		if (num > INT_MAX || (num * *sign) < INT_MIN || !(str[*i] >= '0'
				&& str[*i] <= '9'))
			return (-1);
		num = num * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (num);
}

long long	ft_itoa_num(char *str, t_src *src)
{
	int			i;
	int			sign;
	long long	num;

	i = 0;
	i = 0;
	sign = 1;
	if (ft_strlen(str) > 11)
	{
		free_err(src, "Error\n");
		return (0);
	}
	num = ft_atoi_helper(str, &i, &sign);
	if (num == -1)
	{
		free_err(src, "Error\n");
		return (0);
	}
	return (num * sign);
}

void	convert_numbers(t_src *src)
{
	int			i;
	int			j;
	long long	num;
	char		**arr;

	arr = ft_split(src->add_args, ' ');
	j = 0;
	i = 0;
	while (arr[i] && arr[i][0] != '\0')
	{
		num = ft_itoa_num(arr[i], src);
		if (num > INT_MAX || num < INT_MIN)
		{
			free_err(src, "Error\n");
		}
		src->stack_a[i] = num;
		i++;
	}
	while (arr[j] != NULL)
		free(arr[j++]);
	free(arr);
}
