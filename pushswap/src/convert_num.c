#include "push_swap.h"

long long     ft_itoa_num(char *str, t_src *src)
{
        int     	sign;
        int     	i;
        long long    	num;

        i = 0;
        sign = 1;
        num = 0;
        while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
                i++;
        if(str[i] == '-' || str[i] == '+')
        {
                if(str[i] == '-')
                        sign = -1;
                i++;
        }
        while(str[i])
        {
                if(num > INT_MAX || (num * sign) < INT_MIN || (!(str[i] >= '0' && str[i] <= '9')))
                        free_err(src, "Error\n");
                if(ft_strlen(str) > 11)
		{
                        free_err(src, "Error\n");
		}
                num = num * 10 + (str[i] - '0');
                i++;
        }
        return ((num * sign));
}

void    convert_numbers(t_src *src)
{
        int     i;
	int	j;
	long long	num;
	char	**arr;

	arr = ft_split(src->add_args, ' ');
	j = 0;
        i = 0;
        while(arr[i] && arr[i][0] != '\0')
        {
		num = ft_itoa_num(arr[i], src);
		if(num > INT_MAX || num < INT_MIN)
			free_err(src, "Error\n");
		src->stack_a[i] = num;
        }
	while(arr[j] != NULL)
		free(arr[j++]);
	free(arr);
}
