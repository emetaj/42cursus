/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <emetaj@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:22:45 by emetaj            #+#    #+#             */
/*   Updated: 2023/03/06 13:22:45 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	draw_map2(t_main *main, int y, int x)
{
	if (main->map->map[y][x] == '1')
		mlx_put_image_to_window(main->mlx, main->win,
			main->img->wall, x, y);
	else if (main->map->map[y][x] == '0')
		mlx_put_image_to_window(main->mlx, main->win,
			main->img->way, x, y);
	else if (main->map->map[y][x] == 'P')
	{
		mlx_put_image_to_window(main->mlx, main->win, main->img->pl, x, y);
		main->p_y = y;
		main->p_x = x;
	}
	else if (main->map->map[y][x] == 'E')
		mlx_put_image_to_window(main->mlx, main->win, main->img->exitd, x, y);
	else if (main->map->map[y][x] == 'C')
		mlx_put_image_to_window(main->mlx, main->win, main->img->coin, x, y);
	else if (main->map->map[y][x] != '\n')
		ft_error("Error\nWrong character in Map file", main);
	x++;
	return (x);
}

void	draw_map(t_main *main)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < (main->map->y))
	{
		while (x < (main->map->x))
			x = draw_map2(main, y, x);
		y++;
		x = 0;
	}
}
