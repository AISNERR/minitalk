/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisner <aisner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 06:16:59 by aisner            #+#    #+#             */
/*   Updated: 2022/01/20 07:16:51 by aisner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error_message(char *message, int number)
{
	ft_putstr_fd(message, 2);
	exit(number);
}

int	validation(char *pid)
{
	int	i;

	i = ft_atoi(pid);
	if (i <= 0 || i >= 99999)
		return (0);
	i = -1;
	while (pid[++i])
	{
		if (!(ft_isdigit(pid[i])))
			return (0);
	}
	return (1);
}

void	byte_trans(int pid, char byte)
{
	int	mask;

	mask = 128;
	while (mask > 0)
	{
		if (mask & byte)
		{
			if (kill(pid, SIGUSR1) < 0)
				error_message("\033[0;33mFailed to send a signal.\033[0m\n", -42);
		}
		else
		{
			if (kill(pid, SIGUSR2) < 0)
				error_message("\033[0;33mFailed to send a signal.\033[0m\n", -42);
		}
		mask /= 2;
		usleep(120);
	}
}
