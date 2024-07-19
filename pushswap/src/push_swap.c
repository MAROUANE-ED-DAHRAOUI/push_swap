#include "push_swap.h"

int		*bubble_sort(int *arr, int len)
{
	int i, j, swap;

	i = -1;
	while(++i < len)
	{	
			j = i + 1;
			while(j < len)
			{
				if(arr[i] > arr[j])
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
int		*assign_indx(int *org, int *cpy, int *indx, int size)
{
	int	i;
	int j;

	i = -1;
	while(++i < size)
	{
		j = 0;
		while(j < size)
		{
			if(org[i] == cpy[j])
				indx[i] = j;
			j++;
		}
	}
	return (indx);
}
void	order_rather_index(t_src *src)
{
	int	i;
	int	*indx;
	int *tmp;

	i = -1;
	indx = malloc(src->size_a * sizeof * indx);
	tmp = malloc(src->size_a * sizeof * tmp);
	if(indx && tmp)
	{
		while(src->size_a > ++i)
		{
			tmp[i] = src->stack_a[i];
		}
		tmp = bubble_sort(tmp, src->size_a);
		indx = assign_indx(src->stack_a, tmp, indx, src->size_a);
		src->indx = indx;
		free(tmp);
	}
	else
	{
		free_err(src, "Error in order_rather\n");
	}
}

int succes_args(char ch1, char ch2, char ch3)
{
	if ((ch1 >= '0' && ch1 <= '9') && (ch2 == '-' || ch2 == '+'))
                return (0);
        else if ((ch2 == '-' || ch2 == '+') && (ch3 >= '0' && ch3 <= '9'))
			return (1);
        else if ((ch2 == '-' || ch2 == '+') && (ch3 != '-' || ch3 != '+'))
                return (0);
        else if ((ch2 == '-' || ch2 == '+') && (ch3 == ' ' || ch3 == '\0'))
                return (0);
        else if (ch2 == ' ' || ch2 == '+' || ch2 == '-')
                return (1);
        else if (ch2 >= '0' && ch2 <= '9')
                	return (1);
        else
		return (0);
}

int	process_str(char *str)
{
	int i;

	i = 0;
	while(str[i] == ' ')
		i++;
	if(str[i] == '\0')
		return (0);
	while(str[i] != '\0')
	{
		if(!(succes_args(str[i - 1], str[i], str[i + 1])))
			return (0);
		i++;
	}
	return (1);
}

int Is_valide_input(char **av, int ac)
{
    int i;

    i = 0;
    while(++i < ac)
    {
	if(!(process_str(av[i])))
		return (0);
    }
    return (1);
}
int main(int ac, char **av)
{
	t_src	*src;
	
	if(ac < 2)
                return (0);
	src = malloc(sizeof * src);
        if(src == NULL)
                exit(1);
	if(!(Is_valide_input(av, ac)))
		free_err(src, "Is Not valide input\n");
	stacks_init(ac, av, src);
	if(src->size_a == 1)
		exit(1);
	ft_args_join(av, ac, src);
	convert_numbers(src);
	check_dup(src);
	int i = 0;
	order_rather_index(src);
	if (!if_sorted(src))
		check_action(src);
	printf("stack A\n");
	while (i < 5)
	{
		printf("[%d]\n", src->stack_a[i]);
		i++;
	}
	// printf("stack B\n");
	// i = 0;
	// while (i < 2)
	// {
	// 	printf("[%d]\n", src->stack_b[i]);
	// 	i++;
	// }
	//free_all(src);
	return (0);
}
      