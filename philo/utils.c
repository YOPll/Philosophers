/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <mrx.ga10@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:40:22 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/05/05 15:40:23 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	is_integer(int ac, char *av[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i <= ac - 1)
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] >= 48 && av[i][j] <= 57) || \
				av[i][j] == 43 || av[i][j] == 45 || av[i][j] == 32)
			{
				j++;
			}
			else
			{
				ft_puterr("Wrong arguments\n");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

void	check_max_and_min(long x)
{
	if (x <= INT_MIN || x > INT_MAX)
		ft_puterr("Wrong argument");
}

int	ft_atoi(const char *str)
{
	int	j;
	int	res;

	j = 1;
	res = 0;
	while (*str == '\t' || *str == '\f' || *str == '\r'
		|| *str == ' ' || *str == '\v' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			j *= -1;
		str++;
	}
	if (*str < '0' || *str > '9')
		ft_puterr("Wrong argument");
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	check_max_and_min(res);
	return (res * j);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

int	ft_puterr(char *str)
{
	ft_putstr_fd(str, 1);
	return (1);
}
