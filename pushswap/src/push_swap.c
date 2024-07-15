#include "push_swap.h"

void	order_rather_index(t_src *src)
{
	int	i;
	int	j;
	int	k;
	int	*buff;

	i = 0;
	buff = malloc(src->size_a * sizeof * buff);
	if(buff)
	{
		while(i < src->size_a)
		{
			k = 0;
			j = 0;
			while(j++ < src->size_a)
			{
				if(src->stack_a[i] > src->stack_a[j])
					k++;
			}
			buff[i] = k;
			i++;
		}
		i = src->size_a;
		while(i--)
			src->stack_a[i] = buff[i];

		free(buff);
	}
	else
	{
		free_err(src, "Error in order_rather\n");
	}
}

int succes_args(char ch1, char ch2, char ch3)
{
	//ch1 ___ bf 
	//af______ch3
	//cur_____ch2
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
	order_rather_index(src);
	check_action(src);
	Is_sorted_stack(src);
	return (0);
}
