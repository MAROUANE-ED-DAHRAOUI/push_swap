#include "push_swap.h"

int     Is_sorted_stack(t_src *src)
{
        int     i;

        i = 0;
        while(i < src->size_a)
        {
                if(src->stack_a[i] > src->stack_a[i + 1])
                        return (0);
                i++;
        }
        return (1);
}

void    check_dup(t_src *src)
{
        int     i;
	int cnt;

	cnt = 0;
	i = 0;
        while(cnt < src->size_a)
        {
                i = cnt + 1;
                while(i <  src->size_a)
                {
                        if(src->stack_a[cnt] == src->stack_a[i])
                                free_err(src, "Error\n");
                        i++;
                }
                cnt++;
        }
        if(Is_sorted_stack(src))
                free_err(src, NULL);
}

/*void    process_args(int ac, char **av, t_src *src)
{
        int     i;
        char    *s1;
        char    *s2;

        s1 = ft_strdup("");
        i = 1;
        while(i < ac && av[i] != NULL)
        {
                s2 = ft_strjoin(s1, av[i]);
                if(s1)
                        free(s1);
                if(i != ac - 1)
                {
                        s1 = ft_strjoin(s2, " ");
                        if(s2)
                                free(s2);
                        s2 = s1;
                }
		i++;
        }
        src->add_args = ft_strdup(s2);
        if(src->add_args == NULL)
                free_err(src, "Error\n");
        if(s2)
                free(s2);
}*/
