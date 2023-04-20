/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <emetaj@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:06:12 by emetaj            #+#    #+#             */
/*   Updated: 2023/04/13 18:10:27 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h> 	/* open */
# include <stdio.h> 	/* perror */
# include <stdlib.h> 	/* exit */
# include <unistd.h> 	/* write, access */

# ifdef __linux__
#  include "../minilibx-linux/mlx.h"
#  define W_UP 119
#  define S_DOWN 115
#  define A_LEFT 97
#  define D_RIGHT 100
#  define ESC 65307
# endif

# define PIXEL 64

typedef struct s_img
{
	void			*wall;
	void			*way;
	void			*coin;
	void			*exitd;
	void			*pr;
	void			*pl;
	void			*ple;
	void			*pu;
	void			*pd;
}					t_img;

typedef struct s_map
{
	char			**map;
	int				x;
	int				y;
}					t_map;

typedef struct s_main
{
	void			*mlx;
	void			*win;
	int				p_x;
	int				p_y;
	int				coincount;
	int				movecount;
	int				playercount;
	int				exitcount;
	int				tmp;
	int				exitflag;
	t_map			*map;
	t_img			*img;
}					t_main;

t_main				*main_init(char *path);
char				**map_init(char *path, t_main *main);
void				ft_map_check(t_main *main);
void				ft_map_check2(t_main *main);
void				xpm_to_img(t_main *main);
int					key_event(int key, t_main *main);
int					render(t_main *main);
void				write_move_count(t_main *main);
void				ft_error(char *errorcode, t_main *main);
void				*ft_calloc(size_t count, size_t size);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_itoa(int n);
int					ft_destroy(t_main *main);

#endif
