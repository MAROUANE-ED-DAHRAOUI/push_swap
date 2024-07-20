#include "push_swap.h"

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
}
