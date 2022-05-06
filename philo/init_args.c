/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <mrx.ga10@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:55:54 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/05/06 16:55:55 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo/include/philo.h"

void	ft_get_args(t_arg *args, int ac, char *av[])
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

void	ft_check_args(t_arg args, int ac)
{
	if (ac == 6 && args.nb_t_eat <= 0)
		ft_puterr("ERROR : wrong num ");
	if (args.nb_philos <= 0)
		ft_puterr("ERROR : wrong num of philo");
	if (args.t_die < 60)
		ft_puterr("Wrong argument");
	if (args.t_eat < 60)
		ft_puterr("Wrong argument");
	if (args.t_sleep < 60)
		ft_puterr("Wrong argument");
}
