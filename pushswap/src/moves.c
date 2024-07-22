#include "push_swap.h"

/*void	rab(int *arr, int size, char *s2)
{
	int tmp;

	if (size <= 1)  
        return;
	
	tmp = arr[0];
	ft_memmove(arr, arr + 1, sizeof(int) * (size - 1));
	arr[size - 1] = tmp;
	write(1, "r", 1);
	write(1, s2, ft_strlen(s2));
    write(1, "\n", 1);
}*/
void rab(int *arr, int size, char *s2)
{
    int tmp;
    int i;

    if (size <= 1)
        return;

    i = 0;
    tmp = arr[0];
    while (i < size - 1)
    {
        arr[i] = arr[i + 1];
        i++;
    }
    arr[size - 1] = tmp;

    write(1, "r", 1);
    write(1, s2, ft_strlen(s2));
    write(1, "\n", 1);
}


/*void	rrab(int *arr, int size, char *s2)
{
	int tmp;

	if(size == 0)
		return ;
	tmp = arr[size - 1];
	ft_memmove(arr + 1, arr, sizeof(int) * (size - 1));
	arr[0] = tmp;
	write(1, "rr", 2);
	write(1, s2, ft_strlen(s2));
	write(1, "\n", 1);

}*/
void rrab(int *arr, int size, char *s2) {
    int tmp;
    int i;

    if (size <= 1)
        return;

    tmp = arr[size - 1];
    i = size - 1;
    while (i > 0) {
        arr[i] = arr[i - 1];
        i--;
    }
    arr[0] = tmp;

    write(1, "rr", 2);
    write(1, s2, ft_strlen(s2));
    write(1, "\n", 1);
}

void	swap(int *arr, int size)
{
	int cp;

	if(size <= 0)
		return;
	cp = arr[0];
	arr[0] = arr[1];
	arr[1] = cp;
	write(1, "sa\n", 3);
}

void	push_all_to_stack_a(t_src *src)
 {
	int	max;

	 max = 0;
	 while(src->size_b != 0)
        {

                max = get_index(src->stack_b, ft_max_num(src), src->size_b);
                if(max <= (src->size_b / 2))
                {
                        while(max != 0)
                        {
                                rab(src->stack_b, src->size_b, "b");
                                max--;
                        }
                        push("pa\n", src);
                }
                else
                {
                        while(src->size_b - max != 0)
                        {
                                rrab(src->stack_b, src->size_b, "b");
                                max++;
                        }
                        push("pa\n", src);

                }
		}
 }

/*void push_all_to_stack_a(t_src *src) {
    int max;
    int i;

    while (src->size_b > 0) {
        max = ft_max_num(src);
        i = get_index(src->stack_b, max, src->size_b);

        if (i <= src->size_b / 2) {
            while (i-- > 0) {
                rab(src->stack_b, src->size_b, "b");
            }
        } else {
            i = src->size_b - i;
            while (i-- > 0) {
                rrab(src->stack_b, src->size_b, "b");
            }
        }
        push("pa\n", src);
    }
}*/

