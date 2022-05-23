/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:40:22 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/05/23 16:12:33 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	*ft_is_philo_hungry(void *args)
{
	t_philo	*philo;

	philo = args;
	while (!philo->philo_info->finished)
	{
		if (philo->philo_info->all_ate == philo->philo_info->nb_philos)
			philo->philo_info->finished = 1;
		usleep (180);
	}
	return (NULL);
}

void	*ft_check_philos(void *args)
{
	t_philo	*philo;

	philo = args;
	// printf ("last eat = %d\n", (philo->philo_info->t_die + philo->last_meal));
	// printf ("get_timr = %lld\n", philo->philo_info->created_at - ft_get_time());
	while(!philo->philo_info->finished)
	{
		if ((philo->last_meal + philo->philo_info->t_die) <= ft_get_time() - philo->philo_info->created_at)
		{
			// printf ("-----/%lld\n", ft_get_time());
			// printf ("-----/%d\n", philo->last_meal);
			print_msg_mutex("died", philo);
			philo->should_die = 1;
			philo->philo_info->finished = 1;
		}
		usleep (180);
	}
	return (NULL);
}

void	*routine(void *args)
{
	t_philo	*philo;ƒ
	int		l_fork;
	int		r_fork;

	philo = (t_philo *)args;
	while (!philo->should_die && !philo->philo_info->finished)
	{
		r_fork = philo->id;
		l_fork = (philo->id + 1) % philo->philo_info->nb_philos;
		grab_fork(philo, r_fork);
		if (philo->philo_info->nb_philos == 1)
		{
			usleep((philo->philo_info->t_die + 100) * 1000);
			break ;
		}
		grab_fork(philo, l_fork);
		philo_eating(philo);
		forks_down(philo, r_fork, l_fork);
		sleep_think(philo);
		usleep (180);
	}
	return (NULL);
}