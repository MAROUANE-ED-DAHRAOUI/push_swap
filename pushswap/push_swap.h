/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-dahr <med-dahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:57:51 by med-dahr          #+#    #+#             */
/*   Updated: 2024/07/24 15:57:52 by med-dahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_src
{
	int		*stack_a;
	int		*stack_b;
	int		*indx;
	int		indx_num;
	char	*add_args;
	int		size_a;
	int		size_b;
	int		range;

}			t_src;

int			get_index(int *indx, int nbr, int size);
int			is_valide_input(char **av, int ac);
int			process_str(char *str);
int			succes_args(char ch1, char ch2, char ch3);
void		stacks_init(int ac, char **av, t_src *src);
int			lenght_words(char const *av, char c);
void		ft_args_join(char **av, int ac, t_src *src);
void		convert_numbers(t_src *src);
long long	ft_itoa_num(char *str, t_src *src);
void		check_dup(t_src *src);
void		order_rather_index(t_src *src);
int			*bubble_sort(int *arr, int len);
void		check_action(t_src *src);
int			if_sorted(t_src *src);
void		three_sorting(t_src *src);
void		five_or_four_sorting(t_src *src);
int			ft_min(t_src *src, int size);
void		range(t_src *src, int end);
int			get_index(int *arr, int nbr, int size);
int			ft_max_num(t_src *src);
int			ft_min_num(t_src *src);
int			min_num_pos(t_src *src, int size);
void		free_all(t_src *src);
void		push_all_to_stack_a(t_src *src);
void		push(char *ptr, t_src *src);
void		swap(int *arr, int size);
void		rab(int *arr, int size, char *s2);
void		rrab(int *arr, int size, char *s2);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_memmove(void *dst, const void *src, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			len_word(char const *s, char c, int i);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
void		free_err(t_src *src, char *str);

#endif
