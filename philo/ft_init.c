/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:59:31 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/05/20 20:47:59 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	ft_create_philos(t_info *info)
{
	int i;
	pthread_t	monitoring;

	i = 0;
	while (i < info->nb_philos)
	{
		info->philo[i].id = i;
		info->philo[i].philo_info = info;
		info->philo[i].last_meal = info->created_at;
		info->philo[i].should_die = 0;
		info->philo[i].ate = 0;
		pthread_create(&info->philo[i].thread, NULL, routine, NULL);
		pthread_create(&monitoring, NULL,);
		pthread_detach(monitoring);
		i++;
		usleep(200);
	}
	// if (info->nb_t_eat >= 0)
	// {
	// 	pthread_create(&);
	// 	pthread_detach();
	// }
	return (1);
}

int	ft_init(t_info *info)
{
	int	i;

	i = 0;
	info->philo = malloc(sizeof(t_philo) * info->nb_philos);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->nb_philos);
	if (!info->philo || !info->forks)
		return (1);
	info->finished = 0;
	info->all_ate = 0;
	pthread_mutex_init(&info->finish_lock, NULL);
	while (i < info->nb_philos)
		pthread_mutex_init(&info->forks[i++], NULL);
	ft_create_philos(info);
	return (0);
}