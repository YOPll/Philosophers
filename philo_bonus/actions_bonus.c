/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:30:37 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/05/31 18:54:47 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include_bonus/philo_bonus.h"

void	grab_fork(t_philo *philo, int id, int i)
{
    sem_wait(philo->philo_info->forks);
	print_msg_mutex("has taken a fork", philo);
    philo->last_eat = ft_current_time(philo);
}

void	forks_down(t_philo *philo, int id1, int id2)
{
	print_msg_mutex("is sleeping", philo);
    sem_post(philo->philo_info->forks);
    sem_post(philo->philo_info->forks);
}

void	philo_eating(t_philo *philo)
{
	while (!(philo->last_eat + \
		philo->philo_info->t_eat <= ft_current_time(philo)))
		usleep (180);
	philo->last_meal = ft_current_time(philo);
	philo->ate++;
	if (philo->ate == philo->philo_info->nb_t_eat)
		exit(0);
}

void	sleep_think(t_philo *philo)
{
	while (!(philo->last_eat + philo->philo_info->t_eat + \
		philo->philo_info->t_sleep <= ft_current_time(philo)))
		usleep (180);
	print_msg_mutex("is thinking", philo);
}

void	action_control(t_philo *args)
{
	pthread_t	controller;

	//pthread_create(&controller, NULL, check_mychild, arfgs);
}