/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eiscan <eiscan@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:09:28 by eiscan            #+#    #+#             */
/*   Updated: 2022/05/22 16:09:32 by eiscan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_strchr(const char *s, int c);
void	ft_itoa(int pid);
int		ft_atoi(char *str);
size_t	ft_strlen(char *str);
void	chartobit(int c, int pid);
void	zerone(int signal);
void	bitochar(int d);

#endif
