/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetaj <emetaj@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:19:12 by emetaj            #+#    #+#             */
/*   Updated: 2023/04/12 15:42:49 by emetaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include <stdio.h>

/* -Declare global variable "g_message" of type "t_message"*/

static t_message	g_message;

/*sigusr_handler(int signum):
This function is a signal handler. It takes an integer 'signum' as an argument, which represents the signal number.
The function processes the incoming signal and updates the global 'g_message' variable accordingly.
g_message.bit++: Increments the 'bit' field of the 'g_message' structure.
g_message.character <<= 1: Shifts the bits of the 'character' field of 'g_message' to the left by 1 position.
If the received signal is SIGUSR1, it adds 1 to the 'character' field of 'g_message'.
If the 'bit' field of 'g_message' reaches 8 (which means a full byte has been received), the following steps are performed:
The received character is written to the standard output (file descriptor 1).
The 'bit' and 'character' fields of 'g_message' are reset to 0.*/
void	sigusr_handler(int signum)
{
	g_message.bit++;
	g_message.character <<= 1;
	if (signum == SIGUSR1)
		g_message.character += 1;
	if (g_message.bit == 8)
	{
		write(1, &g_message.character, 1);
		g_message.bit = 0;
		g_message.character = 0;
	}
}

/*main function:
The main function of the program performs the following steps:
Get the process ID (pid) using the getpid() function and print it to the console.
This can be used by other processes to send signals to this process.
Set up signal handlers for SIGUSR1 and SIGUSR2 signals. Both signals will be handled by the sigusr_handler function.
Initialize the 'bit' and 'character' fields of the 'g_message' structure to 0.
Enter an infinite loop, where the program will pause and wait for incoming signals.
When a signal is received, the sigusr_handler function will be called, and the program will process the signal as described earlier.
The program will continue to listen for signals and process them until it is terminated by the user.*/
int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID: %i \n", pid);
	signal(SIGUSR1, sigusr_handler);
	signal(SIGUSR2, sigusr_handler);
	g_message.bit = 0;
	g_message.character = 0;
	while (1)
		pause();
}
