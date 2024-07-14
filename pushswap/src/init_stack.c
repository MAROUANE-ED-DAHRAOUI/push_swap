#include "push_swap.h"

int     lenght_words(char const *av, char c)
{
        int len;
        int i;

        i = 0;
        len = 0;
        while(av[i])
        {
                if(av[i] != c)
                {
                        len++;
                        while(av[i] != c && av[i])
                                i++;
                }
                else
                        i++;
        }
        return (len);
}

void    stacks_init(int ac, char **av, t_src *src)
{
        int     i;
	int	j;

	j = 0;
        src->size_a = 0;
        src->size_b = 0;
        i = 0;
        while(++j < ac)
        {
                if(lenght_words(av[i + 1], ' '))
                {
                        src->size_a += lenght_words(av[i + 1], ' ');
                }
                else
                {
                        src->size_a++;
                }
                i++;
        }
        src->stack_a = malloc(src->size_a * sizeof * src->stack_a);
        if(src->stack_a == NULL)
                free_err(src, "Error\n");
        src->stack_b = malloc(src->size_a * sizeof * src->stack_b);
        if(src->stack_b == NULL)
                free_err(src, "Error\n");
}
