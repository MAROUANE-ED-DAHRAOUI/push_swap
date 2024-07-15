#include "push_swap.h"

int     ft_itoa_num(char *str, t_src *src)
{
        int     sign;
        int     i;
        long    num;

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
                        free_err(src, "Error\n");
                num = num * 10 + (str[i] - '0');
                i++;
        }
        return ((int)(num * sign));
}

void    convert_numbers(t_src *src)
{
        int     i;
	int	j;
	char	**arr;

	arr = ft_split(src->add_args, ' ');
	j = 0;
        i = 0;
        while(arr[i] && arr[i][0] != '\0')
        {
		src->stack_a[i] = ft_itoa_num(arr[i], src);
		i++;
        }
	while(arr[j] != NULL)
		free(arr[j++]);
	free(arr);
}
