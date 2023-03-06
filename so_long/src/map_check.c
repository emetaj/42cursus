/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <emetaj@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:23:27 by emetaj            #+#    #+#             */
/*   Updated: 2023/03/06 13:23:28 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	ft_floodfill(t_main *main, int x, int y, int *count_c)
{
	if (x <= 0 || x >= main->map->x || y <= 0 || y >= main->map->y
		|| main->map->map[y][x] == '1' || main->map->map[y][x] == 'c'
		|| main->map->map[y][x] == 'o' || main->map->map[y][x] == 'e'
		|| main->map->map[y][x] == 'E' || main->map->map[y][x] == 'X')
	{
		if (main->map->map[y][x] == 'E')
			main->exitflag = 1;
		return ;
	}
	if (main->map->map[y][x] == 'C')
	{
		(*count_c)--;
		main->map->map[y][x] = 'c';
	}
	else if (main->map->map[y][x] == '0')
		main->map->map[y][x] = 'o';
	ft_floodfill(main, x, (y + 1), count_c);
	ft_floodfill(main, x, (y - 1), count_c);
	ft_floodfill(main, (x + 1), y, count_c);
	ft_floodfill(main, (x - 1), y, count_c);
}

static void	ft_restore(t_main *main)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < main->map->y)
	{
		x = 0;
		while (x < main->map->x)
		{
			if (main->map->map[y][x] == 'c')
				main->map->map[y][x] = 'C';
			else if (main->map->map[y][x] == 'e')
				main->map->map[y][x] = 'E';
			else if (main->map->map[y][x] == 'o')
				main->map->map[y][x] = '0';
			x++;
		}
		y++;
	}
}

static void	ft_check_valid_map_path(t_main *main)
{
	int	count_c;

	count_c = main->coincount;
	ft_floodfill(main, main->p_x, main->p_y, &count_c);
	if (count_c != 0)
		ft_error("Error\nNo valid Path, access to Coin is blocked", main);
	ft_restore(main);
	if (main->exitflag == 0)
		ft_error("Error\nNo valid Path, access to Exit is blocked", main);
	return ;
}

void	ft_map_check(t_main *main)
{
	int	i;

	if (main->exitcount < 1)
		ft_error("Error\nExit not found", main);
	else if (main->coincount < 1)
		ft_error("Error\nCoin not found", main);
	else if (main->playercount < 1 || main->playercount > 1)
		ft_error("Error\nPlayer not found or more than one", main);
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
	ft_check_valid_map_path(main);
}
