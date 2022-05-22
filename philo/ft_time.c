/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <zyacoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:58:08 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/05/22 18:56:05 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

long long	ft_get_time(void)
{
	t_time	time;

	gettimeofday(&time, NULL);
	return(time.tv_sec * 1000 + time.tv_usec / 1000);
}

long long	ft_current_time(t_philo * philo)
{
	long long	time;

	time = ft_get_time() - philo->philo_info->created_at;
	return (time);
}
