/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eiscan <eiscan@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:08:51 by eiscan            #+#    #+#             */
/*   Updated: 2022/05/22 16:09:04 by eiscan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	chartobit(int c, int pid)
{
	int				i;
	unsigned char	data;

	i = 128;
	data = c;
	while (i > 0)
	{
		if (data / i)
		{
			kill(pid, SIGUSR1);
			data -= i;
		}
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i /= 2;
	}
}

int	main(int ac, char **av)
{
	static int	i;
	int			pid;
	char		*str;

	if (ac == 3)
	{	
		while (av[1][i])
		{
			if (!ft_strchr("0123456789", av[1][i++]))
				return (1);
		}
		pid = ft_atoi(av[1]);
		str = av[2];
		while (*str)
		{
			chartobit(*str, pid);
			str++;
		}
		if (*av[2])
			chartobit('\n', pid);
	}
	return (0);
}
