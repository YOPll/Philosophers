/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:11:55 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/05/25 17:47:36 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include_bonus/philo_bonus.h"

void	ft_get_args(t_info *args, int ac, char *av[])
{
	args->nb_philos = ft_atoi(av[1]);
	args->t_die = ft_atoi(av[2]);
	args->t_eat = ft_atoi(av[3]);
	args->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		args->nb_t_eat = ft_atoi(av[5]);
	else
		args->nb_t_eat = -1;
}

int	ft_check_args(t_info *args, int ac)
{
	if (ac == 6 && args->nb_t_eat <= 0)
	{
		ft_puterr("ERROR : the number of times each "\
			"philosopher_must_eat is less than 1\n");
		return (1);
	}
	if (args->nb_philos <= 0)
	{
		ft_puterr("ERROR : the number of philosophers is less than 1\n");
		return (1);
	}
	return (0);
}