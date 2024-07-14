#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_src
{
	int		*stack_a;
	int		*stack_b;
        char            *add_args;
        int             size_a;
        int             size_b;

}       t_src;

int		Is_valide_input(char **av, int ac);
void		order_rather_index(t_src *src);
void		stacks_init(int ac, char **av, t_src *src);
int		lenght_words(char const *av, char c);
void		ft_args_join(char **av, int ac, t_src *src);
void		convert_numbers(t_src *nah);
int		ft_itoa_num(char *str, t_src *src);
void    	check_dup(t_src *src);
int		Is_sorted_stack(t_src *src);
void    	check_action(t_src *src);
void		swap(int *arr, int size);
void    	three_sorting(t_src *src);
void    	five_or_four_sorting(t_src *src);
void		rotate(int *src, int size, char *s1, char *s2);
void    	sorting_radix(t_src *src);
void    	sort_elements_stk_b(int len_bit, int pos, t_src *src, int size_b);
void   	 	push(char *ptr, t_src *src);
int     	ft_strncmp(const char *s1, const char *s2, size_t n);
void    	*ft_memmove(void *dst, const void *src, size_t n);
char    	*ft_strjoin(char const *s1, char const *s2);
char    	*ft_strdup(const char *s);
size_t		ft_strlen(const char *str);
size_t  	ft_strlcpy(char *dst, const char *src, size_t size);
char    	*ft_substr(char const *s, unsigned int start, size_t len);
char    	**ft_split(char const *s, char c);
int      	len_word(char const *s, char c, int i);
void    	free_err(t_src *src, char *str);
#endif
