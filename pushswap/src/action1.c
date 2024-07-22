#include "push_swap.h"

void    push(char *ptr, t_src *src)
{
        if(ft_strncmp(ptr, "pa\n", 3) == 0)
        {
		 if (src->size_b > 0)
    		 {
        		int temp = src->stack_b[0];
        		for (int i = 0; i < src->size_b - 1; i++)
            			src->stack_b[i] = src->stack_b[i + 1];
        		src->size_b--;
        		for (int i = src->size_a; i > 0; i--)
            			src->stack_a[i] = src->stack_a[i - 1];
        		src->stack_a[0] = temp;
        		src->size_a++;
    		}
                /*if(src->size_b <= 0)
                        return ;
                tmp = src->stack_b[0];
                ft_memmove(src->stack_a + 1, src->stack_a, sizeof(int) * src->size_a);
                src->stack_a[0] = tmp;
                src->size_b--;
                ft_memmove(src->stack_b, src->stack_b + 1, sizeof(int) * src->size_b);
                src->size_a++;*/
        }
        else if(ft_strncmp(ptr, "pb\n", 3) == 0)
        {
                if(src->size_a <= 0)
                        return ;
		 if (src->size_a > 0)
    		 {
        		int temp = src->stack_a[0];
        		for (int i = 0; i < src->size_a - 1; i++)
            			src->stack_a[i] = src->stack_a[i + 1];
       		 	src->size_a--;
        		for (int i = src->size_b; i > 0; i--)
            			src->stack_b[i] = src->stack_b[i - 1];
        		src->stack_b[0] = temp;
        		src->size_b++;
    		}
                /*tmp = src->stack_a[0];
                ft_memmove(src->stack_b + 1, src->stack_b, sizeof(int) * src->size_b);
                src->stack_b[0] = tmp;
                src->size_a--;
                ft_memmove(src->stack_a, src->stack_a + 1, sizeof(int) * src->size_a);
                src->size_b++;*/
        }
        write(1, ptr, ft_strlen(ptr));
}

int	ft_max_num(t_src *src )
{
	int	max;
	int	i;

	i = 0;
	max = src->stack_b[0];
        // printf("size b: %d\n", src->size_b);
        // exit(0);
	while(i < src->size_b)
	{
		if(src->stack_b[i] > max)
                {
			max = src->stack_b[i];
                }
		i++;
	}
	return (max);
}

int get_index(int *indx, int nbr, int size)
{
        int i;

        i = 0;
        while(i < size)
        {
                if(indx[i] == nbr)
		{
                        return i;
		}
                i++;
        }
        return (-1);
}

void    range(t_src *src, int end)
{
	int index;

	
	int size = src->size_a;
        while(src->size_a)
        {	
                index = get_index(src->indx, src->stack_a[0], size);
		if (index < src->size_b)
			push("pb\n", src);
		else if (index >= src->size_b && index <= src->size_b + end)
		{
			push("pb\n", src);
			rab(src->stack_b, src->size_b, "b");
		}
		else
			rab(src->stack_a, src->size_a, "a");
        }
        push_all_to_stack_a(src);
}
