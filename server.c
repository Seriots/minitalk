/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:20:44 by lgiband           #+#    #+#             */
/*   Updated: 2022/05/31 13:49:07 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

unsigned char	*get_space(size_t length, unsigned char *str)
{
	unsigned char	*new_str;
	size_t			i;

	if (length == 1)
	{
		new_str = ft_calloc(sizeof(unsigned char), length + 1);
		if (!new_str)
			return (0);
		return (new_str);
	}
	new_str = ft_calloc(sizeof(unsigned char), length + 1);
	if (!new_str)
	{
		free(str);
		return (0);
	}
	i = -1;
	if (str)
	{
		while (str[++i])
			new_str[i] = str[i];
		free(str);
	}
	return (new_str);
}

int	save_char(unsigned char *str, size_t *i, unsigned char *c, size_t *length)
{
	int	end_message;

	str[*i] = *c;
	*i += 1;
	end_message = 0;
	if (*c == 0)
	{
		ft_printf("%s", str);
		free(str);
		end_message = 1;
		*length = 0;
		*i = 0;
	}
	*c = 0;
	return (end_message);
}

int	print_char(unsigned char *c, unsigned int *end, int new_message, size_t *i)
{
	static unsigned char	*str;
	unsigned char			t;
	static size_t			length;

	t = 0;
	if (new_message == 2)
	{
		t = ft_power(2, 7 - *end);
		*c |= t;
	}
	*end += 1;
	if (*end != 8)
		return (0);
	if (length <= *i)
	{
		length *= 2;
		if (length == 0)
			length = 1;
		str = get_space(length, str);
		if (!str)
			return (-1);
	}
	*end = 0;
	return (save_char(str, i, c, &length));
}

void	reception(int sig, siginfo_t *siginfo, void *context)
{
	static unsigned char	c;
	static unsigned int		end;
	static size_t			i;
	int						new_message;
	int						client_pid;

	(void)context;
	if (sig == 10)
		new_message = 1;
	else if (sig == 12)
		new_message = 2;
	else
		new_message = 0;
	client_pid = siginfo->si_pid;
	new_message = print_char(&c, &end, new_message, &i);
	if (new_message == 0)
		kill(client_pid, SIGUSR1);
	else if (new_message == -1)
	{
		kill(client_pid, SIGUSR2);
		exit(1);
	}
	else
		kill(client_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sigact;

	ft_memset(&sigact, '\0', sizeof(sigact));
	sigact.sa_sigaction = &reception;
	sigact.sa_flags = SA_SIGINFO;
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
		sleep(-1);
}
