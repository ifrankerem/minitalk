/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:52:17 by iarslan           #+#    #+#             */
/*   Updated: 2025/03/16 17:37:19 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_flag = 0;

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	number;

	number = 0;
	i = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		number = number * 10 + (nptr[i] - 48);
		i++;
	}
	return (number * sign);
}

void	charsignal(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_flag = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		while (g_flag == 0)
			pause();
	}
}

void	ft_flag(int signal)
{
	if (signal == SIGUSR1)
		g_flag = 1;
}

void	pidcontrol(char *av)
{
	int	server_pid;

	server_pid = ft_atoi(av);
	if (kill(server_pid, 0) == -1 || server_pid > 4194304 || server_pid == -1)
	{
		ft_printf("Invalıd PID!\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 3)
	{
		pidcontrol(av[1]);
		signal(SIGUSR1, ft_flag);
		while (av[2][i])
		{
			charsignal(ft_atoi(av[1]), av[2][i]);
			i++;
		}
		charsignal(ft_atoi(av[1]), '\n');
		ft_printf("Message received.\n");
	}
	else
		ft_printf("Wrong Argument Number!");
}
