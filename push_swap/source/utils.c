/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:30:21 by abeaufil          #+#    #+#             */
/*   Updated: 2025/01/31 20:55:52 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ps_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ps_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

int	ps_atoi(const char *nptr)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (res > (INT_MAX - (*nptr - '0')) / 10)
			exit_error(NULL, NULL, 1);
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return ((int)(res * sign));
}

void	ps_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ps_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ps_putchar_fd(s[i], fd);
		i++;
	}
}
