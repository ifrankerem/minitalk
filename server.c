/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:52:22 by iarslan           #+#    #+#             */
/*   Updated: 2025/03/14 01:13:41 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int bit)
{
	static char	c;
	static int	x;

	if (bit == SIGUSR1)
		c = ((c << 1) | 1);
	else if (bit == SIGUSR2)
		c = c << 1;
	x++;
	if (x == 8)
	{
		write(1, &c, 1);
		c = 0;
		x = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("my pid: %d ", pid);
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
	}
}
