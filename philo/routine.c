/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:40:22 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/05/21 18:39:58 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	*ft_is_philo_hungry(void *args)
{
	printf("hello");
}

void	*ft_check_philos(void *args)
{
	printf("hello");
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
		grab_fork(philo, r_fork);
		if (philo->philo_info->nb_philos == 1)
		{
			print_msg_mutex("died", philo);
			usleep(100000);
			break;
		}
		grab_fork(philo, l_fork);
	}
	return (NULL);
}