/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <emetaj@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:31:59 by emetaj            #+#    #+#             */
/*   Updated: 2023/05/10 14:45:41 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "../libft/libft.h"

typedef struct s_stacks
{
	int		*a;
	int		*b;
	char	**tmp;
	int		a_size;
	int		b_size;
	char	*join_args;
}			t_stacks;

void			rotate(int *array, int size, char *direction, char *list);
void			swap(char *str, int *array, int size);
void			push(char *str, t_stacks *s);
void			sort_three_elements(t_stacks *s);
void			sort_four_to_five_elements(t_stacks *s);
void			radix_sort(t_stacks *s);
void			parse_numbers(t_stacks *s);
void			create_index(t_stacks *s);
void			init_stacks(int argc, char **argv, t_stacks *s);
void			free_errormsg(t_stacks *s, char *msg);
void			exit_sorted_dup(t_stacks *s, int i);
int				is_array_sorted(t_stacks *s);
long			ft_atol(char *nptr, t_stacks *s, char **tmp);
void			free_parsedwords(t_stacks *s, char **parsedwords);

#endif
