/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <emetaj@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:23:27 by emetaj            #+#    #+#             */
/*   Updated: 2023/04/13 17:52:05 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	ft_floodfill(t_main *main, int x, int y, int *count_c)
{
	if (x < 0 || x >= main->map->x || y < 0 || y >= main->map->y
		|| main->map->map[y][x] == '1' || main->map->map[y][x] == 'c'
		|| main->map->map[y][x] == 'o' || main->map->map[y][x] == 'e')
		return ;
	if (main->map->map[y][x] == 'E')
	{
		main->exitflag = 1;
		if (*count_c == 0)
			return ;
	}
	if (main->map->map[y][x] == 'C')
	{
		(*count_c)--;
		main->map->map[y][x] = 'c';
	}
	else if (main->map->map[y][x] == '0')
		main->map->map[y][x] = 'o';
	else if (main->map->map[y][x] == 'E')
		main->map->map[y][x] = 'e';
	ft_floodfill(main, x, y + 1, count_c);
	ft_floodfill(main, x, y - 1, count_c);
	ft_floodfill(main, x + 1, y, count_c);
	ft_floodfill(main, x - 1, y, count_c);
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
	int	x;
	int	y;
	int	count_c;

	x = 0;
	y = 0;
	count_c = 0;
	while (y < main->map->y)
	{
		x = 0;
		while (x < main->map->x)
		{
			if (main->map->map[y][x] == 'C')
				count_c++;
			x++;
		}
		y++;
	}
	ft_floodfill(main, main->p_x, main->p_y, &count_c);
	if (count_c != 0)
		ft_error("Error : Invalid map path, collectibles not reachable", main);
	if (main->exitflag == 0)
		ft_error("Error : Invalid map path, exit not reachable", main);
	ft_restore(main);
}

void	ft_map_check2(t_main *main)
{
	ft_check_valid_map_path(main);
}
