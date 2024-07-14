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

int Is_valide_input(char **av, int ac)
{
    int i;
    int j;

    i = 0;
    while(++i < ac)
    {
	    j = 0;
	    if (!av[i][0] || (av[i][0] && av[i][0] == ' '))
		    return (0);
	     while(av[i][j] != '\0')
	     {
		     if((!(av[i][j] >= '0' && av[i][j] <= '9') && (av[i][j] != ' ')
					     && (av[i][j] != '+' && av[i][j] != '-' && av[i][j] != ' ')) ||
				     (av[i][j] == '-' && av[i][j + 1] == '\0') || 
				     (av[i][j] == '+' && av[i][j + 1] == '\0') ||
				     (av[i][j] == '-' && av[i][j + 1] == ' ') ||
				     (av[i][j] == '+' && av[i][j + 1] == ' '))
			     return (0);
		     else
			     j++;
	     }
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
	ft_args_join(av, ac, src);
	convert_numbers(src);
	check_dup(src);
	order_rather_index(src);
	check_action(src);
	Is_sorted_stack(src);
	return (0);
}
