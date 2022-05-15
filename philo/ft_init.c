/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:59:31 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/05/15 18:20:50 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	ft_create_philos(t_info *info)
{
	int i;

	i = 0;
	while (i < info->nb_philos)
	{
		info->philo[i].id = i;
		i++;
	}
}

int	ft_init(t_info *info)
{
	int	i;

	i = 0;
	info->philo = malloc(sizeof(t_philo) * info->nb_philos);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->nb_philos);
	if (!info->philo || !info->forks)
		return (1);
	while (i < info->nb_philos)
		pthread_mutex_init(&info->forks[i++], NULL);
	return (1);
}