/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaladri <sgaladri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 22:16:36 by sgaladri          #+#    #+#             */
/*   Updated: 2021/10/21 03:52:00 by sgaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_negative(const char *str, long long int	neg, int i)
{
	neg = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			neg = -1;
			return (neg);
		}
		neg = 1;
	}
	return (neg);
}

int	ft_exception(int flag)
{
	if (flag == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int						i;
	unsigned long long int	result;
	long long int			neg;

	i = 0;
	neg = 1;
	result = 0;
	while (str[i] == 32 || str[i] == 10 || str[i] == 9 || str[i] == 12
		|| str[i] == 13 || str[i] == 11)
		i++;
	neg = ft_negative(str, neg, i);
	i += (neg == 1 || neg == -1);
	neg += (neg == 0);
	while (str[i])
	{
		if (str[i] < 48 || 57 < str[i])
			return (result * neg);
		else
			result = (result * 10) + (long long int)(str[i] - '0');
		i++;
	}
	if (i > 19 || result >= 9223372036854775808ULL)
		return (ft_exception(neg));
	return ((int) result * neg);
}
