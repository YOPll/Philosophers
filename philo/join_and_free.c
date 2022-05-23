/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:59:31 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/05/23 14:49:41 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	join_and_free(t_info *philo)
{
	int	i;

	i = 0;
	while (i < philo->nb_philos)
		pthread_join(philo->philo[i++].thread, NULL);
	free(philo->philo);
	i = 0;
	while (i < philo->nb_philos)
		pthread_mutex_destroy(&philo->forks[i++]);
	pthread_mutex_destroy(&philo->finish_lock);
	free(philo->forks);
	free(philo);	
}