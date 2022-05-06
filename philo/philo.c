/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <mrx.ga10@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:58:08 by zyacoubi          #+#    #+#             */
/*   Updated: 2022/05/05 14:58:11 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	main(int ac, char *av[])
{
	t_arg	args;

	if (ac != 5 && ac != 6)
		ft_puterr("Usage : ./philo number_of_philosophers time_to_die time_to_eat\
		time_to_sleep [number_of_times_each_philosopher_must_eat]");
	memset(&args, 0, sizeof(t_arg));
	

	return (0);
}