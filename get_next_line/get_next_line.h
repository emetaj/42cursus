/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngjokaj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:46:38 by ngjokaj           #+#    #+#             */
/*   Updated: 2022/11/12 09:46:40 by ngjokaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4000
# endif

//get_next_line

char	*get_next_line(int fd);
/**
 * Reads a file from a fd, in my case the pointer line* returns the line from
 * a file discriptor. 
 */
char	*ft_read_save(int fd, char *save);
char	*ft_save(char *save);
char	*ft_get_line(char *save);

//get_nex_line_utils

size_t	ft_str_len(const char *str);
/**
 * computes the length of the string str up to, but not including
 * the terminating null character.
 */
char	*ft_strchr(const char *s, int c);
/**
 * computes the length of the string str up to, but not including
 * the terminating null character.
 */
char	*ft_strjoin(char *s1, char *s2);

#endif
