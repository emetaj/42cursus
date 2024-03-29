/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <emetaj@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:12:30 by emetaj            #+#    #+#             */
/*   Updated: 2023/05/10 14:41:45 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	exit_sorted_dup(t_stacks *s, int i)
{
	int	j;

	j = 0;
	if (i == 0)
	{
		while (i < s->a_size)
		{
			j = i + 1;
			while (j < s->a_size)
			{
				if (s->a[i] == s->a[j])
					free_errormsg(s, "Error\n");
				j++;
			}
			i++;
		}
	}
	if (is_array_sorted(s))
		free_errormsg(s, "");
}

void	free_parsedwords(t_stacks *s, char **parsedwords)
{
	int	i;

	i = 0;
	while (parsedwords[i])
	{
		free(parsedwords[i]);
		i++;
	}
	free(parsedwords);
	free_errormsg(s, "Error\n");
}

void	parse_numbers(t_stacks *s)
{
	char	**tmp;
	int		i;
	int		z;

	z = 0;
	tmp = ft_split(s->join_args, ' ');
	i = 0;
	while (tmp[i])
	{
		if (tmp[i][0] != '\0')
		{
			s->a[z++] = ft_atol(tmp[i], s, tmp);
		}
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

void	init_stacks(int argc, char **argv, t_stacks *s)
{
	int	i;

	i = 0;
	s->a_size = 0;
	s->b_size = 0;
	while (--argc)
	{
		if (count_strings(argv[i + 1], ' '))
			s->a_size += count_strings(argv[i + 1], ' ');
		else
			s->a_size++;
		i++;
	}
	s->a = malloc(s->a_size * sizeof * s->a);
	if (!s->a)
		free_errormsg(s, "Error\n");
	s->b = malloc(s->a_size * sizeof * s->b);
	if (!s->b)
		free_errormsg(s, "Error\n");
}

void	create_index(t_stacks *s)
{
	int		i;
	int		j;
	int		k;
	int		*new_a;

	new_a = malloc(s->a_size * sizeof * new_a);
	if (!new_a)
		free_errormsg(s, "Error \n");
	i = -1;
	while (++i < s->a_size)
	{
		k = 0;
		j = -1;
		while (++j < s->a_size)
			if (s->a[i] > s->a[j])
				k++;
		new_a[i] = k;
	}
	i = s->a_size;
	while (i--)
		s->a[i] = new_a[i];
	free(new_a);
}
