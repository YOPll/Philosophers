/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:59:31 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/05/21 18:40:06 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	ft_forks_down(t_philo *philo, int id1, int id2)
{
	pthread_mutex_unlock(&philo->philo_info->forks[id1]);
	pthread_mutex_unlock(&philo->philo_info->forks[id2]);
}

void	grab_fork(t_philo *philo, int id)
{
	pthread_mutex_lock(&philo->philo_info->forks[id]);
	print_msg_mutex("has taken a fork", philo);
	
}
