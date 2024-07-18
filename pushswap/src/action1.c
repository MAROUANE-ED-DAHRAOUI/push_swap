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

int index_number(t_src *src)
{
        int     max;
        int i;

        i = 0;
        max = ft_max_num(src);
        while(i < src->size_b)
        {
                if(src->stack_b[i] == max)
                        return (i);
                i++;
        }
        return (0);
}

int	ft_max_num(t_src *src)
{
	int	max;
	int	i;

	i = 0;
	max = src->stack_a[0];
	while(src->stack_a[i])
	{
		if(src->stack_a[i] > max)
			max = src->stack_a[i];
		i++;
	}
	return (max);
}

void    range_In_order(t_src *src)
{
        int i = 0;
        int indx;

        while(src->stack_b[i])
        {
                indx = index_number(src);
                if(indx < (src->size_b / 2))
                {
                        while(indx > 0)
                        {
                                 rab(src->stack_b, src->size_b, "b");
                                 indx--;
                        }
                }
                else
                {
                        while((src->size_b - indx) != 0)
                        {
                                rrab(src->stack_a, src->size_a,  "b");
                                indx++;
                        }
                }
        }
      push("pa\n", src);
}
void    range(t_src *src, int end)
{
        int start;

        start = 0; 

        while(src->size_a > 0)
        {
                if(src->stack_a[0] >= start && src->stack_a[0] <= end)
                {
                        push("pb\n", src);
                        start++;
                        end++;
                }
                else if(src->stack_a[0] < start)
                {
                        push("pb\n", src);
                        rab(src->stack_b, src->size_b, "b");
                        start++;
                        end++;
                }
                else
                {
                        rab(src->stack_b, src->size_b, "a");
                }
        }  
        while(src->size_b > 0)
        {
                range_In_order(src);
        }
}

