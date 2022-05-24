/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:11:55 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/05/24 21:21:34 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include_bonus/philo_bonus.h"

void	is_integer(int ac, char *av[])
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

void	ft_puterr(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
}
