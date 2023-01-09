#include "get_next_line.h"

/*
** ft_get_line()
** Allocates a new string and copies the characters from 'save' up until the
** first occurrence of the newline character ('\n') into the new string.
** Returns the new string.
*/
char	*ft_get_line(char *save)
{
	char	*str; // new string to be returned
	int		i; // counter variable

	i = 0;
	if (!save[i]) // if 'save' is empty
		return (NULL); // return NULL
	while (save[i] && save[i] != '\n') // while the character at index 'i' in 'save' is not NULL and is not '\n'
		i++; // increment 'i'
	str = malloc(sizeof(char) * (i + 2)); // allocate memory for 'str'
	if (!str) // if allocation failed
		return (NULL); // return NULL
	i = 0;
	while (save[i] && save[i] != '\n') // while the character at index 'i' in 'save' is not NULL and is not '\n'
	{
		str[i] = save[i]; // copy character from 'save' to 'str'
		i++; // increment 'i'
	}
	if (save[i] == '\n') // if the character at index 'i' in 'save' is '\n'
	{
		str[i] = save[i]; // copy character from 'save' to 'str'
		i++; // increment 'i'
	}
	str[i] = '\0'; // add NULL terminator to 'str'
	return (str); // return 'str'
}

/*
** ft_save()
** Allocates a new string and copies the characters from 'save' after the
** first occurrence of the newline character ('\n') into the new string.
** Frees the memory used by 'save' and returns the new string.
*/
char	*ft_save(char *save)
{
	char	*str; // new string to be returned
	int		i; // counter variable
	int		a; // another counter variable

	i = 0;
	while (save[i] && save[i] != '\n') // while the character at index 'i' in 'save' is not NULL and is not '\n'
		i++; // increment 'i'
	if (!save[i]) // if the character at index 'i' in 'save' is NULL
	{
		free(save); // free memory used by 'save'
		return (NULL); // return NULL
	}
	str = malloc(sizeof(char) * (ft_str_len(save) - i + 1)); // allocate memory for 'str'
	if (!str) // if allocation failed
		return (NULL); // return NULL
	i++; // increment 'i'
	a = 0;
	while (save[i]) // while the character at index 'i' in 'save' is not NULL
		str[a++] = save[i++];
	str[a] = '\0';
	free(save);
	return(str);
}
/*
** ft_read_save()
** Reads the file with descriptor 'fd' and stores the contents in 'save'.
** Continues reading the file until it reaches the end or until it finds
** a newline character ('\n').
** Returns 'save'.
*/
char	*ft_read_save(int fd, char *save)
{
	int		ret; // variable to store the return value of 'read()'
	char	*buffer; // temporary buffer to store data read from the file

	ret = 1; // initialize 'ret' to 1
	buffer = malloc(BUFFER_SIZE + 1); // allocate memory for 'buffer'
	if (!buffer) // if allocation failed
		return (NULL); // return NULL
	while (!ft_strchr(save, '\n') && ret != 0) // while 'save' does not contain a newline character and 'read()' has not reached the end of the file
	{
		ret = read(fd, buffer, BUFFER_SIZE); // read from the file and store the number of bytes read in 'ret'
		if (ret == -1) // if there was an error while reading the file
		{
			free(save); // free memory used by 'save'
			save = NULL; // set 'save' to NULL
			free(buffer); // free memory used by 'buffer'
			return (NULL); // return NULL
		}
		buffer[ret] = '\0'; // add NULL terminator to 'buffer'
		save = ft_strjoin(save, buffer); // concatenate 'save' and 'buffer' and store the result in 'save'
	}
	free(buffer); // free memory used by 'buffer'
	return (save); // return 'save'
}

/*
** get_next_line()
** Reads a file line by line and returns the next line each time it is called.
** 'fd' is the file descriptor of the file to be read.
** Returns a string containing the next line of the file.
*/
char	*get_next_line(int fd)
{
	static char	*save; // static variable to store data read from the file
	char		*line; // string to store the next line of the file

	if (fd < 0 || BUFFER_SIZE <= 0) // if the file descriptor is invalid or the buffer size is less than or equal to 0
		return (0); // return 0
	save = ft_read_save(fd, save); // read from the file and store the contents in 'save'
	if (!save) // if 'ft_read_save()' returned NULL
		return (NULL); // return NULL
	line = ft_get_line(save); // retrieve the next line of the file from 'save'
	save = ft_save(save); // update 'save' by removing the line that was just read
	return (line); // return the line that was read
}
