/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:59:31 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/05/23 15:38:07 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	sleep_think(t_philo *philo)
{
	print_msg_mutex("is sleeping", philo);
	usleep(philo->philo_info->t_sleep * 1000);
	print_msg_mutex("is thinking", philo);
}

void	philo_eating(t_philo *philo)
{
	print_msg_mutex("is eating", philo);
	usleep(philo->philo_info->t_eat * 1000);
	philo->last_meal =	ft_current_time(philo);
	philo->ate++;
	if (philo->ate == philo->philo_info->nb_t_eat)
		philo->philo_info->all_ate++;
}

void	forks_down(t_philo *philo, int id1, int id2)
{
	pthread_mutex_unlock(&philo->philo_info->forks[id1]);
	pthread_mutex_unlock(&philo->philo_info->forks[id2]);
}

void	grab_fork(t_philo *philo, int id)
{
	pthread_mutex_lock(&philo->philo_info->forks[id]);
	print_msg_mutex("has taken a fork", philo);
}
