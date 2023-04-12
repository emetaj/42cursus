/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:06:29 by emetaj            #+#    #+#             */
/*   Updated: 2023/01/10 13:06:34 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_line(char *save)
{
	char	*str;
	int		i;

	i = 0;
	if (!save[i])
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (0);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_save(char *save)
{
	char	*str;
	int		i;
	int		a;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	str = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!str)
		return (0);
	i++;
	a = 0;
	while (save[i])
		str[a++] = save[i++];
	str[a] = '\0';
	free(save);
	return (str);
}

char	*ft_read_save(int fd, char *save)
{
	int		ret;
	char	*buffer;

	ret = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (!ft_strchr(save, '\n') && ret != 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
		{
			free(save);
			save = 0;
			free(buffer);
			return (0);
		}
		buffer[ret] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read_save(fd, save);
	if (!save)
		return (0);
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}
/*
#include <stdio.h>
int	main(void)
{
	int	fd;
        char *filename;

        filename = "test.txt";
	fd = 0;
		fd = open(filename, O_RDONLY);
		printf("fd : %d\n", fd);
		printf("%s \n", get_next_line(fd));
		printf("%s \n", get_next_line(fd));
		printf("%s \n", get_next_line(fd));

	return (0);
}
*/
