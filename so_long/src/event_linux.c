/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_linux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <emetaj@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:41:21 by emetaj            #+#    #+#             */
/*   Updated: 2023/03/06 13:23:05 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	write_move_cnt(int cnt)
{
	char	*move;

	move = ft_itoa(cnt);
	write(1, "Move count: ", 12);
	write(1, move, ft_strlen(move));
	write(1, "\n", 1);
	free(move);
}

static int	check_esc(t_main *main, int key)
{
	if (key == ESC)
		ft_destroy(main);
	else if (main->map->map[main->p_y][main->p_x] == 'C')
	{
		main->map->map[main->p_y][main->p_x] = '0';
		main->coincount--;
	}
	return (0);
}

int	key_event(int key, t_main *main)
{
	if (key == W_UP && main->map->map[main->p_y - 1][main->p_x] != '1')
	{
		main->p_y--;
		main->img->pl = main->img->pu;
		write_move_cnt(++(main->movecount));
	}
	else if (key == A_LEFT && main->map->map[main->p_y][main->p_x - 1] != '1')
	{
		main->img->pl = main->img->ple;
		main->p_x--;
		write_move_cnt(++(main->movecount));
	}
	else if (key == S_DOWN && main->map->map[main->p_y + 1][main->p_x] != '1')
	{
		main->img->pl = main->img->pd;
		main->p_y++;
		write_move_cnt(++(main->movecount));
	}
	else if (key == D_RIGHT && main->map->map[main->p_y][main->p_x + 1] != '1')
	{
		main->img->pl = main->img->pr;
		main->p_x++;
		write_move_cnt(++(main->movecount));
	}
	return (check_esc(main, key));
}

int	ft_destroy(t_main *main)
{
	int	y;

	mlx_destroy_image(main->mlx, main->img->ple);
	mlx_destroy_image(main->mlx, main->img->pr);
	mlx_destroy_image(main->mlx, main->img->pu);
	mlx_destroy_image(main->mlx, main->img->pd);
	mlx_destroy_image(main->mlx, main->img->wall);
	mlx_destroy_image(main->mlx, main->img->way);
	mlx_destroy_image(main->mlx, main->img->exitd);
	mlx_destroy_image(main->mlx, main->img->coin);
	mlx_destroy_window(main->mlx, main->win);
	mlx_destroy_display(main->mlx);
	y = 0;
	while (y < main->map->y)
		free(main->map->map[y++]);
	free(main->map->map);
	free(main->img);
	free(main->map);
	free(main->mlx);
	free(main);
	exit(0);
	return (0);
}
