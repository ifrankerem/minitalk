/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:52:22 by iarslan           #+#    #+#             */
/*   Updated: 2025/03/12 18:43:16 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
int	handler(int bit)
{
}
int	main(int ac, char **av)
{
	pid_t pid = getpid();

	if (ac == 3)
	{
		ft_printf(pid);
		while (1)
		{
			signal(SIGUSR1, handler);
			signal(SIGUSR2, handler);
		}
	}
}