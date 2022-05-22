/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:59:31 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/05/22 18:56:34 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	ft_create_philos(t_info *info)
{
	int i;
	pthread_t	monitoring;

	i = 0;
	info->created_at = ft_get_time();
	while (i < info->nb_philos)
	{
		info->philo[i].id = i;
		info->philo[i].philo_info = info;
		info->philo[i].last_meal = info->created_at;
		info->philo[i].should_die = 0;
		info->philo[i].ate = 0;
		pthread_create(&info->philo[i].thread, NULL, routine, &info->philo[i]);
		pthread_create(&monitoring, NULL, ft_check_philos, &info->philo[i]);
		pthread_detach(monitoring);
		i++;
		usleep(200);
	}
	if (info->nb_t_eat >= 0)
	{
		pthread_create(&monitoring, NULL, ft_is_philo_hungry, info);
		pthread_detach(monitoring);
	}
}

int	ft_init(t_info *info)
{
	int	i;

	if (!info)
		return(1);
	i = 0;
	info->philo = ft_calloc(info->nb_philos, sizeof(t_philo));
	info->forks = ft_calloc(info->nb_philos, sizeof(pthread_mutex_t));
	if (!info->philo || !info->forks)
		return (1);
	pthread_mutex_init(&info->finish_lock, NULL);
	while (i < info->nb_philos)
		pthread_mutex_init(&info->forks[i++], NULL);
	ft_create_philos(info);
	return (0);
}