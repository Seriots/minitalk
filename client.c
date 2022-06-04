/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:20:42 by lgiband           #+#    #+#             */
/*   Updated: 2022/05/31 13:59:09 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

const char	*g_message;

void	send_message(size_t *current_letter, size_t *end_char, int pid_server)
{
	unsigned char	c;

	c = g_message[*current_letter];
	c = c << (*end_char);
	if (c / 128 == 0)
	{
		*end_char += 1;
		kill (pid_server, SIGUSR1);
	}
	else
	{
		*end_char += 1;
		kill (pid_server, SIGUSR2);
	}
	if (*end_char == 8)
	{
		*current_letter += 1;
		*end_char = 0;
	}
}

void	get_response(int sig, siginfo_t *siginfo, void *context)
{
	static size_t	current_letter;
	static size_t	end_char;

	(void)context;
	if (sig == SIGUSR2)
	{
		if (current_letter == ft_strlen(g_message) + 1 && end_char == 0)
			ft_printf("Message has been send !\n");
		else
			ft_printf("Fail !\n");
		exit(EXIT_SUCCESS);
	}
	if (current_letter == 0 && end_char == 0)
		end_char = 1;
	send_message(&current_letter, &end_char, siginfo->si_pid);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sigact;
	size_t				j;
	int					pid_server;

	if (argc != 3)
		return (0);
	ft_memset(&sigact, '\0', sizeof(sigact));
	sigact.sa_sigaction = get_response;
	sigact.sa_flags = SA_SIGINFO;
	j = 0;
	pid_server = ft_atoi(argv[1]);
	if (pid_server <= 0)
		return (0);
	g_message = argv[2];
	if (ft_strlen(g_message) == 0)
		return (0);
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	send_message(&j, &j, pid_server);
	while (1)
		sleep(-1);
	return (0);
}
