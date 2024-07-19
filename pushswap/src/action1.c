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
	max = src->stack_a[0];
	while(i < src->size_b)
	{
		if(src->stack_b[i] > max)
                {
			max = src->stack_b[i];
                }
		i++;
	}
        printf("------%d-----", max);
	return (max);
}

int get_index(int *idx, int nbr, int size)
{
        int i;

        i = 0;
        while(i < size)
        {
                if(nbr == idx[i])
                        return i;
                i++;
        }
        return (0);
}

void    range(t_src *src, int end)
{
        int start;
        int index = 0;

        start = 0; 
        while(src->size_a != 0)
        {
                index = get_index(src->indx, src->stack_a[0], src->size_a);
                if(index >= start && index <= end)
                {
                        push("pb\n", src);
                        start++;
                        end++;
                }
                else if(index < start)
                {
                        push("pb\n", src);
                        rab(src->stack_b, src->size_b, "b");
                        start++;
                        end++;
                }
                else if(index > end)
                {
                        rab(src->stack_a, src->size_a, "a");
                }
        }  
        // size = src->size_b;
        // int max = 0;
        // while(size != 1)
        // {

        //         max = ft_max_num(src);
        //         if(max < (src->size_b / 2))
        //         {
        //                 while(max-- >= 0)
        //                 {
        //                         rab(src->stack_b, src->size_b, "b");
        //                         push("pa\n", src);
        //                         size--;
        //                 }
        //         }
        //         else if(max > (src->size_b / 2))
        //         {
        //                 max -= (src->size_b / 2);
        //                 while(max-- >= 0)
        //                 {
        //                         rrab(src->stack_b, src->size_b, "b");
        //                         push("pa\n", src);
        //                         size--;
        //                 }
        //         }
        // }
}

