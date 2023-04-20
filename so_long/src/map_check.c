/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <emetaj@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:23:27 by emetaj            #+#    #+#             */
/*   Updated: 2023/04/14 12:10:41 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_check_other_char(t_main *main)
{
	int	i;
	int	j;

	i = 0;
	while (i < main->map->y)
	{
		j = 0;
		while (j < main->map->x)
		{
			if (main->map->map[i][j] != '1' && main->map->map[i][j] != '0'
				&& main->map->map[i][j] != 'C' && main->map->map[i][j] != 'E'
				&& main->map->map[i][j] != 'P')
				ft_error("Error\nInvalid character in map", main);
			j++;
		}
		i++;
	}
}

void	ft_check_border(t_main *main)
{
	int	i;

	i = -1;
	while (++i < main->map->y - 1)
	{
		if (main->map->map[i][0] != '1')
			ft_error("Error\nMAP: (LEFT) border of wall", main);
		else if (main->map->map[i][main->map->x - 1] != '1')
			ft_error("Error\nMAP: (RIGHT) border of wall", main);
	}
	i = -1;
	while (++i < main->map->x)
	{
		if (main->map->map[0][i] != '1')
			ft_error("Error\nMAP: (UP) border of wall", main);
		if (main->map->map[main->map->y - 1][i] != '1')
			ft_error("Error\nMAP: (DOWN) border of wall", main);
	}
}

void	ft_map_check(t_main *main)
{
	if (main->exitcount < 1 || main->exitcount > 1)
		ft_error("Error\nExit not found or more than one", main);
	else if (main->coincount < 1)
		ft_error("Error\nCoin not found", main);
	else if (main->playercount < 1 || main->playercount > 1)
		ft_error("Error\nPlayer not found or more than one", main);
	ft_check_border(main);
	ft_check_other_char(main);
}
