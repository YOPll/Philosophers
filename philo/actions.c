/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:59:31 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/05/23 18:39:31 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	sleep_think(t_philo *philo)
{
	while (!(philo->last_eat + philo->philo_info->t_eat + \
		philo->philo_info->t_sleep <= ft_current_time(philo)))
		usleep (180);
	print_msg_mutex("is thinking", philo);
	return (1);
}

int	philo_eating(t_philo *philo)
{
	while (!(philo->last_eat + \
		philo->philo_info->t_eat <= ft_current_time(philo)))
		usleep (180);
	philo->last_meal = ft_current_time(philo);
	philo->ate++;
	if (philo->ate == philo->philo_info->nb_t_eat)
		philo->philo_info->all_ate++;
	return (1);
}

int	forks_down(t_philo *philo, int id1, int id2)
{
	print_msg_mutex("is sleeping", philo);
	pthread_mutex_unlock(&philo->philo_info->forks[id1]);
	pthread_mutex_unlock(&philo->philo_info->forks[id2]);
	return (1);
}

void	grab_fork(t_philo *philo, int id, int i)
{
	pthread_mutex_lock(&philo->philo_info->forks[id]);
	print_msg_mutex("has taken a fork", philo);
	if (i == 2)
	{
		philo->last_eat = ft_current_time(philo);
		print_msg_mutex("is eating", philo);
	}
}
