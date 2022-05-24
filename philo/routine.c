/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:40:22 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/05/23 18:35:58 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	*ft_is_philo_hungry(void *args)
{
	t_info	*philo;

	philo = args;
	while (!philo->finished)
	{
		if (philo->all_ate == philo->nb_philos)
			philo->finished = 1;
		usleep (198);
	}
	return (NULL);
}

void	*ft_check_philos(void *args)
{
	t_philo	*philo;

	philo = args;
	while (!philo->philo_info->finished)
	{
		if ((philo->last_meal + philo->philo_info->t_die) <= ft_get_time() - \
				philo->philo_info->created_at)
		{
			print_msg_mutex("died", philo);
			philo->should_die = 1;
			philo->philo_info->finished = 1;
		}
		usleep (198);
	}
	return (NULL);
}

void	*routine(void *args)
{
	t_philo	*philo;
	int		l_fork;
	int		r_fork;

	philo = (t_philo *)args;
	while (!philo->should_die && !philo->philo_info->finished)
	{
		r_fork = philo->id;
		l_fork = (philo->id + 1) % philo->philo_info->nb_philos;
		grab_fork(philo, r_fork, 1);
		if (philo->philo_info->nb_philos == 1)
		{
			usleep((philo->philo_info->t_die + 100) * 1000);
			break ;
		}
		grab_fork(philo, l_fork, 2);
		philo_eating(philo);
		forks_down(philo, r_fork, l_fork);
		sleep_think(philo);
		usleep (198);
	}
	return (NULL);
}
