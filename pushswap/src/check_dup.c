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
