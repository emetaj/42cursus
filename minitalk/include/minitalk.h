/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <emetaj@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 20:21:07 by emetaj            #+#    #+#             */
/*   Updated: 2023/04/12 13:06:55 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_message
{
	int				bit;
	unsigned char	character;
}				t_message;

#endif
