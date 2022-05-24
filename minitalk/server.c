/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eiscan <eiscan@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:10:15 by eiscan            #+#    #+#             */
/*   Updated: 2022/05/22 16:10:17 by eiscan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bitochar(int d)
{
	static unsigned char	writ;
	static int				i = 7;

	writ += d << i;
	if (i == 0)
	{
		i = 7;
		write(1, &writ, 1);
		writ = 0;
	}
	else
		i--;
}

void	zerone(int signal)
{
	if (signal == SIGUSR1)
		bitochar(1);
	else if (signal == SIGUSR2)
		bitochar(0);
}

int	main(void)
{
	signal(SIGUSR1, zerone);
	signal(SIGUSR2, zerone);
	write(1, "pid : ", 6);
	ft_itoa(getpid());
	while (1)
		pause();
	return (0);
}
