/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <emetaj@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:19:12 by emetaj            #+#    #+#             */
/*   Updated: 2023/04/13 18:21:32 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include <stdio.h>

/*send(char c, int pid, int signal):
This function sends a character 'c' to a process with the process ID 'pid'
using signals.
The function takes an additional 'signal' parameter, which is used to indicate
if there's an error in sending the character.
If the kill function returns -1, indicating an error in sending the signal,
the program prints an error message and exits with failure status.
The variable 'i' is initialized to 128 (binary: 10000000).
In a loop, the function checks if the current bit (from the most significant
 bit) of the character 'c' is 1 or 0 by performing a bitwise AND operation with
'i'.
If the result is non-zero, a SIGUSR1 signal is sent to the process with ID
 'pid'.
If the result is zero, a SIGUSR2 signal is sent to the process with ID 'pid'.
The variable 'i' is shifted right by 1 bit (i >>= 1) to check the next bit of
the character 'c'.
The program then sleeps for 650 microseconds (usleep(650)) to ensure a small
delay between signal transmissions.
The loop continues until all bits of the character 'c' have been sent.*/
void	send(char c, int pid, int signal)
{
	int	i;

	if (kill(pid, signal) == -1)
	{
		ft_printf("Signal Error, Please try again!");
		exit(EXIT_FAILURE);
	}
	i = 128;
	while (i)
	{
		if (c & i)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i >>= 1;
		usleep(650);
	}
}

/*The main function of the program performs the following steps:
Check if the number of command-line arguments is equal to 3 (the program's name
, the target process ID, and the string to send).
If not, print an error message and exit with failure status.
If the correct number of arguments is provided:
Convert the target process ID (argv[1]) from a string to an integer using the
ft_atoi function.
Iterate through each character of the input string (argv[2]) using the
variable 'i'.
If the character is an ASCII character, call the send function with the
character, target process ID, and SIGUSR2 signal.
If the character is not an ASCII character, call the send function with the
 character, target process ID, and SIGUSR1 signal.
Increment 'i' to process the next character in the string.
Return 0 to indicate successful program execution.
When combined with the previously explained code that listens for
incoming signals, this program can be used to send characters from
one process to another using signals.*/
int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf ("Not enough arguments!");
		exit(EXIT_FAILURE);
	}
	else
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			if (ft_isascii(argv[2][i]))
				send(argv[2][i], pid, SIGUSR2);
			else
				send(argv[2][i], pid, SIGUSR1);
			i++;
		}
		return (0);
	}
}
