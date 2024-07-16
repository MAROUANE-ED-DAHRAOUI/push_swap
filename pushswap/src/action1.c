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

void    sort_elements_stk_b(int len_bit, int pos, t_src *src, int size_b)
{
        while (!Is_sorted_stack(src) && size_b-- && pos <= len_bit)
        {
                if(((src->stack_b[0] >> size_b) & 1) == 0)
                        ra(src->stack_b, src->size_b, "up", "b");
                else
                        push("pa\n", src);
        }
        if(Is_sorted_stack(src))
        {
                while(src->size_b != 0)
                        push("pa\n", src);
        }
}

void    sorting_radix(t_src *src)
{
        int     j;
        int     len_bits;
        int     len;

        j = 0;
        len = src->size_a;
        len_bits = 0;
        while(len > 1 && ++len_bits)
                len /= 2;

        while(j <= len_bits)
        {
                len = src->size_a;
                while(!Is_sorted_stack(src) && len--)
                {
                        if (((src->stack_a[0] >> j) & 1) == 0)
                                push("pb\n", src);
                        else
                                ra(src->stack_a, src->size_a, "up", "a");
                }
                sort_elements_stk_b(len_bits, j + 1, src, src->size_b);
		j++;
        }
        while(src->size_b != 0)
                push("pa\n", src);
}
