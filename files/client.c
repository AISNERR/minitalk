/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisner <aisner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 05:49:39 by aisner            #+#    #+#             */
/*   Updated: 2022/01/23 13:51:51 by aisner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	int		pid;
	char	*aim;
	int		i;

	if (argc != 3)
		error_message("\033[0;33mInvalid configuration\033[0m\n", 1);
	if (!validation(argv[1]))
		error_message("\033[0;33mInvalid PID\033[0m\n", 1);
	pid = ft_atoi(argv[1]);
	aim = argv[2];
	i = -1;
	while (aim[++i])
		byte_trans(pid, aim[i]);
	byte_trans(pid, '\0');
}
