#include "push_swap.h"

void    push(char *ptr, t_src *src)
{
        int     tmp;

        if(ft_strncmp(ptr, "pa\n", 3) == 0)
        {
                if(src->size_b <= 0)
                        return ;
                tmp = src->stack_b[0];
                ft_memmove(src->stack_a + 1, src->stack_a, sizeof(int) * src->size_a);
                src->stack_a[0] = tmp;
                src->size_b--;
                ft_memmove(src->stack_b, src->stack_b + 1, sizeof(int) * src->size_b);
                src->size_a++;
        }
        else if(ft_strncmp(ptr, "pb\n", 3) == 0)
        {
                if(src->size_a <= 0)
                        return ;
                tmp = src->stack_a[0];
                ft_memmove(src->stack_b + 1, src->stack_b, sizeof(int) * src->size_b);
                src->stack_b[0] = tmp;
                src->size_a--;
                ft_memmove(src->stack_a, src->stack_a + 1, sizeof(int) * src->size_a);
                src->size_b++;
        }
        write(1, ptr, ft_strlen(ptr));
}

int	ft_max_num(t_src *src )
{
	int	max;
	int	i;
	int	j;

	i = 0;
	j = 0;
	max = src->indx[0];
	while(src->indx && i < src->size_a)
	{
		if(src->stack_a[i] > max)
                {
			max = src->stack_a[i];
                }
		i++;
	}
        printf("------%d-----", max);
	return (max);
}

void    range(t_src *src, int end)
{
        int start;

        start = 0; 
        int size = src->size_a;
        while(size != 1)
        {
                if(src->indx[0] >= start && src->indx[0] <= end)
                {
                        push("pb\n", src);
                        size--;
                        start++;
                        end++;
                }
                else if(src->indx[0] < start)
                {
                        push("pb\n", src);
                        rab(src->stack_b, src->size_b, "b");
                        size--;
                        start++;
                        end++;
                }
                else if(src->indx[0] > end)
                {
                        rab(src->stack_a, src->size_a, "a");
                }
        }  

        size = src->size_b;
        int max = 0;
        while(size != 1)
        {

                max = ft_max_num(src);
                if(max < (src->size_b / 2))
                {
                        while(max-- >= 0)
                        {
                                rab(src->stack_b, src->size_b, "b");
                                push("pa\n", src);
                                size--;
                        }
                }else if(max > (src->size_b / 2))
                {
                        max -= (src->size_b / 2);
                        while(max-- >= 0)
                        {
                                rrab(src->stack_b, src->size_b, "b");
                                push("pa\n", src);
                                size--;
                        }
                }
        }
}

