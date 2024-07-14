#include "push_swap.h"

void	ft_args_join(char **av, int ac, t_src *src)
{
	char	*cp1;
	char 	*cp2;
	int	k;

	k = 0;
	cp2 = ft_strdup("");
	while(++k < ac && av[k] != NULL)
	{
		cp1 = ft_strjoin(cp2, av[k]);
		if(cp2)
			free(cp2);
		if(k != ac - 1)
		{
			cp2 = ft_strjoin(cp1, " ");
			if(cp1)
				free(cp1);
			cp1 = cp2;
		}
	}
	src->add_args = ft_strdup(cp1);
	if(src->add_args == NULL)
		free_err(src, "Error in join args\n");
	if(cp1)
		free(cp1);
}
