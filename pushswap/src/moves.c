#include "push_swap.h"

void	rab(int *arr, int size, char *s2)
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
}

void	rrab(int *arr, int size, char *s2)
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