/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:40:22 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/05/21 18:12:19 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	print_msg_mutex(char *msg, t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_info->finish_lock);
	if (!philo->philo_info->finished)
		printf("%lld\t%d\t%s\n",ft_current_time(philo), philo->id + 1, msg);
	pthread_mutex_unlock(&philo->philo_info->finish_lock);
}